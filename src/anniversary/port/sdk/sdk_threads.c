#include "common.h"
#include "libco.h"

#include <eekernel.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Emulate PS2's cooperative multithreading model using libco

#define THREAD_MAX_PRIORITY 127
#define READY_QUEUE_SIZE THREAD_MAX_PRIORITY + 1
#define MAX_THREADS 256 - 3

typedef struct Thread {
    cothread_t cothread;
    int id;
    int state;
    int init_priority;
    int current_priority;
    int wakeup_request_count;
    struct Thread *prev;
    struct Thread *next;
} Thread;

static Thread threads[MAX_THREADS];
static Thread *current_thread = NULL;
static Thread *ready_queue[READY_QUEUE_SIZE];
static int thread_count = 0;

static void initialize_if_needed() {
    if (thread_count > 0) {
        return;
    }

    Thread *main_thread = &threads[0];
    main_thread->cothread = co_active();
    main_thread->id = 1;
    main_thread->state = THS_RUN;
    main_thread->init_priority = 1;
    main_thread->current_priority = 1;
    main_thread->wakeup_request_count = 0;
    main_thread->prev = NULL;
    main_thread->next = NULL;

    current_thread = main_thread;
    ready_queue[1] = main_thread;
    thread_count = 1;
}

static Thread *find_tail(Thread *node) {
    if (node == NULL) {
        return NULL;
    }

    Thread *tail = node;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    return tail;
}

static void append_to_ready_queue(Thread *thread, int priority) {
    if (thread == NULL) {
        return;
    }

    Thread *tail = find_tail(ready_queue[priority]);

    if (tail == NULL) {
        // Queue is empty. Let's put the thread at the head
        ready_queue[priority] = thread;
    } else {
        // Queue has some threads. Let's append the thread
        tail->next = thread;
        thread->prev = tail;
    }
}

static void remove_from_ready_queue(Thread *thread) {
    if (thread == NULL) {
        return;
    }

    Thread *head = ready_queue[thread->current_priority];
    Thread *node = head;

    while (node != NULL) {
        // If it's not the node we're looking for, go to the next one
        if (node->id != thread->id) {
            node = node->next;
            continue;
        }

        // Found the node. Let's remove it
        Thread *prev = node->prev;
        Thread *next = node->next;

        if (prev != NULL) {
            prev->next = next;
        }

        if (next != NULL) {
            next->prev = prev;
        }

        // If we remove the head we must adjust the ready queue too
        if (node->id == head->id) {
            ready_queue[thread->current_priority] = next;
        }

        return;
    }

    // Getting to this point means the thread's priority doesn't match
    // its position in ready queue, which is an implementation error
    fatal_error("Implementation error");
}

void switch_to_next_thread() {
    for (int i = 1; i < READY_QUEUE_SIZE; i++) {
        Thread *thread = ready_queue[i];

        if (thread == NULL) {
            continue;
        }

        remove_from_ready_queue(thread);
        thread->state = THS_RUN;
        co_switch(thread->cothread);
        current_thread = thread;
        return;
    }

    fatal_error("No threads to switch to");
}

int GetThreadId(void) {
    initialize_if_needed();

    return current_thread->id;
}

int CreateThread(struct ThreadParam *param) {
    initialize_if_needed();

    if (thread_count == MAX_THREADS) {
        printf("Can't create more than %d threads\n", MAX_THREADS);
        return -1;
    }

    if (param->initPriority < 1 || param->initPriority > THREAD_MAX_PRIORITY) {
        printf("Invalid priority: %d\n", param->initPriority);
        return -1;
    }

    Thread *new_thread = &threads[thread_count];
    new_thread->cothread = co_derive(param->stack, param->stackSize, param->entry);
    new_thread->id = thread_count + 1;
    new_thread->state = THS_DORMANT;
    new_thread->init_priority = param->initPriority;
    new_thread->wakeup_request_count = 0;
    new_thread->prev = NULL;
    new_thread->next = NULL;

    thread_count += 1;

    return new_thread->id;
}

int StartThread(int tid, void *arg) {
    initialize_if_needed();

    if (tid > thread_count) {
        printf("Can't start a non-existent thread %d\n", tid);
        return -1;
    }

    Thread *thread = &threads[tid - 1];

    if (thread->state != THS_DORMANT) {
        printf("Can't start a thread that is not in DORMANT state\n");
        return -1;
    }

    thread->state = THS_READY;
    append_to_ready_queue(thread, thread->current_priority);

    return thread->id;
}

