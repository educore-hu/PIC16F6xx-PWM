/*
 * File:   PWM.c
 * Author: Educore
 *
 * Created on 2025. december 26., 12:40
 */

//Projekt mellé kell tenni
#include "pic16f690.h"
void PWM_init(void) {

//	https://www.micro-examples.com/public/microex-navig/doc/097-pwm-calculator.html
//Frequency,  Resolution (Bits), TIMER2 Prescaler,     PR2,	       T2CON,	  CCPR1L,	CCP1CON,
// 5000.00	       10	              ÷4	       0b11111001	0b00000101	0b01111100	0b00111100
    
    
// 1. Disable the PWM pin (CCP1) output driver by setting the associated TRIS bit
    // Enable PWM pin output driver by clearing the associated TRIS bit
    TRISCbits.TRISC2 = 1; // Set CCP1 pin (RC2) as output
    TRISCbits.TRISC3 = 1; // Set CCP1 pin (RC3) as output
    TRISCbits.TRISC4 = 1; // Set CCP1 pin (RC4) as output
    TRISCbits.TRISC5 = 1; // Set CCP1 pin (RC5) as output
    // 2. Set the PWM period by loading the PR2 register
    PR2 = 249; // Set period for 1000 Hz PWM
    
    //CCP1CON beállításai:
    //Single PWM az 0 0
    //Full Bridge mód:0 1
    //Half Bridge mód:1 0
    CCP1CONbits.P1M1=1;
    CCP1CONbits.P1M0=0;
    
    //Van Compar mód stb, de itt most a LSB bitek tárolva vannak, mert 10 bites lehet. A maradék bitek jönnek ide
    //Ha csak 8 bitest akarunk, akkor ezek lehetnek 1-ek, majd a CCPRL'-ben a maradék 8 bittel lehet a felbontást
    //változtatni
    CCP1CONbits.DC1B0=1;
    CCP1CONbits.DC1B1=1;
    
    
    // 3. Configure CCP1 module for PWM operation
    //Itt lehet beállítani egy csomó PWM módot. 4 láb hogy viselkedjen a motorvezérléshez stb
    //Itt ezzel a 4 bittel kikapcsolja!!!
    CCP1CONbits.CCP1M = 0b0000; // Disable PWM mode for now

    // 4. Set the PWM duty cycle
    CCPR1L = 0x7C; // Set duty cycle high byte (50%)



    // 6. Ensure Timer2 is off for now
    T2CONbits.TMR2ON = 0; // Turn off Timer2
    // Clear TMR2 overflow flag
    PIR1bits.TMR2IF = 0;
    // 5. Set the TMR2 prescale value
    T2CONbits.T2CKPS = 0b01; // Set Timer2 prescale to 4
}
void PWM_Start(void) {
// Clear TMR2 overflow flag
    PIR1bits.TMR2IF = 0;

    // Enable Timer2
    T2CONbits.TMR2ON = 1;

    // Wait until Timer2 overflows
    while (!PIR1bits.TMR2IF);
    PIR1bits.TMR2IF = 0; // Clear TMR2 overflow flag

    // Enable PWM mode
    //Itt lehet beállítani egy csomó PWM módot. 4 láb hogy viselkedjen a motorvezérléshez stb
    //Itt ezzel a 4 bittel, mivel nem 0-k ezért bekapcsolja, mégpedig P1A,P1C activ High, és P1B,P1D active Low-vra!!!
    CCP1CONbits.CCP1M = 0b1100; // Set CCP1 to PWM mode

    // Enable PWM pin output driver by clearing the associated TRIS bit
    TRISCbits.TRISC2 = 0; // Set CCP1 pin (RC2) as output
    TRISCbits.TRISC3 = 0; // Set CCP1 pin (RC3) as output
    TRISCbits.TRISC4 = 0; // Set CCP1 pin (RC4) as output
    TRISCbits.TRISC5 = 0; // Set CCP1 pin (RC5) as output
}
void PWM_Stop(void) {
// Disable PWM mode
    CCP1CONbits.CCP1M = 0b0000; // Disable PWM mode

    // Turn off Timer2
    T2CONbits.TMR2ON = 0;

    // Disable PWM pin output driver by setting the associated TRIS bit
    TRISCbits.TRISC2 = 1; // Set CCP1 pin (RC2) as input
}


