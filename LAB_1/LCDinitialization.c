#include "msp.h"

/*
 * Function to enact delays according to external calculations(MSP freq times time needed to be delayed
 */
void delay(int n)
{
    volatile int i;
    for (i = 0; i < n; i++)
        ;
}

/*
 * Sets interface data length, number of display line and character font.
 */
void setLCD()
{
    //initializing ports and pins
    //D7 to D0
    P4->DIR |= (BIT7 + BIT6 + BIT5 + BIT4 + BIT3 + BIT2 + BIT1 + BIT0 );
    //RS & R/W
    P2->DIR |= (BIT6 + BIT5 );
    //Enabler
    P3->DIR |= BIT0;
    //sending the bit values corresponding with the set command
    unsigned char a = 0x38;
    P4->OUT = a;
    //BIT related to RS
    P2->OUT &= ~BIT6;
    //BIT related to R/W
    P2->OUT &= ~BIT5;
    //Enables data read/write from MSP to LCD pins
    P3->OUT |= BIT0;
    //Disables data read/write
    P3->OUT &= ~BIT0;
}

/*
 * Sets On/Off of the display, cursor, and blink of the cursor position
 */
void displayONOFF()
{
    //initializing ports and pins
    //D7 to D0
    P4->DIR |= (BIT7 + BIT6 + BIT5 + BIT4 + BIT3 + BIT2 + BIT1 + BIT0 );
    //RS & R/W
    P2->DIR |= (BIT6 + BIT5 );
    //Enabler
    P3->DIR |= BIT0;
    //sending the bit values to turn ON/OFF the display
    unsigned char a = 0x0F;
    P4->OUT = a;
    //BIT related to RS
    P2->OUT &= ~BIT6;
    //BIT related to R/W
    P2->OUT &= ~BIT5;
    //Enables data read/write from MSP to LCD pins
    P3->OUT |= BIT0;
    //Disables data read/write
    P3->OUT &= ~BIT0;
}

/*
 * Clears display and returns cursor to the home position (address 0) of the display.
 */
void clearDisplay()
{
    //initializing ports and pins
    //D7 to D0
    P4->DIR |= (BIT7 + BIT6 + BIT5 + BIT4 + BIT3 + BIT2 + BIT1 + BIT0 );
    //RS & R/W
    P2->DIR |= (BIT6 + BIT5 );
    //Enabler
    P3->DIR |= BIT0;
    //sending the bit values corresponding with to clear the display
    unsigned char a = 0x01;
    P4->OUT = a;
    //BIT related to RS
    P2->OUT &= ~BIT6;
    //BIT related to R/W
    P2->OUT &= ~BIT5;
    //Enables data read/write from MSP to LCD pins
    P3->OUT |= BIT0;
    //Disables data read/write
    P3->OUT &= ~BIT0;
}

/*
 * module used only during initialization sequence;
 * Sets Interface data length(8 bits), number of display lines(2),
 * and character font(5x8 dots)
 */
void entryMode()
{
    //initializing ports and pins
    //D7 to D0
    P4->DIR |= (BIT7 + BIT6 + BIT5 + BIT4 + BIT3 + BIT2 + BIT1 + BIT0 );
    //RS & R/W
    P2->DIR |= (BIT6 + BIT5 );
    //Enabler
    P3->DIR |= BIT0;
    //sending the bit values corresponding with the set entry mode command
    unsigned char a = 0x06;
    P4->OUT = a;
    //BIT related to RS
    P2->OUT &= ~BIT6;
    //BIT related to R/W
    P2->OUT &= ~BIT5;
    //Enables data read/write from MSP to LCD pins
    P3->OUT |= BIT0;
    //Disables data read/write
    P3->OUT &= ~BIT0;
}

/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    //initialization sequence
    //wait 40ms for VDD to rise
    delay(5120);
    //Function Set Command
    setLCD();
    //wait 4.1ms
    delay(525);
    //Function Set Command
    setLCD();
    //wait 100us
    delay(13);
    //Function Set Command
    setLCD();
    //Turn on display and enable cursor
    displayONOFF();
    //clear display and reset cursor
    clearDisplay();
    //entry mode command
    entryMode();
}
