LIST p=18f4520		
#include<p18f4520.inc>		

	org 	0x00		
MOVLF	MACRO N, DATUM        ; 將立即數放置FILE REGISTER
	MOVLW N
	MOVWF DATUM
	CLRF WREG
	ENDM
goto intial
fib:
    clrf WREG
    addwf 0x012,0
    addwf 0x013,0
    movwf 0x014
    MOVFF 0x013,0x012
    MOVFF 0x014,0x013
    DECFSZ 0x015
    BNZ 3
    return
intial:
MOVLF 0x00,0x12
MOVLF 0x01,0x13
clrf WREG
MOVLF 8,0x015
RCALL fib
	end