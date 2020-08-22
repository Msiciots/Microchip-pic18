LIST p=18f4520
#include<p18f4520.inc>
    CONFIG OSC=INTIO67
    CONFIG WDT = OFF
    
    org	0x00

    clrf WREG
    LFSR 0,0x120
loop1:
    
    incf WREG
    MOVWF POSTINC0
    btfss WREG,3
    goto loop1
    LFSR 0,0x120
loop2:
    MOVWF POSTINC0
    DECFSZ WREG,0
    goto loop2

end