#include <kipr/wombat.h>
#include <math.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <trey.h>
#include <ross.h>

int trey_start = arm_max + 500;
int smol_cubes = closed + 200;
int stack_hand = closed + 300;
int stack_arm = arm_max + 800;

int trey()
{
    create_connect();
	servo(arm,arm_max,3);
    	msleep(16);
    //servo(hand,open,3);
    	msleep(16);
    //first_cubes();
    	msleep(16);
    create_disconnect();
    return 0;
}

int first_cubes()
{
    straight_distance(550);
		msleep(40);
	turn_create(-90);
    	msleep(16);
    	create_drive_direct(0,0);
    	msleep(16);
    square_up_back_create(black,square);
    	msleep(16);
    straight_distance(-40);
    	msleep(16);
    create_stop();
    	msleep(500);
    /////////////////////////		//begin stacking
    servo(hand,smol_cubes,2);
    	msleep(500);
    servo(arm,stack_arm,2);
    	msleep(500);
    square_up_back_create(black,square);
    	msleep(500);
    servo(hand,stack_hand,2);
    	msleep(500);
    servo(arm,trey_start,2);
    	msleep(500);
    servo(hand,smol_cubes,2);
    	msleep(16);
    
    return 0;
}
