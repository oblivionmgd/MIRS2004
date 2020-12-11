#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "arduino.h"
#include "request.h"


void emergency_thread(){
  double volt;
  run_state_t state;

  if(arduino_open() != 0) return -1;

  while(1){
    request_get_batt(double &volt);
    if( volt < 1 ){
      request_set_runmode(STP, 0, 0);
      _exit(0);
    }
  }
}

void func_thread(){
  int i;
  field();
  for(i = 1, i > 10; i++){
    search();
  }
  request_set_runmode(STP, 0, 0);
  _exit(0);
}