int SleepThread(void) {
    initialize_if_needed();

    if (current_thread->wakeup_request_count > 0) {
        current_thread->wakeup_request_count -= 1;
        return current_thread->id;
    }

    current_thread->state = THS_WAIT;
    switch_to_next_thread();

    return current_thread->id;
}

int WakeupThread(int tid) {
    initialize_if_needed();

    if (tid > thread_count) {
        printf("Can't wakeup a non-existent thread %d\n", tid);
        return -1;
    }

    Thread *thread = &threads[tid - 1];

    switch (thread->state) {
    case THS_WAIT:
        thread->state = THS_READY;
        append_to_ready_queue(thread, thread->current_priority);
        break;

    case THS_WAITSUSPEND:
        thread->state = THS_SUSPEND;
        break;

    case THS_READY:
    case THS_RUN:
    case THS_SUSPEND:
    case THS_DORMANT:
        thread->wakeup_request_count += 1;
        break;
    }

    return tid;
}

int iWakeupThread(int tid) {
    return WakeupThread(tid);
}

int SuspendThread(int tid) {
    initialize_if_needed();

    if (tid > thread_count) {
        printf("Can't suspend a non-existent thread %d\n", tid);
        return -1;
    }

    if (tid == current_thread->id) {
        printf("Can't suspend current thread\n");
        return -1;
    }

    Thread *thread = &threads[tid - 1];

    switch (thread->state) {
    case THS_WAIT:
        thread->state = THS_WAITSUSPEND;
        break;

    case THS_WAITSUSPEND:
    case THS_SUSPEND:
        // The thread is already suspended
        break;

    case THS_DORMANT:
        // Suspending a dormant thread doesn't make much sense
        break;

    case THS_READY:
        remove_from_ready_queue(thread);
        thread->state = THS_SUSPEND;
        break;

    case THS_RUN:
        // If we're here something has gone wrong
        fatal_error("Implementation error");
        break;
    }

    return tid;
}

int ResumeThread(int tid) {
    initialize_if_needed();

    if (tid > thread_count) {
        printf("Can't resume a non-existent thread %d\n", tid);
        return -1;
    }

    if (tid == current_thread->id) {
        printf("Can't resume current thread\n");
        return -1;
    }

    Thread *thread = &threads[tid - 1];

    switch (thread->state) {
    case THS_SUSPEND:
        thread->state = THS_READY;
        append_to_ready_queue(thread, thread->current_priority);
        break;

    case THS_WAITSUSPEND:
        thread->state = THS_WAIT;
        break;

    case THS_DORMANT:
    case THS_READY:
    case THS_WAIT:
        // Resuming a thread which is dormant, ready or waiting doesn't make much sense
        break;

    case THS_RUN:
        // If we're here something has gone wrong
        fatal_error("Implementation error");
        break;
    }

    return tid;
}

void ExitDeleteThread(void) {
    initialize_if_needed();

    if (current_thread->id == 1) {
        fatal_error("Can't exit main thread");
    }

    thread_count -= 1;
    co_delete(current_thread->cothread);
    memset(current_thread, 0, sizeof(Thread));
    switch_to_next_thread();
}

int ChangeThreadPriority(int tid, int prio) {
    initialize_if_needed();

    if (tid > thread_count) {
        printf("Can't change priority of a non-existent thread %d\n", tid);
        return -1;
    }

    if ((prio < 1) || (prio > THREAD_MAX_PRIORITY)) {
        printf("Invalid priority: %d\n", prio);
        return -1;
    }

    Thread *thread = &threads[tid - 1];
    int old_priority = thread->current_priority;

    if (thread->current_priority == prio) {
        return prio;
    }

    if (thread->state == THS_READY) {
        remove_from_ready_queue(thread);
        append_to_ready_queue(thread, prio);
    }

    thread->current_priority = prio;
    return old_priority;
}

int ReferThreadStatus(int tid, struct ThreadParam *info) {
    initialize_if_needed();

    if (tid > thread_count) {
        printf("Can't get status of a non-existent thread %d\n", tid);
        return -1;
    }

    if (info == NULL) {
        return tid;
    }

    Thread *thread = &threads[tid - 1];
    info->status = thread->state;
    info->currentPriority = thread->current_priority;

    return tid;
}

int iReferThreadStatus(int tid, struct ThreadParam *info) {
    return ReferThreadStatus(tid, info);
}

int DelayThread(u_int) {
    not_implemented(__func__);
}
