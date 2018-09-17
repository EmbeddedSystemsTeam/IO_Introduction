#include "msp.h"


/**
 * Toggles LED on and off every 1ms.
 */
void main(void)
{
    volatile int i;									//Int used for delay.
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer.

	//Leave off to not consume power in case it blocks.
	P2 -> DIR |= BIT3;								//Init P2.3 as Output

	while(1)
	{
	    P2 -> OUT ^= BIT3;							//Toggle P2.3 / Toggle LED.
	    for (i = 0; i < 12800; i++); 				//Delay for 1ms.
	}
	return 0;										//@Unreachable successful termination.
}
