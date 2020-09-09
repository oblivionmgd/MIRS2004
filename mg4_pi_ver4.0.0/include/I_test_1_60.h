#ifndef __Itest160__
#define __Itest160__

typedef enum{
	STP = 0,
	STR,
	ROT
} run_state_t;

extern void request_set_runmode(run_state_t state, int speed, int dist);
extern int  request_get_runmode(run_state_t *state, int *speed, int *dist);

#endif
