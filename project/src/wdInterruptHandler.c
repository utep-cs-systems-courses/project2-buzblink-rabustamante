

#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "buzzer.h"

#include "switches.h"


void

__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  

  
    if ((switch_state_changed ==0) &&(++blink_count !=125)){
      
      switch_interrupt_handler();
      blink_count = 0;
    }
    else{
      toggle_red_green();
	
     }
    
    if((switch_state_changed == 1) &&(++blink_count %25)==0){
      switch_interrupt_handler();
      blink_count =0;
    }
    else{
      toggle_red_green();
    }
   
}
    

    
