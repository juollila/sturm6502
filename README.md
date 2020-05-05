INTRODUCTION
============

Sturm6502 is a minimal cross macro assembler for the MOS Tehcnology 6502 and
compatible processors. The original design goal was to support Commodore and
Atari 8-bit computers as a host computer i.e. a native compiler, but the
support has not yet been implemented. Sturm6502 does not support 65C02 or
65C816 extensions. 

COMMAND LINE PARAMETERS
=======================

```
Usage:          sturm6502 [options] sourcefile

-d #            debug level (1..3)
-D label=value  define a numeric constant
-l name         generate a list file
-o name         an object file's name
-s              print symbols
```
LINE FORMAT
===========

the basic format of the source file's line is the following:
```<label> <command> <operand> <command>```

Examples:
```
label0:
; comment
label1:  lda #$00    ; comment
label2:  nop         ; comment
         clc
```
LABELS
======

Label definitions are case insensitive and they must start at the beginning
of the line. The label may end with a column ':' character, but is not
required.

A global label starts with a letter (a-z). The following characters shall be
alphanumberic.

Examples:
```
Label1:
START
```
A local label starts with a '@' character. The following characters shall be
alphanumeric. A local label is valid only between two global labels. It can
not be used out of the local context.

Examples:
```
@LOCAL1:
@skip
```

COMMENTS
========

A comment starts with a ';' character. A comment can be in the beginning of
a line, after the label, or after the command and its parameter.

Example:
```
; This is a comment
```

PSEUDO COMMANDS
===============

.ORG expression

Defines the starting address of compiled object code. This command should be
used before any assembly code.

Example:
```
.org $C000
```

.BYTE expression, ...

This command can be used to define static bytes or reserve space.

Example:
```
.byte "Sturmmann was here.", $0D
```

.IF expression

If the expression is not equal to zero then the following code is compiled.
The nested if statements are not supported.

Example:
```
.if 1
```

.ELSE

If the .IF statement's expression was equal to zero then the code after the
.ELSE is compiled.

.ENDIF

Terminates the previous .IF.

.IFDEF identifier

If the identifier has been defined then the following code is compiled. The
nested ifdef statements are not supported.

Example:
```
.ifdef foo
```

.IFNDEF identifier

If the identifier has not been defined then the following code is compiled.
The nested ifndef statements are not supported.

.INCLUDE "file"

The included "file" is compiled. The nested includes are supported.

.INCBIN "file"

The included "file" is copied directly (as a binary) to the object file. 

.MAC name

Start a definition of the macro. In the macro definition, \1, \2, \3 ... \9
are input arguments when macro is called.

Example:
```
.mac lbeq
   .byte	$d0,$3   ; bne +3
   jmp   \1	
.endmac
```

.ENDMAC

Terminates a macro definition.
 
EXPRESSIONS
===========

The expression evaluation supports global labels, local labes, global defines,
numbers (decimal, hexadecimal and binary), characters. Parenthesis are also
supported, but indexed addressing modes use also parenthesis. Thus it is not
recommend to use parenthesis in expressions in the assembly command's operand.

The following operators are supported (listed in precedense order):
- multiplication *, division /
- addition +, subtraction -
- low byte <, high byte >

The comparison, logical or bitwise operators are not supported.

The logical "and" operator can be emulated using multiplication and the
logical "or" operator can be emulated using addition.

Example:
```
foobar = (foo + bar) * sturm  ; (foo || bar) && sturm
```

