chrout = $ffd2

   .org  $c000-2
   .word start
start:
   ldx   #0
loop:
   lda   text,x
   beq   end
   jsr   chrout
   inx
   bne   loop
end
   rts

text:
   .byte "HELLO, WORLD!",0x0d, 0
