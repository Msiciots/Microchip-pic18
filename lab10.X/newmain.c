#include <xc.h>
#pragma config OSC  = INTIO67,WDT=OFF,LVP=OFF
#pragma PBADEN = 1 //set AN0~AN12 as analog input

void adc_init(void);
void ccp2_init(void);
void tmr_init(void);
unsigned int adcValue;
void __interrupt(high_priority) Hi_ISR(void)
{
    //deal ccp2 interrupt and adc interrupt
    if(PIR1bits.ADIF){//AD conversion finish
          adcValue=(ADRESH*256) | (ADRESL);
          ADIF=0;
    }
    else if(PIR2bits.CCP2IF){ //special event triger
        ADCON0bits.GO = 1;
       
    }
    return ;
}

void main(void) {
    //change OSC if you want
    //    OSCCONbits.IRCF = ??;
    adc_init();
    ccp2_init();
    tmr_init();
    while(1);
    return;
}

void adc_init(void){
    //datasheet p232 TABLE 19-2
    //Configure the A/D module
    ADCON1bits.PCFG  = 11 ;  //Setting A/D Port Configuration Control
    //ADCON0
    //select analog channel
    ADCON0bits.CHS = 0 ;    //setting input channel
    //set TRIS
    TRISA = 0xFF ;             //setting port as input 
    //Turn on A/D module
    //ADCON1 //set refer voltage
    ADCON1bits.VCFG1 = 0 ;  //setting vref-
    ADCON1bits.VCFG0 = 0 ;  //setting vref+
    
    //ADCON2
    
    //A/D Conversion Clock
    //Acquisition Time
    //setting acquisition time (ADCON2) ACQT 2:0
    //setting conversion time (ADCON2))
    ADCON2bits.ACQT = 5; //8
    ADCON2bits.ADCS =4;//  RC
    ADCON0bits.ADON = 1;    //turn on ad module 
    //left or right justified
    ADCON2bits.ADFM = 1 ;    //setting left justified
    //Configure A/D interrupt(optional)
    //enable Interrupt Priority mode
    ADIF=0;
    ADIE=1;
    GIE=1;
    
    ADRESH=0;  			// Flush ADC output Register
    ADRESL=0; 
    
    return ;
}

void ccp2_init(void){
    //Configure CCP2 mode,ref datasheet p139
    TRISCbits.TRISC2=0;	// RC2 pin is output.
    CCP1CON=9;		// Compare mode, initialize CCP1 pin high, clear output on compare match
    PIR1bits.CCP1IF=0;
    IPR1bits.CCP1IP = 1;
    
    /*
    CCP2M3=1;
    CCP2M2=0;
    CCP2M1=1;
    CCP2M0=1;
    //configure CCP2 interrupt
    CCP2IE=1;
    CCP2IF=0;
    //configure CCP2 comparator value
    CCPR2L=18;
    CCPR2H=122;*/
}

void tmr_init(void){
    //set up timer3, ref datasheet p135
    T3CCP2=0;
    T3CCP1=1;
    
    T3CKPS1=1;
    T3CKPS0=0;    //  1/4
    //no need to turn up timer3 interrupt
}