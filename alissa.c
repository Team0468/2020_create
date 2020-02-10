#include <kipr/wombat.h>
#include <math.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <alissa.h>
#include <camera.h>

int above_yellow = arm_min + 800;
int clear_swings = arm_min + 230;
int grab_yellow = arm_min + 920;
int yellow_above_pvc = arm_min + 640;
int yellow_place = arm_min + 940;
int open_yellow = closed + 950;
int close_yellow = closed + 100;

int alissa()
{
    create_connect();
	start_position();
    out_of_box();
    get_to_yellow();
	get_to_one();
    take_yellow();
    yellow_one();
    get_to_yellow();
    get_to_two();
    take_yellow();
    yellow_two();
	bang();
	finish_two();
    get_to_yellow();
    create_disconnect();
    return 0;
}




int out_of_box(){
    create_drive_direct(100,-100);
    msleep (350);
    square_up_back_create(black,square);
    create_drive_direct(100,100);
    msleep (50);
    square_up_back_create(white,square);
    return 0;
}
void create_line_follow_bang(){
    create_full();
    msleep(15);
    while(get_create_lbump()==0 && get_create_rbump()==0){
        if(get_create_rfcliff_amt() < 1600){
            create_drive_direct(166,250);
        }
        else{
            create_drive_direct(250,166);
        }
        msleep(15);
    }
    create_safe();
    msleep(15);
}
int get_to_yellow(){//this function is way to Fing fast!!!!!!!!!!!!!!!!!!!!!!!!!
    create_stop();
    msleep(200);
    create_drive_direct(500,500);
    msleep(700);
    create_drive_direct(-400,400); //replace with gyro -90
    msleep(600); 
    create_drive_direct(-200,-200);  //physical square up  
    msleep(900);
    create_stop();
    msleep(200);
    return 0;
}
int get_to_one(){
    yellow_camera(yellow); //forward past yellow
    create_drive_direct(-250,-250);  //back up to allign with yellow 
    msleep(600);
    create_stop();
    msleep(100);
    create_drive_direct(400,-400); //replace with gyro 90 // infront of yellow 1
    msleep(515); 
    create_stop();
    msleep(100);
    return 0;
}
int take_yellow(){
    slow_arm (above_yellow, 2);
    msleep (1000);
    slow_hand (open_yellow, 1);
    msleep (500);
    slow_arm (grab_yellow, 1);
    msleep (400);
    slow_hand (close_yellow, 1);
    msleep (400);
   	slow_arm (yellow_above_pvc, 1);
    msleep (500);
    return 0;
}
int yellow_one(){
    square_up_back_create(black,-square);
    msleep (100);
    slow_arm (clear_swings, 1);
    msleep (600);
    create_drive_direct(-200,200); //replace with gyro 180 // deliever one
    msleep(1900); 
    square_up_back_create(black,-square);
    slow_arm (yellow_place, 1);
    msleep(400);
    create_drive_direct(-100,100); 
    msleep(400); 
    create_stop();
    msleep(100);
    slow_hand (open_yellow, 1);
    msleep (300);   
    slow_arm (clear_swings, 1);
    msleep (600); 
    create_drive_direct(-200,-300); 
    msleep(600); 
    square_up_back_create(black, square); 
    create_drive_direct(-200,200); //replace with gyro 180 // deliever one
    msleep(1900); 
    square_up_back_create(black, -square);  
    create_drive_direct(200,200);
    msleep (400);   
    square_up_back_create(black,-square);
    msleep(200);
    create_stop();
    msleep(100);
    return 0;
}

int get_to_two(){
	create_drive_direct(250,250);
    msleep(1300);
    create_stop();
    msleep(100);
    create_drive_direct(200,-200); //replace with gyro 90 // infront of yellow 1
    msleep(1030); 
    create_stop();
    msleep(100);
    yellow_camera(yellow); //forward past yellow
    create_drive_direct(-250,-250);  //back up to allign with yellow 
    msleep(600);
    create_stop();
    msleep(100); 
    return 0;
}

int yellow_two(){
    square_up_back_create(black,-square);
    msleep (100);
    square_up_front_create(black,-square);    
    slow_arm (clear_swings, 2);
    msleep (600);
    create_drive_direct(200,-200); //replace with gyro 180 // deliever one
    msleep(1900); 
    square_up_back_create(black,-square);
    create_drive_direct(-200,-200);
    msleep(500); 
    create_stop();
    msleep(100);    
    slow_arm (yellow_place, 1);
    msleep(400);
    create_drive_direct(-100,100); 
    msleep(900); 
	create_stop();
    msleep(100);
    slow_hand (open_yellow, 1);
    msleep(400);
    slow_arm (clear_swings, 1);
    msleep(400);
    create_drive_direct(-200,-200);
    msleep(500);    
	return 0;
}
int finish_two(){
    create_drive_direct(-100,-100); //back up from wall
    msleep(300); 
	create_stop();
    msleep(100); 
    create_drive_direct(250,-250); 
    msleep(300); 
	create_stop();
    msleep(100); 
    square_up_back_create(black, -square);
    create_drive_direct(200,-200); //replace with gyro 180 // deliever one
    msleep(1900); 
    square_up_front_create(black, -square);
	return 0;
}