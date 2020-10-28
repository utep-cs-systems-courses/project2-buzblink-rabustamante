//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  buzzer_init();

  or_sr(0x18);		/* CPU off, GIE on */
}
