/*
 * File:   main.c
 * Author: Diego Gerardo Mencos Caal
 * Carne: 18300
 * Curso: Digital 2
 *
 * Created on 25 de enero de 2021, 12:01 PM
 */

//******************************************************************************
//Librerías
//******************************************************************************
#include <xc.h>


// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)




//******************************************************************************
//Variables
//*****************************************************************************
#define ROJO PORTDbits.RD0
#define AMARILLO PORTDbits.RD1
#define VERDE PORTDbits.RD2
#define EMP PORTCbits.RC0
#define JUG1 PORTCbits.RC1
#define JUG2 PORTCbits.RC2



//*****************************************************************************
//Prototipos de funciones
//****************************************************************************
void setup(void);
void delay(unsigned char n);
//*****************************************************************************
//Ciclo Principal
//*****************************************************************************

void main(void) {
    setup();
    delay (500);
    while (1) {
        if (EMP == 1) {
            ROJO = 1;
            delay (6000);
            ROJO=0;
            AMARILLO=1;
            delay (6000);
            AMARILLO=0;
            VERDE=1;
            delay(6000);
            VERDE=0;
                        
        } else {
            PORTDbits.RD0 = 0;
        }

    }


    return;
}

//*****************************************************************************
//Configuración
//****************************************************************************

void setup(void) {
    ANSEL = 0;
    ANSELH = 0;
    TRISB = 0;
    TRISA = 0;
    TRISC = 1;

    TRISD = 0;
    PORTA = 0;
    PORTB = 0;
    PORTD = 0;
    PORTD = 0;





}

void delay(unsigned char n) {
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
        }
    }
}
