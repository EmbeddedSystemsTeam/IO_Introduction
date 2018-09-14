#include "msp.h"


/**
 * main.c
 */
void main(void)
{
    volatile int i;

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Init LOED pin as OUTPUT.
	//Leave off to not consume power in case it blocks.
	P2 -> DIR |= BIT3;

	while(1)
	{
	    P2 -> OUT ^= BIT3;

	    for (i = 0; i < 12800; i++);
	}

	return 0;
}
