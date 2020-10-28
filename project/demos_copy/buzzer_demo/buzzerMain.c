#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main(){
  
    configureClocks();
    buzzer_init();
    char  on_state =0;
    switch(on_state){
      case 0:
	on_state =1;
	break;
      case 1:
	buzzer_set_period(6000);
	buzzer_set_period2(1000);
	on_state =1;
	break;  
    } 
    or_sr(0x18);          // CPU off, GIE on
    
}
