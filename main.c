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

}
