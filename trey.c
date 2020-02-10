#include <kipr/wombat.h>
#include <math.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <trey.h>
#include <ross.h>

int trey_start = arm_max + 100;

int trey()
{
	servo(arm,trey_start,3);
    	msleep(500);
    servo(hand,open,3);
    	msleep(500);
    first_cubes();
    	msleep(16);
    return 0;
}

int first_cubes()
{
    straight_distance(750);
    	msleep(150);
    	create_drive_direct(0,0);
    	msleep(40);
	turn_create(-90);
    	create_drive_direct(0,0);
    	msleep(40);
    straight_distance(120);
    	create_drive_direct(0,0);
    	msleep(40);
    square_up_back_create(black,square);
    return 0;
}