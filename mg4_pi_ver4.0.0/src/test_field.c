#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "arduino.h"
#include "request.h"
#include "position.h"
#include "test_field.h"

int main(){
	int speed, dist, dist_l, dist_r;
	double d_l, d_r, x, y, dir;
	run_state_t state;

  if(arduino_open() != 0) return -1;

	position_set_first(0, 0, 90);

  request_set_runmode(ROT, 45, 90);
	request_get_dist(&dist_l, &dist_r);
	d_l = dist_l;
	d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      break;
    }
    usleep(10*1000);
  }

  usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l -= dist_l;
	d_r -= dist_r;
	position_set_coord(d_l, d_r);

  speed = 30;
	dist = 400;

  request_set_runmode(STR, speed, dist);
  request_get_dist(&dist_l, &dist_r);
  d_l = dist_l;
  d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      break;
    }
    usleep(10*1000);
  }

	usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l -= dist_l;
	d_r -= dist_r;
	position_set_coord(d_l, d_r);

	position_get_coord(&x, &y, &dir);
	position_set_field(x, y);

  request_set_runmode(ROT, 45, 180);
  request_get_dist(&dist_l, &dist_r);
  d_l = dist_l;
  d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    usleep(10*1000);
  }

	usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l -= dist_l;
	d_r -= dist_r;
	position_set_coord(d_l, d_r);

	dist = x / sin(dir / 360);

  request_set_runmode(STR, speed, dist);
	request_get_dist(&dist_l, &dist_r);
  d_l = dist_l;
  d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    usleep(10*1000);
  }

	usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l -= dist_l;
	d_r -= dist_r;
	position_set_coord(d_l, d_r);

  dist = 90 - dir;

  request_set_runmode(ROT, 45, dist);
	request_get_dist(&dist_l, &dist_r);
  d_l = dist_l;
  d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    usleep(10*1000);
  }

	usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l -= dist_l;
	d_r -= dist_r;
	position_set_coord(d_l, d_r);


	arduino_close();
	return 0;
}
