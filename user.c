/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <xc.h>          /* Defines special function registers, CP0 regs  */

#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
//#include <sys/attribs.h>

void InitTimer2AndOC8(void) {
    T2CON = 0; // clear timer settings to defaults
    T2CONbits.TCKPS = 7; // divide clock by 256 with prescaler
    TMR2 = 0;
    // Set period for timer
    PR2 = PWM_PERIOD_COUNTS-1;    
    // Set initial duty cycle to 50%
    OC8R = PWM_PERIOD_COUNTS/2;
    // Set reload duty cycle to 50%
    OC8RS = PWM_PERIOD_COUNTS/2;
    // Configure OC5 control register
    OC8CONbits.ON = 1;
    OC8CONbits.OC32 = 0;    // 16 bit mode
    OC8CONbits.OCTSEL = 0; // Select timer 2
    OC8CONbits.OCM = 6; // Select PWM mode without fault pin
    // Map OC8 signal to pin D4 (LED LD2)
    RPD4R = 12; // Select OC8
    // Start Timer 2
    T2CONbits.ON = 1;
}

void InitGPIO(void) {
    /* Setup functionality and port direction */
    // LED output
    // Disable analog mode
    ANSELGbits.ANSG6 = 0;

    // Set directions to output
    TRISGbits.TRISG6 = 0;

    // Turn off LEDs for initialization
    LD1_PORT_BIT = 0;

}