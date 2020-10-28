#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
 {
   /* char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();*/

   led_changed = toggle_red();
   led_update();
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

