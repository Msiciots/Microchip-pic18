LIST p=18f4520		
#include<p18f4520.inc>
    org 0x00
    goto initail
    mclear:
    movff 0x140,POSTINC0
    movff 0x116,POSTINC0
    movff 0x154,POSTINC0
    movlw 0x01
    MULWF 0x140
    MOVFF PRODL,WREG
    MULWF 0x116
    MOVFF PRODL,WREG
    MULWF 0x154
    clrf 0x140
    clrf 0x116
    clrf 0x154
    clrf POSTDEC0
    movff POSTDEC0,0x154
    movff POSTDEC0,0x116
    movff POSTDEC0,0x140
    return
    initail:
    movlb 1
    MOVLW 0X08
    MOVWF 0X40,1
    MOVLW 0X07
    MOVWF 0X16,1
    MOVLW 0X6
    MOVWF 0X54,1
    LFSR 0,0X100
    RCALL mclear  
    end
    end