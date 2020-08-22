LIST p=18f4520		
#include<p18f4520.inc>		

	org 	0x00		
Initial:	
 	
	clrf	LATD		
;***************************************
NAND:
	NOP
	MOVLW 0X5D		
	ANDLW 0X78
	XORLW 0XFF
	MOVWF LATD
NOR:
	MOVLW 0x96
	IORLW  0X69
	XORLW 0XFF
	MOVWF LATC
	end