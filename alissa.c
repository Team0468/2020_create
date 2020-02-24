#include <kipr/botball.h>
#include <math.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <alissa.h>
#include <camera.h>
#include <filter.h>
int above_yellow = arm_min + 900;
int clear_swings = arm_min + 150;
int grab_yellow = arm_min + 1240;
int yellow_above_pvc = arm_min + 330;
int yellow_place = arm_min + 1200;
int under_bridge = arm_min + 1500;
int open_yellow = closed + 1150;
int close_yellow = closed + 100;
int cET_buff = 2300;
double correction = 0.66667;

int alissa()
{
    create_connect();
    calibrate_gyro();
    start_position();//create_functions.c
    //wait_for_light(port);
    out_of_box();
    ///////////////////////////////////////////
    thread first_servos_thread;//creation and executiojn of servo thread for squaring up first yellow block
    first_servos_thread = thread_create(first_servos);
    thread_start(first_servos_thread);
    ///////////////////////////////////////////
    get_to_yellow();
    get_to_one();
    thread_destroy(first_servos_thread);//kill the previous threads to avoid servo failure
    take_yellow();
    /*yellow_one();
    get_to_yellow();
    get_to_two();
    take_yellow();
    yellow_two();
    get_to_yellow();
	get_to_three();
    msleep(1000);*/
    create_disconnect();
    return 0;
}




int out_of_box(){
//notes
//base postition = 150 
    create_drive_direct(400,-400);
    msleep (87);
    square_up_back_create(black,square+50);
    create_drive_direct(100,100);
    msleep (50);
    square_up_back_create(white,square);
    return 0;
}
void create_line_follow_bang(){
    create_drive_direct(250,250);
    msleep(15);
    while(get_create_lbump()==0 && get_create_rbump()==0){
        if(get_create_lfcliff_amt() < 1600){
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
int get_to_yellow(){
    create_stop();
    msleep(55);
    PID_gyro_drive_create(normal,(1*correction)); //runs towards cubes //1.3 //original=(200,1)
    turn_with_gyro_create(250, -90); 
    create_drive_direct(-300,-300);  //physical square up  
    msleep(800);
    create_stop();
    msleep(15);
    return 0;
}
int get_to_one(){
    PID_gyro_drive_create(normal, .6*correction); //distance until yellow 1
    create_stop();
    msleep(50);
    turn_with_gyro_create(250, 90);  // infront of yellow 1
    msleep(50); 
    create_stop();
    msleep(100);
    return 0;
}
int take_yellow(){
    /*slow_arm (above_yellow, 2);
    msleep (1000);
    slow_hand (open_yellow, 1);///this is currently threaded above
    msleep (500);*/
    PID_gyro_drive_create_et(140, cET_buff);
    slow_arm (grab_yellow, 2);
    msleep (400);
    slow_hand (close_yellow, 3);
    msleep (400);
    slow_arm (yellow_above_pvc, 3);
    msleep (500);
    return 0;
}
int yellow_one(){
    square_up_back_create(black,-square);
    slow_arm (clear_swings, 1);
    msleep (700);
    turn_with_gyro_create(200, 180);  // deliever one
    PID_gyro_drive_create(-1*normal, 0.75*correction);
    square_up_back_create(black,square); //on box line
    PID_gyro_drive_create(normal, 0.2*correction);
	adjust_cube();    
    create_drive_direct(-250,200); // -200, 200
    msleep (225);					//225
    create_stop();
    msleep(100);
    slow_hand (open_yellow, 1); //one is in the box
    msleep (300);   
    slow_arm (clear_swings, 1);
    msleep (600); 
    create_drive_direct(-200,-300); 
    msleep(700); 
    square_up_back_create(black, square); 
    turn_with_gyro_create(200, 180);  
    square_up_back_create(black, -square);  
    return 0;
}

int get_to_two(){
    PID_gyro_drive_create(normal, 2.2*correction);
    create_stop();
    msleep(100);
    turn_with_gyro_create(200, 90);// infront of yellow 2
    create_stop();
    msleep(100);
    create_stop();
    msleep(100); 
    return 0;
}

int yellow_two(){
    square_up_back_create(black,-square); //square up on middle line facing cubes
    slow_arm (clear_swings, 2);
    msleep (600);
    turn_with_gyro_create(200, 90);   // deliever two
    //bang
    PID_gyro_drive_create(-1*normal, 0.3*correction);
    turn_with_gyro_create(200, 90);
    PID_gyro_drive_create(-250, 1);
    square_up_back_create(black,square); //square up on box line facing inside of box 
    PID_gyro_drive_create(-250, 1.25);
    create_drive_direct(-250,200);
    msleep (100);
    create_stop();
    msleep(100);
    slow_arm (yellow_place, 1);
    msleep (400);
    slow_hand (open_yellow, 1);
    msleep(400);
    slow_arm (clear_swings, 1);
    msleep(400); 
    create_drive_direct(200,-200); 
    msleep(200); 
    square_up_back_create(black, square);
    turn_with_gyro_create(200, 180);
    PID_gyro_drive_create(-1*normal, 1*correction);
    square_up_back_create(black, square);  
    return 0;
}
int get_to_three(){
    create_drive_direct(0,0); 
    msleep(200); 
    slow_arm (yellow_above_pvc, 1);
    msleep(3000);
    /*PID_gyro_drive_create(300, 3);
    create_stop();
    msleep(100);
    turn_with_gyro_create(200, 90);// infront of yellow 1
    create_stop();
    msleep(100);
    create_stop();
    msleep(100); */
    return 0;
}
void first_servos(){
    slow_arm (above_yellow, 2);    
    slow_hand (open_yellow, 1);
}
int adjust_cube(){
	slow_arm (yellow_place, 2);
   	msleep(400);
    slow_hand (open_yellow, 2);
    msleep(400);
    slow_arm (under_bridge, 2);
    msleep(400);
    slow_hand (close_yellow, 2);
    msleep(400);
    slow_arm (yellow_place, 2);
    msleep(400);
    return 0;
}

