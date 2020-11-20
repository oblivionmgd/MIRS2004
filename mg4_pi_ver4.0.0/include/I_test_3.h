#ifndef __Itest3__
#define __Itest3__

typedef enum{
	STP = 0,
	STR,
	ROT
} run_state_t;

extern void request_set_runmode(run_state_t state, int speed, int dist);
extern int  request_get_runmode(run_state_t *state, int *speed, int *dist);
extern int  request_get_dist(int *dist_l, int *dist_r);
extern int  io_open();
extern void io_get_sw(int *sw_f, int *sw_l, int *sw_r);
extern int  uss_open_l();
extern int  uss_open_r();
extern long uss_get_l();
extern long uss_get_r();

#endif
