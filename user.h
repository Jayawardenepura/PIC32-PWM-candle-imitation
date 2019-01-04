#define LD1_PORT_BIT        LATGbits.LATG6

#define BTN1_PORT_BIT       PORTAbits.RA5
#define BTN2_PORT_BIT       PORTAbits.RA4

/* TODO Application specific user parameters used in user.c may go here */
#define PWM_FREQ_HZ (1000)
#define PWM_PERIOD_COUNTS (100000000/(256*PWM_FREQ_HZ))
#define MAX_ADC_VALUE (4095)

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitGPIO(void);
void InitTimer2AndOC8(void);

