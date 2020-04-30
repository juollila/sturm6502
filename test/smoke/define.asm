.include	"test/smoke/kernal.asm"

basic	=	$2b
variables =	$2d
chrget	=	$73
textptr	=	$7a
endofload =	$ae
devnbr	=	$ba
ndx	=	$c6	; number of chars in keyboard buffer
buffer	=	$200
keybuffer =	$277
warm	=	$302
igone	=	$308
goneptr	=	$3fc
saveptr	=	$3fe
tape	=	$33c	; tape buffer
device	=	tape
secondary =	tape+1
run	=	tape+2
length	=	tape+3
bin	=	tape+4
bcd	=	tape+6
param	=	tape+9


