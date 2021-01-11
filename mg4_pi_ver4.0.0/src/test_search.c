#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"
#include "position.h"
#include "test_search.h"

int main(){
	int speed, dist;
	double dist_l, dist_r, d_l, d_r, d_lo, d_ro, xl, yl, x, y, dir;
	run_state_t state;

  if(arduino_open() != 0) return -1;

  position_set_first(0, 0, 90);

  request_set_runmode(ROT, 45, 360);
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
	d_lo = dist_l - d_l;
	d_ro = dist_r - d_r;
	position_set_coord(d_lo, d_ro);

  speed = 30;
	dist = 400;

	position_get_field(&xl, &yl);
  request_set_runmode(STR, speed, dist);
	request_get_dist(&dist_l, &dist_r);
  d_l = dist_l;
  d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
		request_get_dist(&dist_l, &dist_r);
		d_lo = dist_l - d_l;
		d_ro = dist_r - d_r;
		d_l = dist_l;
		d_r = dist_r;
		position_set_coord(d_lo, d_ro);
		position_get_coord(&x, &y, &dir);

		if( x > xl ){
			dist = 0 - dir;
		  request_set_runmode(ROT, 45, dist);
			while(1){
				request_get_runmode(&state, &speed, &dist);
		    if( state == STP ) break;
				usleep(10*1000);
			}
			usleep(1000*1000);

			request_get_dist(&dist_l, &dist_r);
			d_lo = dist_l - d_l;
			d_ro = dist_r - d_r;
			position_set_coord(d_lo, d_ro);
		}

		if( x < 0 ){
			dist = 0 - ( dir - 180 );
		  request_set_runmode(ROT, 45, dist);
			while(1){
				request_get_runmode(&state, &speed, &dist);
		    if( state == STP ) break;
				usleep(10*1000);
			}
			usleep(1000*1000);

			request_get_dist(&dist_l, &dist_r);
			d_lo = dist_l - d_l;
			d_ro = dist_r - d_r;
			position_set_coord(d_lo, d_ro);
		}

		if( y > yl ){
			dist = 0 - ( dir + 90 ) % 360;
		  request_set_runmode(ROT, 45, dist);
			while(1){
				request_get_runmode(&state, &speed, &dist);
		    if( state == STP ) break;
				usleep(10*1000);
			}
			usleep(1000*1000);

			request_get_dist(&dist_l, &dist_r);
			d_lo = dist_l - d_l;
			d_ro = dist_r - d_r;
			position_set_coord(d_lo, d_ro);
		}

		if( y < 0 ){
			dist = 180 - ( dir + 90 );
		  request_set_runmode(ROT, 45, dist);
			while(1){
				request_get_runmode(&state, &speed, &dist);
		    if( state == STP ) break;
				usleep(10*1000);
			}
			usleep(1000*1000);

			request_get_dist(&dist_l, &dist_r);
			d_lo = dist_l - d_l;
			d_ro = dist_r - d_r;
			position_set_coord(d_lo, d_ro);
		}

    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      break;
    }
    usleep(10*1000);
  }

	usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l = dist_l - d_l;
	d_r = dist_r - d_r;
	position_set_coord(d_l, d_r);

  arduino_close();
	return 0;
}
