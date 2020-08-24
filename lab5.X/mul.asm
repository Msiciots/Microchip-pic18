#include <xc.inc>
 GLOBAL _mul
 
 PSECT mytext,local,class=CODE,reloc=2
 
 tempvar1	equ	0x001
 tempvar2	equ	0x003

_mul:
    clrf WREG
    movff tempvar1,LATB
    movff tempvar2,LATC
    CLRF LATD
    CLRF TRISA
    MOVLW 0X08
    MOVWF LATA
    clrf WREG
LOOP:
    BTFSC LATC,0
    goto add
    BCF STATUS,0
continue:
    RRCF LATD,f
    RRNCF TRISA,f
    BTFSC STATUS,0
   BSF TRISA,7
    RRNCF LATC,f
    BCF LATC,7
    DECFSZ LATA
    goto LOOP
    movff LATD,0x002
    movff TRISA,0x001
    
    return
add:
    movff LATB,WREG
    addwf LATD
    goto continue