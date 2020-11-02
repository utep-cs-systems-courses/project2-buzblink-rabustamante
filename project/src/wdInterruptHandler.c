

#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "buzzer.h"

#include "switches.h"


void

__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  
  if(++blink_count ==125){
    toggle_red_green();
    switch(switch_state_changed){
      
    /*  sw1 is pressed*/
    case 0:
    
      switch_interrupt_handler();
      switch_state_changed =0;
      break;
    /*sw2 is pressed*/
    case 1:
    
       switch_interrupt_handler();
       switch_state_changed =1;
       break;
    /*sw3 is prested*/
    case 2:
      
      switch_interrupt_handler();
      switch_state_changed =2;
      break;
    case 3:
      
      switch_interrupt_handler();
      switch_state_changed =0;
      break;   
    }
  }
}
  
    

    
