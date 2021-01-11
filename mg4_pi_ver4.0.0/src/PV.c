#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"


int main(){
  int mode, speed, dist;
  double volt;
  //char buf[256];
  run_state_t state;

  printf("1入れて\n");
  scanf("%d",&mode);
  switch(mode){
    case 1:
      request_set_runmode(ROT, 45, 90);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        //request_get_convmode();
        if( state == STP ) break;
      }
			usleep(10*1000);

      request_set_runmode(STR, 30, 100);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
      }
			usleep(10*1000);
      break;
    default:
      break;
  }
}