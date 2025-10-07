# Coding guidelines

- [General rules](#general-rules)
  - [Leave blank lines for readability](#leave-blank-lines-for-readability)
  - [Explicitly mark fallthroughs and empty blocks with comments](#explicitly-mark-fallthroughs-and-empty-blocks-with-comments)
  - [Don't use unnecessary unsigned integer literals](#dont-use-unnecessary-unsigned-integer-literals)
  - [Remove auto-generated comments](#remove-auto-generated-comments)
  - [Use decimal integers for shifts](#use-decimal-integers-for-shifts)
- [Functions](#functions)
  - [Initialize local variables if possible](#initialize-local-variables-if-possible)
  - [Don't use void to denote empty parameter list](#dont-use-void-to-denote-empty-parameter-list)

## General rules

### Leave blank lines for readability

Use a single blank line to separate:
- variable declarations from executable code
- conditional blocks and loops from other code
- the end of one switch from the start of another
- function definitions

You shouldn't add more than one blank line though.

#### Examples

```c
// Bad ❌
s32 a = 0;
printf("%d\n", a);

// Good ✅
s32 a = 0;

printf("%d\n", a);
```

```c
// Bad ❌
a = 3;
if (a == 4) {
    a += 1;
}
a -= 5;

// Good ✅
a = 3;

if (a == 4) {
    a += 1;
}

a -= 5;
```

```c
// Bad ❌
switch (a) {
case 1:
    a += 1;
    break;
case 2:
    a -= 1;
    break;
}

// Good ✅
switch (a) {
case 1:
    a += 1;
    break;

case 2:
    a -= 1;
    break;
}
```

```c
// Bad ❌
void func_a() {
    ...
}
void func_b() {
    ...
}

// Good ✅
void func_a() {
    ...
}

void func_b() {
    ...
}
```

### Explicitly mark fallthroughs and empty blocks with comments

Unmarked fallthroughs look like a programmer oversight. Explicitly mark them with `/* fallthrough */` to state that falling through is intentional. An exception to this rule is a series of empty cases.

Empty blocks follow the same logic. To state that the emptiness is intentional write `// Do nothing`.

#### Examples

```c
// Bad ❌
switch (a) {
case 1:
    a += 1;

case 2:
    a -= 1;
    break;
}

// Good ✅
switch (a) {
case 1:
    a += 1;
    /* fallthrough */

case 2:
    a -= 1;
    break;
}
```

```c
// Bad ❌
void my_func() {}

// Good ✅
void my_func() {
    // Do nothing
}
```

### Don't use unnecessary unsigned integer literals

Most of the time unsigned integer literals (e.g. '0x10U') are unnecessary and ordinary ones can be used instead.

#### Examples

```c
// Bad ❌
u32 a = 16U;

// Good ✅
u32 a = 16;
```

### Remove auto-generated comments

Auto-generated comments do not belong in code. For example, m2c sometimes adds comments to switch statements and cases.

#### Examples

```c
// Bad ❌
switch (bits->bitdepth) { /* irregular */
    ...

// Good ✅
switch (bits->bitdepth) {
    ...
```

### Use decimal integers for shifts

#### Examples

```c
// Bad ❌
s8 a = (color >> 0x18) & 0xFF;

// Good ✅
s8 a = (color >> 24) & 0xFF;
```

## Functions

### Initialize local variables if possible

Local variables should be initialized in-place whenever possible.

#### Examples

```c
// Bad ❌
s32 a;
s32 b;

a = 10;
b = 5;

// Good ✅
s32 a = 10;
s32 b = 5;
```

### Don't use void to denote empty parameter list

#### Examples

```c
// Bad ❌
s32 get_offset(void);

// Good ✅
s32 get_offset();
```
