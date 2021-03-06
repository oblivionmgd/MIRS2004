#include <stdio.h>
#include "arduino.h"
#include "I_test_1_30.h"

int main(){
  int mode, speed, dist;
  double volt;
  //char buf[256];
  run_state_t state;

  if(arduino_open() != 0) return -1;


        speed = 30;
        dist = 300;

        request_set_runmode(STR, speed, dist);
        while(1){
          request_get_runmode(&state, &speed, &dist);
          if( state == STP ) break;
        }

  arduino_close();
  return 0;
}
