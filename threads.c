#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <threads.h>
#include <trey.h>
#include <ross.h>

void thread_green_up(){
    msleep(300);
    servo(arm,arm_min,2);
}

void thread_four_down(){
    msleep(750);
    servo(arm,chain_arm,3);
}