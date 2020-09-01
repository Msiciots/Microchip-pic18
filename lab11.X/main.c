#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include <math.h> 

extern char mystring[];
extern int lenStr;

int digital=0;

void Mode1() // print "Hello world"
{
    // TODO 
    // Output the result on Command-line Interface.
    UART_Write_Text("Hello world\n");
    ClearBuffer();
}

void Mode2() { // Output Voltage 
    ClearBuffer();
    //int digital = 0;
    float voltage = 0.0;
   // while(???????????????????) // TODO design a condition. Return to main function when the while loop is over.
    {
        digital=ADC_Read(0);
        
        if(digital!=0){
        voltage = digital* ((float)5/1023); // 5v / 2^10-1  (10bits)
        // TODO
        // Output the voltage on CLI.
        
        char res[20];
        sprintf(res,"%f",voltage);
         UART_Write_Text(res);
        }
        // The voltage must have the second digit after the decimal point.
        
      //  for(int i = 0 ; i < 10000 ; i++) ; // a delay time
    }
    
    ClearBuffer();
}

void main(void) 
{
    
    SYSTEM_Initialize() ;
    
    while(1) {
        // TODO 
        // "clear" > clear UART Buffer()
        ClearBuffer();
        char *input=GetString();
        
        if(mystring[lenStr]=='1'){
             Mode1();
        }
        else if(mystring[lenStr]=='2'){
            Mode2();
        }
        // "mode1" > start Mode1 function as above
        // "mode2" > start Mode2 function as above
    }
    return;
    
}

// old version: 
// void interrupt high_priority Hi_ISR(void)
void __interrupt(high_priority) Hi_ISR(void)
{
    if(PIR1bits.CCP1IF == 1) {
        RC2 ^= 1;
        PIR1bits.CCP1IF = 0;
        TMR3 = 0;
    }
    return ;
}