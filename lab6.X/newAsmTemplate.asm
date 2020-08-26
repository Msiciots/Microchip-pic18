    LIST p=18f4520		
#include<p18f4520.inc>		
    CONFIG  OSC = INTIO67       ; Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
    CONFIG  WDT = OFF           ; Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
    CONFIG  LVP = OFF
    ;CONFIG  PBADEN = OFF	; Set RB<4:0> as digital I/O pins
 
    L1	    EQU 0X14
    L2	    EQU 0X15
    ORG	    0x0
    
  ;  CLRF	    LATA ; Alternate method to clear output data latches
    CLRF TRISA
    BSF		    TRISA,4
    MOVLW	    0x0f
    MOVWF	    ADCON1;set digital I/O		
    CLRF	    TRISD; Set PORTD for LED output
    CLRF	    LATD
    
DELAY MACRO num1,num2
    local LOOP1	;prevent compile error
    local LOOP2               
    MOVLW num2
    MOVWF L2
    LOOP2:
	MOVLW num1                   
	MOVWF L1  
    LOOP1:
	NOP
	NOP
	NOP
	NOP
	DECFSZ L1,1
	    GOTO LOOP1
	DECFSZ L2,1
	    GOTO LOOP2
    ENDM

    MOVLW 0X11
    MOVWF LATD
    BSF PORTA,4
  ;  CLRF PORTA
    NOP
 
LOOPL:    
   RLNCF LATD,1
   DELAY 0X64,0X64
   
    BTFSC PORTA,4 
    GOTO LOOPL
  DELAY 0X64,0X64
    LOOPR:
    RRNCF LATD,1
   DELAY 0X64,0X64
   BTFSC PORTA,4 
    GOTO LOOPR
    GOTO LOOPL
END