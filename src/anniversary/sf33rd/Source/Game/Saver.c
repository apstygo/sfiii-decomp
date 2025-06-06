#include "sf33rd/Source/Game/Saver.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/workuser.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Saver", Saver_Task);
#else
void Saver_Task(struct _TASK *task_ptr) {
    not_implemented(__func__);
}
#endif

void Saver_Init(struct _TASK* task_ptr) {
    task_ptr->r_no[0] = 1;
    task_ptr->r_no[1] = 0;
    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    task_ptr->timer = 0;
}

void Saver_Check(struct _TASK *task_ptr) {
    if (Demo_Flag == 0) {
        task_ptr->timer = 0;
        return;
    }

    if ((PLsw[0][0] != 0) || (PLsw[1][0] != 0)) {
        task_ptr->timer = 0;
        return;
    }

    if ((task_ptr->timer += 1) > 18000) {
        task_ptr->r_no[0]++;
    }
}

void Saver_Move(struct _TASK* task_ptr) {
    if ((PLsw[0][0] != 0) || PLsw[1][0] != 0) {
        Saver_Init(task_ptr);

    } else {
        switch (task_ptr->r_no[1]) {
        case 0:
            task_ptr->r_no[1] += 1;
            task_ptr->free[0] = 0;
            FadeInit();
            /* fallthrough */

        case 1:
            FadeOut(1, 4, 0);

            if ((task_ptr->free[0]++) > 0x30) {
                task_ptr->r_no[1] += 1;
            }
            break;

        case 2:
            ToneDown(0xC8, 0);
            break;
        }
    }
}

void Saver_Exit(struct _TASK* task_ptr) {
    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1] += 1;
        FadeInit();
        /* fallthrough */

    case 1:
        if (FadeIn(1, 0xFF, 8) != 0) {
            Saver_Init(task_ptr);
        }
    }
}
