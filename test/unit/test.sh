#!/bin/bash
set -e
cc test_asm.c ../../sturm6502.c -D UNIT_TEST=1 -l lcut -o test_asm
./test_asm
cc test_pseudo.c ../../sturm6502.c -D UNIT_TEST=1 -l lcut -o test_pseudo
./test_pseudo
cc test_exp.c ../../sturm6502.c -D UNIT_TEST=1 -l lcut -o test_exp
./test_exp
