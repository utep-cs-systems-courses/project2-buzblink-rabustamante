

#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "buzzer.h"

void

__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */

  static char blink_count = 0;

  if((++blink_count %25)==0){

    buzzer_advance();

  }

  if(blink_count == 250){

    main_state_advance();

    blink_count =0;

  }

}
