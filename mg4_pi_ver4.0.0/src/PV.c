#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"
int main(){
  char passbuf[] = "python3 /home/pi/MIRS2004/MIRSFace/face.py";
  int mode, speed, dist;
  //double volt;
  //char buf[256];
  run_state_t state;
  conv_state_t conv_state;

  printf("1入れて\n");
  scanf("%d",&mode);
  switch(mode){
    case 1:
      system(passbuf);
      //一個目
      /*request_set_runmode(ROT, 45, 90);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);*/

      request_set_runmode(ROT, 45, 30);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);

      request_set_runmode(STR, 30, 50);
      request_set_convmode(RT);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);

      //二個目
      request_set_runmode(ROT, 45, 120);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);
/*
      request_set_runmode(ROT, 45, 90);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);*/
/*
      request_set_runmode(ROT, 45, -45);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);*/

      request_set_runmode(STR, 30, 50);
      request_set_convmode(RT);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);

      //三個目
      request_set_runmode(ROT, 45, 100);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);
/*
      request_set_runmode(ROT, 45, 90);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);

      request_set_runmode(ROT, 45, 45);
      request_set_convmode(ST);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);*/

      request_set_runmode(STR, 30, 50);
      request_set_convmode(RT);
      while(1){
        request_get_runmode(&state, &speed, &dist);
        request_get_convmode(&conv_state);
        if( state == STP ) break;
  			usleep(10*1000);
      }
			usleep(1000*1000);

      request_set_convmode(ST);
      request_get_convmode(&conv_state);
      break;
    default:
      break;
  }
  arduino_close();
	return 0;
}
