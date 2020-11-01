#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "buzzer.h"

#include "switches.h"

char toggle_red()/* always toggle! */

{

  red_on = 1;

  led_changed = red_on;



  green_on =0;

  led_update();

}



char toggle_green(){

  green_on = 1;

  led_changed = green_on;

  red_on = 0;

  led_update();

}
char toggle_red_green(){

  static char state =0;

  switch(state){

  case 0:

    toggle_green();

    state =1;
    break;

  case 1:
    toggle_red();
    state =0;

    break;

  default:
    state= 0;
    break;
  }

}


void dimLight()

{

  char on_state = 0;

  char led = 0;

  char changed =0;

  switch(on_state)

    {

    case 0:

      ++on_state;

      break;

    case 1:

      ++on_state;

      break;

    case 2:

      ++ on_state;

    case 3:

      changed = toggle_red();

      on_state = 1; /*reset state*/
      break;

    }

  led_changed = changed;

  led_update();

}

void go_up()

{

  int sb = 1;

  toggle_green();

}

void go_down()

{

  int sb = 0;

  toggle_red();



}

void brightLight()

{

  char on_state = 0;

  char changed =0;

  char led = 0;



  switch(on_state){

  case 0:

    changed = toggle_red();

    ++on_state;

  case 1:

    changed  = toggle_red();

    ++on_state;

    break;

  case 2:

    changed = toggle_red();

    ++on_state;

    break;

  case 3:

    on_state = 1; /*reset state*/

    break;

  }

  led_changed = changed;

  led_update();

}



void buzzer_advance()

{

  char buzzer_state;

  static int x  = 500;

  if(buzzer_state){

    x+=225;

  }

  else{

    x -= 400;

  }

  short cycle = 2000000/x;

  buzzer_set_period( cycle);

}

void main_state_advance()

{


  static char  state =0;



  switch(state){



  case 0:



  case 1:



    go_up();



    state++;


    break;


  case 2:


    go_down();


    state =0;

  default:

    break;

  }
}
