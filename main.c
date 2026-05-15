/*
 * File:   main.c
 * Author: Educore
 *
 * Created on 2025. december 25., 9:56
 */


// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "PWM.h"

#define _XTAL_FREQ 4000000UL
void main(void) {
    int i;
    
    //PORT B beallitasa
    //Elsokent ertekadas:
    
    PORTB=0b00000000;
    //Minden láb Output
    //TRISB=0b00000000;
    //Vagy egyenként:
    TRISBbits.TRISB4=0;
    PORTBbits.RB4=0;
    
    for (i=0;i<10;i++)
    {
        PORTBbits.RB4=1;
        __delay_ms(500);
        PORTBbits.RB4=0;
        __delay_ms(500);
    }
    
    
    //PWM inicializálása:
     PWM_init();
    //PWM indítása:    
     PWM_Start();
    while (1) {
        PORTBbits.RB4=1;
        __delay_ms(1000);
        PORTBbits.RB4=0;
        __delay_ms(1000);
    }
     
}
