#include <msp430.h>

volatile unsigned int led = 0;

unsigned int toggle (unsigned int value)
{
    unsigned int retVal = 0;

    if (value == 0)
        retVal = 1;
    else
        retVal = 0;

    return retVal;
}

int main(void){
  volatile unsigned int i;

  WDTCTL = WDTPW+WDTHOLD;   // Stop WDT
  P1DIR |= BIT0;            // P1.0 set as output

  while(1){                 // continuous loop
    P1OUT ^= BIT0;          // XOR P1.0
    led = toggle(led);
    for(i=50000;i>0;i--);   // Delay
  }
}
