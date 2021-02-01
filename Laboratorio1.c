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
#include <stdio.h>
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
int ganador;
int jugador1;
int jugador2;
int conteo;
int led;


//*****************************************************************************
//Prototipos de funciones
//****************************************************************************
void setup(void);
void delay(unsigned char n);
void carrera(void);
//*****************************************************************************
//Ciclo Principal
//*****************************************************************************

void main(void) {
    setup();
    delay(500);
    while (1) {
        if (EMP == 1) {
            ROJO = 1;
            delay(6000);
            ROJO = 0;
            AMARILLO = 1;
            delay(6000);
            AMARILLO = 0;
            VERDE = 1;
            delay(6000);
            VERDE = 0;
            while (ganador != 1) {
                if (JUG1 == 1) {
                    ++jugador1;
                    conteo = jugador1;
                    led = 1;
                    carrera();
                    delay (5000);

                }
                if (JUG2 == 1) {
                    ++jugador2;
                    conteo = jugador2;
                    carrera();
                    delay(5000);
                }
                


            }

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
    ganador = 0;
    jugador1 = 0;
    jugador2 = 0;
    conteo = 0;
    led = 0;




}

void delay(unsigned char n) {
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
        }
    }
}

void carrera(void) {

    if (conteo ==1) {
        if (led == 1) {
            PORTAbits.RA0 = 1;
            led=0;
        } else {
            PORTBbits.RB0 = 1;
        }
    }
    if (conteo ==2) {
        if (led == 1) {
            PORTA = 0b00000010;
            led=0;
        } else {
            PORTB = 0b00000010;
        }
    }
    if (conteo ==3) {
        if (led == 1) {
            PORTA = 0b00000100;
            led=0;
        } else {
            PORTB = 0b00000100;
        }
    }
    if (conteo ==4) {
        if (led == 1) {
            PORTA = 0b00001000;
            led=0;
        } else {
            PORTB = 0b00001000;
        }
    }
    if (conteo ==5) {

        if (led == 1) {
            PORTA = 0b00010000;
            led=0;
        } else {
            PORTB = 0b00010000;
        }
    }
    if (conteo== 6) {

        if (led == 1) {
            PORTA = 0b00100000;
            led=0;
        } else {
            PORTB= 0b00100000;
        }
    }
    if (conteo ==7) {
        if (led == 1) {
            PORTA = 0b01000000;
            led=0;
        } else {
            PORTB = 0b01000000;
        }
    }
    if (conteo ==8) {
        if (led == 1) {
            PORTA = 0b10000000;
            led=0;
            ganador=1;
            delay(5000);
            PORTDbits.RD3=1;
            delay(8000);
            PORTDbits.RD3=0;
            PORTB= 0b00000000;
            PORTA= 0b00000000;
            
        } else {
            PORTB= 0b10000000;
            ganador=1;
            delay(5000);
            PORTDbits.RD4=1;
            delay(8000);
            PORTDbits.RD3=0;
            PORTB= 0b00000000;
            PORTA= 0b00000000;
        }
    }



}
