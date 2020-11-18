#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "arduino.h"
#include "request.h"
#include "test_field.h"
#include ""

int main(){
	int speed, dist;
	long dist_l, dist_r, d_l, d_r, angle, d_average;
	run_state_t state;

  if(arduino_open() != 0) return -1;

  request_set_runmode(ROT, 45, 90);
  while(1){
    request_get_dist(int *dist_l, int *dist_r);
    d_l = dist_l;
    d_r = dist_r;
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      request_get_dist(int *dist_l, int *dist_r);
      d_l -= dist_l;
      d_r -= dist_r;
      d_average = (d_l + d_r)/2;
      angle = (d_average % (32.1 * M_PI))/(32.1 * M_PI) * 360;
      break;
    }
    usleep(10*1000);
  }

  usleep(1000*1000);

  speed = 30;
	dist = 400;

  request_set_runmode(STR, speed, dist);
  while(1){
    request_get_dist(int *dist_l, int *dist_r);
    d_l = dist_l;
    d_r = dist_r;
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      request_get_dist(int *dist_l, int *dist_r);
      d_l -= dist_l;
      d_r -= dist_r;
      d_average = (d_l + d_r)/2;
      break;
    }
    usleep(10*1000);
  }

  usleep(1000*1000);

  request_set_runmode(ROT, 45, 180);
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
  }

  request_set_runmode(STR, 30, d_average);
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
  }

  dist = 180 - angle;

  request_set_runmode(ROT, 45, dist);
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
  }

  void get_field(double x, double y){
    x = d_average * cos(angle / 360);
    y = d_average * sin(angle / 360);
  }



	arduino_close();
	return 0;
}
