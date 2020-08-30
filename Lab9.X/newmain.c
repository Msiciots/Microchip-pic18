#define TMR2PRESCALE 16
#define _XTAL_FREQ 800000
#include <xc.h>
// BEGIN CONFIG
#pragma config OSC = INTIO67   // Oscillator Selection bits (HS oscillator)
#pragma config WDT = OFF  // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON  // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF   // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)

//END CONFIG

PWM1_Init(long setDuty)
{
  PR2 = setDuty;
}

PWM1_Duty(unsigned int duty)
{
//set duty to CCPR1L , CCP1X(CCP1CON:5) and CCP1Y(CCP1CON:4)
    CCPR1L=duty/4;
    CCP1X=(duty/2)%2;
    CCP1Y=duty%2;
}

PWM1_Start()
{
  //set CCP1CON
  CCP1M3=1;
  CCP1M2=1;
  CCP1M1=0;
  CCP1M0=0;
  //set timer2 on
  T2CONbits.TMR2ON=1;
  //set rc2 output
  TRISC=0x00;
  if (TMR2PRESCALE == 1)
  {
	
  }
  else if(TMR2PRESCALE == 4)
  {  
 
  }
  else if (TMR2PRESCALE == 16)
  {
      T2CONbits.T2CKPS1=1;
  }
 
}

void main()
{
  int i=15;
  //set trisD
  TRISD=0XFF;
  
 // PORTD=0XFF;
  
  OSCCONbits.IRCF2=0;       //set pwm period
  OSCCONbits.IRCF1=1;
  OSCCONbits.IRCF0=1;                 
  PWM1_Init(155); 
  
  do
  {     
    if(RD0 == 0 && i<75)
      i=i+1;
    PWM1_Duty(i);
    PWM1_Start();
   __delay_ms(50);
  }while(1);
}