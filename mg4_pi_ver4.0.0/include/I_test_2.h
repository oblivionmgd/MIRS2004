#ifndef __Itest2__
#define __Itest2__
#include <opencv2/opencv.hpp>

typedef enum{
	STP = 0,
	STR,
	ROT
} run_state_t;

#define NUM_LEN 1 // 読み取る数字の最大個数
#define __NUMBER_DEBUG__

extern void request_set_runmode(run_state_t state, int speed, int dist);
extern int  request_get_runmode(run_state_t *state, int *speed, int *dist);
extern int  number_detect(int dist);
extern int  number_search(const cv::Mat img_src);
extern void number_set_device(int device);
extern void number_get(int *ans);


#endif
