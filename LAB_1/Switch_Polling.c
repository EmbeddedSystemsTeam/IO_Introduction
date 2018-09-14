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
    P2->DIR |= BIT3;
    P2->DIR |= BIT4;

    //Init button as INPUT.
    P3->DIR &= BIT7;                               //Pull-Up Button.
    P3->DIR &= BIT6;                               //Pull-Down Button.

    while (1)
    {

        if (P3->IN & BIT7)              //If Pull-Up Button is Pressed. LOGIC 0.
        {
            P2->OUT &= ~BIT4;                      //Turn Off
        }
        else
        {
            P2->OUT |= BIT4;                       //
        }

        if (P3->IN & BIT6)            //If Pull-Down Button is Pressed. LOGIC 1.
        {
            P2->OUT &= ~BIT3;
        }
        else
        {
            P2->OUT |= BIT3;
        }
    }

    return 0;
}

//IF PRESSED
//TURN ON
//ELSE
//TURN OFF
