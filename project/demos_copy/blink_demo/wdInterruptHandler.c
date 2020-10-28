#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char state  = 0;
  static char changed =0;
  if ((blink_count %=25) ==0) {
     buzzer_advance();
  }
  if(blink_count ==250){ 
    main_state_advance();
    count =0;
  }
}
