//#include <kipr/botball.h>
int initialize();
int camera_rotate(int channel);
int is_present(int channel);
#define red 0 //hue:338-358 saturation:143-176 value:110-190
#define green 1 //hue:148-170 saturation:70-236 value:90-217
#define yellow 2 //hue:42-62 saturation:63-199 value:88-222
#define initial 0
int where();
void camera_thread_func();
double timer, init_time, cur_time;

int yb1,y2,y3,g1,g2,g3,g4,r1,r2,r3,r4;
int camera_initialize();
int full_check(int c);
int camera_center(int color);
int block_check();
int yellow_camera(int color);
int i;