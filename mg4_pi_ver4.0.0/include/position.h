#ifndef __POSITION__
#define __POSITION__

extern void position_set_first(double x_s, double y_s, double dir_s);
extern void position_straight(double dist);
extern void position_rotate(double angle);
extern void position_correct(double dist);
extern void position_get_coord(double *x_g, double *y_g, double *dir_g);
extern void position_set_coord(double d_l, double d_r);
extern void position_set_field(double x, double y);
extern void position_get_field(double *xl, double *yl);
extern char position_get_area();

#endif
