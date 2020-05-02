#!/bin/bash
set -e
cc test_asm.c ../../sturm6502.c -DUNIT_TEST=1 -llcut -o test_asm
./test_asm
cc test_pseudo.c ../../sturm6502.c -DUNIT_TEST=1 -llcut -o test_pseudo
./test_pseudo
