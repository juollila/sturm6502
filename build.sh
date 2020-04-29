#!/bin/sh
set -e
cc sturm6502.c -o sturm6502
./sturm6502 -d 1 -o test/smoke/sturmdos.bin test/smoke/sturmdos.asm
xxd test/smoke/sturmdos.bin > test/smoke/smoke.hex
set +e
diff test/smoke/expected.hex test/smoke/smoke.hex
exit_code=$?
if [ $exit_code != 0 ]; then
   printf "SMOKE TEST FAILED: %d\n" "$exit_code"
else
   printf "SMOKE TEST OK\n"
fi
