#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"


void GPIO_PORT_F_init(void) {
    SYSCTL_RCGC2_R |= 0x20;                    /* Enable clock for Port F */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;            /* Unlock Port F configuration */
    GPIO_PORTF_CR_R = 0x1F;                    /* Allow configuration changes on PF0-PF4 */
    GPIO_PORTF_DEN_R = 0x1F;                   /* Enable digital functions on PF0-PF4 */
    GPIO_PORTF_DIR_R = 0x0E;                   /* Set PF1, PF2, PF3 as outputs; PF0, PF4 as inputs */
    GPIO_PORTF_PUR_R = 0x11;                   /* Pull-up resistors for PF0 and PF4 */


    NVIC_EN0_R |= 1 << 30;                     /* Enable interrupts for Port F */
    GPIO_PORTF_IS_R = 0x00;                    /* Set edge-sensitive interrupts */
    GPIO_PORTF_IBE_R = 0x00;                   /* Single edge triggering */
    GPIO_PORTF_IEV_R = 0x00;                   /* Trigger on falling edge */
    GPIO_PORTF_IM_R |= 0x11;                   /* Unmask interrupts on PF0 and PF4 */
}
void GPIO_PORT_B_init(void) {
    SYSCTL_RCGCGPIO_R |= 0x02;                 /* Enable clock for Port B */
    SYSCTL_RCGCUART_R |= 0x02;                 /* Enable clock for UART1 */

    GPIO_PORTB_DEN_R |= 0x03;                  /* Enable digital functionality for PB0 and PB1 */
    GPIO_PORTB_AFSEL_R |= 0x03;                /* Set alternate functions for PB0, PB1 */
    GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF00) | 0x00000011; /* Configure PB0, PB1 for UART */
}
