#include <msp430.h>
#include "switches.h"

#include "led.h"



char switch_state_down, switch_state_changed; /* effectively boolean */

static char

switch_update_interrupt_sense()

{

  char p1val = P2IN;

  /* update switch interrupt to detect changes from current buttons */

  P2IES |= (p1val & SWITCHES);/* if switch up, sense down */

  P2IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  return p1val;

}


void

switch_init()/* setup switch */

{

  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();

  led_update();

}

void

switch_interrupt_handler()

{

  char p1val = switch_update_interrupt_sense();
  char state =0;
  if(SWITCHES){
     switch_state_down =~(switch_state_down);
   
    switch_state_changed =1;

    led_update();
  }
}

 
