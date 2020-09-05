# Microchip-pic18f4520 exercises
A serial exercises on a microcontroller, which is Microchip-PIC18F4520. The programs were developed using [Microchip MPLAB<sup>&reg;</sup>X Integrated Development Environment (IDE)](https://www.microchip.com/mplab/mplab-x-ide).
## Exercise introduction
### Lab1
A simple addition exercise.
### Lab2
An exercise on addressing mode.
- Literal addressing mode
- Direct addressing mode
- Indirect addressing mode
- Relative addressing mode
### Lab3 
Logical and control operations.
#### Lab3-1
Implement two logic operations: 
- NAND
- NOR  

P.S. The implementation are limited to AND, OR and XOR operations. 
#### Lab3-2
Add from 1,2, ... to overflow and check the relative register status.  
Practice rotating with carry using RLCF and RRCF instructions.
### Lab4
Macro and subroutine.
#### Lab4-1
Compute Fibonacci sequence for N = 9
#### Lab4-2
Implement a stack to simulate function call procedure.
### Lab5
Mixing C with assembly language.  
Write a multiplication library in assembly language, and call it in C main function.
### Lab6
Let a LED blink, and each time interval is exactly 1 second.  
P.S. Count the cpu cycle.
### Lab7
The application of interrupt.   
Light up LEDs(RD0~RD3) for 0.5 second in order after pushing an external button.
### Lab8
Use timer and interrupt to control LEDs.  
Continually light up LEDs(RD0~RD3) for 2 second in order.
### Lab9
Use PWM to control servo motor.
### Lab10
Use CCP2 to trigger ADC(Analog-to-Digital Converter).
Control variable resistor and store each result of ADC sample.
### Lab11
An implementation of UART.  
Mode 1 : Just print "Hello world!"  
Mode 2 : Print the voltage on real time by adjusting variable resistor controller.