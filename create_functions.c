#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#define hand 3
#define arm 2
#define bd 1
#define base 0
#define arm_max 2000
#define arm_min 0
#define arm_mid 600
#define hand_max 2047 //also start
#define hand_min 0
#define hand_close 330
#define base_max 2000
#define base_min 0
#define base_start 150
#define left 2
#define right 1
#define max 1500
#define bd_max 2047
#define bd_min 125


/* If you change one of the defines above that matches one below, you must change the other as well */

//#define out 125
//int out = out;
int in = out + 1875 + 47;
int between = out + 1375;

//#define down 2000
//int down = down;
int up = down - 900;
int mid = down - 550;
int arm_firefighter = down - 340; //1660
int arm_water = down - 175;
int arm_building = down - 800;
int arm_start = down - 860;

//#define front 1300
//int front = front;
int back = front - 1200;
int half = front - 700;

//#define closed 200
//int closed = closed;
int firetruck = closed + 200;
int open = closed + 1647;
int tight = closed - 200;
int small_open = closed + 1200;
int tightish = closed - 125;
int ajar = closed + 800;

void slow_arm02 (int x )//this funtion slows 
{ 

    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, x);
    disable_servo (arm);
}

void slow_arm (int x,int speed)//this funtion slows 
{ 

    enable_servo (arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (0) {desired_position = arm_max;}
    else if(0) {desired_position = arm_min;}
    else {desired_position = x;}

    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(arm, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(arm, current_position);

                 msleep(1);
                }
            }
            break;
        case 2:
            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(arm, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(arm, current_position);

                 msleep(2);
                }
            }
            break;
    }

    set_servo_position (arm, x);
    msleep(25);
    disable_servo (arm);

}

/*void slow_hand (int x )//this funtion slows 
{ 

    enable_servo(hand);
    int desired_position = x;
    int current_position = get_servo_position(hand);
    //if (x > hand_max) {desired_position = hand_max;}
    //else if(x < hand_min) {desired_position = hand_min;}
    //else {desired_position = x;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }

    set_servo_position (hand, x);
    disable_servo (hand);
}*/

void slow_hand ( int z, int speed )//this funtion slows 
{ 

    enable_servo (hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (0) {desired_position = hand_max;}
    else if(0) {desired_position = hand_min;}
    else {desired_position = z;}


    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(hand, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(hand, current_position);
                 msleep(1);
                }
            }
            break;
        case 2:

            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(hand, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(hand, current_position);

                 msleep(2);
                }
            }
            break;
    }
    set_servo_position (hand, z);
    msleep(25);
    disable_servo (hand);
}

void slow_base(int x ) 
{ 
    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (x > base_max) {desired_position = base_max;}
    else if(x < base_min) {desired_position = base_min;}
    else {desired_position = x;}
    while(current_position != desired_position){
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }
    set_servo_position (base, x);
    disable_servo (base);
}

void start_position(){
    slow_arm(arm_start,5);
    slow_base(back);
    slow_hand(open, 1);
}

void arm_out(){
    slow_base(front);
    slow_arm(down, 1);
}

void slow_base_valve()//this function slows 
{ 

    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (front-750 > base_max) {desired_position = base_max;}
    else if(front-750 < base_min) {desired_position = base_min;}
    else {desired_position = front-750;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, front-750);
    disable_servo (base);
}

void slow_start() 
{ 	
    enable_servo(arm);
    enable_servo(hand);
    enable_servo(base);
    int d = mid;
    int dd = open;
    int ddd = back;
    int c = get_servo_position(arm);
    int cc = get_servo_position(hand);
    int ccc = get_servo_position(base);

    while((c != d) || (cc != dd) || (ccc != ddd)) // this loop is being exited instantly. need to fix.
    {
        if(c < d)
        { c=c+1;
         set_servo_position(arm, c);
         msleep(2);
        }
        if(c > d)
        { c=c-1;
         set_servo_position(arm, c);
         msleep(2);
        }
        if(cc < dd)
        { cc=cc+1;
         set_servo_position(hand, cc);
         msleep(2);
        }
        if(cc > dd)
        { cc=cc-1;
         set_servo_position(hand, cc);
         msleep(2);
        }
        if(ccc < ddd)
        { ccc=ccc+1;
         set_servo_position(base, ccc);
         msleep(2);
        }
        if(ccc > ddd)
        { ccc=ccc-1;
         set_servo_position(base, ccc);
         msleep(2);
        }
        msleep(2);
    }
    set_servo_position(arm, mid);
    set_servo_position(hand,open);
    set_servo_position(base,back);
    disable_servo(arm);
    disable_servo(hand);
    disable_servo(base);
}

void slow_arm_pre_valve()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if ((up+625) > arm_max) {desired_position = arm_max;}
    else if((up+625) < arm_min) {desired_position = arm_min;}
    else {desired_position = (up+625);}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, (up+625));
    disable_servo (arm);
}

void slow_base_front()//this funtion slows 
{ 
    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (front > base_max) {desired_position = base_max;}
    else if(front < base_min) {desired_position = base_min;}
    else {desired_position = front;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, front);
    disable_servo (base);
}

void slow_arm_up()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (up > arm_max) {desired_position = arm_max;}
    else if(up < arm_min) {desired_position = arm_min;}
    else {desired_position = up;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, up);
    disable_servo (arm);
}

void slow_arm_up2()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (up > arm_max) {desired_position = arm_max;}
    else if(up < arm_min) {desired_position = arm_min;}
    else {desired_position = up;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, up);
    disable_servo (arm);

    enable_servo(base);
    int desired_position2;
    int current_position2 = get_servo_position(base);
    if (front > base_max) {desired_position2 = base_max;}
    else if(front < base_min) {desired_position2 = base_min;}
    else {desired_position2 = front;}

    while(current_position2 != desired_position2)
    {
        if(current_position2 < desired_position2)
        { current_position2=current_position2 +1;
         set_servo_position(base, current_position2);
         msleep(2);
        }
        if(current_position2 > desired_position2)
        { current_position2=current_position2 -1;
         set_servo_position(base, current_position2);
         msleep(2);
        }
    }

    set_servo_position (base, front);
    disable_servo (base);
}

void slow_hand_open()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (small_open > hand_max) {desired_position = hand_max;}
    else if(small_open < hand_min) {desired_position = hand_min;}
    else {desired_position = small_open;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }
    set_servo_position (hand, small_open);
    disable_servo (hand);
}

void slow_hand_small_open()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position = ajar+450;
    int current_position = get_servo_position(hand);
    if (closed-50 > hand_max) {desired_position = hand_max;}
    else if(closed-50 < hand_min) {desired_position = hand_min;}
    else {desired_position = closed-50;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }
    set_servo_position (hand, ajar+450);
    disable_servo (hand);
}

void slow_arm_down()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (down > arm_max) {desired_position = arm_max;}
    else if(down < arm_min) {desired_position = arm_min;}
    else {desired_position = down;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, down);
    disable_servo (arm);
}

void slow_hand_close()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position = tight;
    int current_position = get_servo_position(hand);
    //if (tight > hand_max) {desired_position = hand_max;}
    //else if(tight < hand_min) {desired_position = hand_min;}
    //else {desired_position = tight;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(hand, current_position);
         msleep(1);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(hand, current_position);
         msleep(1);
        }
    }

    set_servo_position (hand, tight);
    disable_servo (hand);
}

/*void short_pause(){
    create_stop();
    msleep(100);
}*/

void slow_arm_bucket()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (down-500 > arm_max) {desired_position = arm_max;}
    else if(down-500 < arm_min) {desired_position = arm_min;}
    else {desired_position = down-500;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, down-500);
    disable_servo (arm);
}

void shake_arm(){
    enable_servos(arm);
    int i = 0;
    while(i < 20){
        set_servo_position(arm,arm_building+325);
        msleep(30);
        set_servo_position(arm,arm_building-250);
        msleep(30);
        i=i+1;
    }
}

void fast_hand (int x){ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (x > hand_max) {desired_position = hand_max;}
    else if(x < tight) {desired_position = tight;}
    else {desired_position = x;}
    while(current_position >= desired_position+3 || current_position <= desired_position-3){
        if(current_position < desired_position)
        { current_position=current_position +3;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -3;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }
    set_servo_position (hand, x);
    disable_servo (hand);
}

void grab_water(){

    thread ad;
    thread hc;

    ad = thread_create(slow_arm_down);
    hc = thread_create(slow_hand_close);

    turn_with_gyro_create(turn,-90);
    short_pause();
    thread_start(ad);
    fast_hand(open);
    short_pause();
    thread_start(hc);
    square_up_front_create(white,square);
    short_pause();
    PID_gyro_drive_create(PID-50,0.475);
    create_stop();
    msleep(900);
    slow_arm(down-250, 60);
    PID_gyro_drive_create(-(PID*2),1);
    square_up_front_create(black,square);
    short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();

    thread_destroy(ad);
    thread_destroy(hc);
}

void pile_water(int x){
    fast_hand(closed+x);
    shake_arm();
    fast_hand(open);
    slow_arm(down, 60);
}

void push_water(){

    thread ab;

    ab = thread_create(slow_arm_bucket);

    PID_gyro_drive_create(PID,3.0);
    thread_start(ab);
    PID_gyro_drive_create(-PID,0.7);
    create_stop();
    msleep(650);

    thread_destroy(ab);
}

void recover_water(){
    PID_gyro_drive_create(-(PID*2),0.5);
    slow_arm(down, 60);
    PID_gyro_drive_create(PID*2,0.35);
    fast_hand(closed);
    PID_gyro_drive_create(-(PID*2),0.35);
    slow_arm(arm_water, 60);
    PID_gyro_drive_create(PID*2,0.5);
    fast_hand(open);
}

void first_water(){

    thread ad2;
    thread hc2;

    ad2 = thread_create(slow_arm_down);
    hc2 = thread_create(slow_hand_close);

    square_up_back_create(black,square);
    PID_gyro_drive_create(-PID,0.80);
    short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();
    thread_start(ad2);
    PID_gyro_drive_create(-(PID*2),0.75);
    thread_start(hc2);
    square_up_front_create(white,square);
    short_pause();
    PID_gyro_drive_create(PID-50,0.475);
    create_stop();
    msleep(900);
    slow_arm(down-300, 60);
    PID_gyro_drive_create(-(PID*2),1);
    square_up_front_create(black,square);
    short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();

    thread_destroy(ad2);
    thread_destroy(hc2);
}

void all_water(){
    PID_gyro_drive_create(PID*2,1.5);
    short_pause();
    PID_gyro_drive_create(-PID,0.4);
    fast_hand(tightish);
    short_pause();
}

/*void first_water_down(){

    thread ab2;

    ab2 = thread_create(slow_arm_bucket);

    PID_gyro_drive_create(PID,2.3);
    slow_arm(down-250);
    fast_hand(closed+700);
    shake_arm();
    thread_start(ab2);
    create_stop();
    msleep(650);

    thread_destroy(ab2);
}

void all_water_drop(){
    PID_gyro_drive_create(-(PID*2),1.25);
    short_pause();
    turn_with_gyro_create(turn,-90);
    PID_gyro_drive_create(-(PID*4/3),2);
    PID_gyro_drive_create(PID,0.3);
    short_pause();
    turn_with_gyro_create(turn,90);
    slow_arm(arm_water);
    square_up_front_create(black,square);
    turn_with_gyro_create(turn-50,01);
    fast_hand(open);
}

void shake_arm_bucket(){
    enable_servos(arm);
    int i = 0;
    while(i < 20){
        set_servo_position(arm,down-400);
        msleep(30);
        set_servo_position(arm,down-475);
        msleep(30);
        i=i+1;
    }
}
*/
void fast_arm (int x )//this funtion slows 
{ 

    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}
    while(current_position >= desired_position+3 || current_position <= desired_position-3)
    {
        if(current_position < desired_position)
        { current_position=current_position +3;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -3;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }
    set_servo_position (arm, x);
    disable_servo (arm);
}

void slow_arm_building()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (arm_building > arm_max) {desired_position = arm_max;}
    else if(arm_building < arm_min) {desired_position = arm_min;}
    else {desired_position = arm_building;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }
    set_servo_position (arm, arm_building);
    disable_servo (arm);
}

int check_building_one(){
    //This function was designed and created by Ryan P. Webb
    camera_open_black();
    int yCount = 0;
    int p = 0;
    while (p < 15){
        camera_update();
        if(get_object_count(0) > 0){
            yCount++;
        }
        p++;
    }
    if (yCount/15 <  .5){
        return 1;
    }else{return 0;}
    return -1;
}

void slow_arm_water()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    desired_position = arm_water;
    while(current_position >= desired_position+2 || current_position <= desired_position-2){
        if(current_position < desired_position){ 
            current_position=current_position +2;
            set_servo_position(arm, current_position);
            msleep(2);
        }
        if(current_position > desired_position){ 
            current_position=current_position -2;
            set_servo_position(arm, current_position);
            msleep(2);
        }
    }
    set_servo_position (arm, arm_water);
    disable_servo (arm);
}

void fast_bd(int x){ 
    enable_servo(bd);
    int desired_position;
    int current_position = get_servo_position(bd);
    if (x > bd_max) {desired_position = bd_max;}
    else if(x < bd_min) {desired_position = bd_min;}
    else {desired_position = x;}
    while(current_position >= desired_position+3 || current_position <= desired_position-3){
        if(current_position < desired_position)
        { current_position=current_position +3;
         set_servo_position(bd, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -3;
         set_servo_position(bd, current_position);
         msleep(2);
        }
    }
    set_servo_position(bd, x);
    disable_servo(bd);
}

void fast_base(int x){ 
    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (x > base_max) {desired_position = base_max;}
    else if(x < base_min) {desired_position = base_min;}
    else {desired_position = x;}
    while(current_position >= desired_position+2 || current_position <= desired_position-2){
        if(current_position < desired_position){
            current_position=current_position +2;
            set_servo_position(base, current_position);
            msleep(2);
        }
        if(current_position > desired_position){ 
            current_position=current_position -2;
            set_servo_position(base, current_position);
            msleep(2);
        }
    }
    set_servo_position (base, x);
    disable_servo (base);
}

void slow_base_half() 
{ 
    enable_servo(base);
    int desired_position = half;
    int current_position = get_servo_position(base);
    while(current_position != desired_position){
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }
    set_servo_position (base, half);
    disable_servo (base);
}
void towards_firetruck()
{
    arm_out(mid);
    msleep(15);
	slow_hand(closed,1); //grabs firefighter
    square_up_back_create(black, 100); // verifies line to move out of box
    msleep(100);
    square_up_back_create(black, 100);
    slow_arm(mid, 1);
    create_drive_direct(100,70); //r = 90
    msleep(500);
    create_drive_direct(100,100);//number to change if ff isnt on ft correctly
    msleep(2090); 
    create_stop();
}
void at_firetruck()
{
    slow_arm02(arm_firefighter); //ff is placed onto firetruck
	slow_hand(small_open,1);
    msleep(30);
    slow_arm02(down); 
    msleep(500);
    slow_hand(firetruck, 1);
    slow_arm(arm_building,1); //with ft in hand, arm moves to building height
}
void transport_firetruck()
{
    turn_with_gyro_create(60, 90);
    square_up_back_create(black, 100);
    turn_with_gyro_create(60, -45);
    slow_arm02(down);
    slow_hand(open,1);//the firetruck is now infront of the burning building
}
void corner_waters()
{
    slow_arm_up(arm_building);
    turn_with_gyro_create(60,45);
    create_drive_direct(100,100); //forward to position claw over waters (number to change if waters arent being grabbed)
   	msleep(300); 
    create_stop();
    slow_arm(down,1);
    slow_hand(tight,1);
    create_drive_direct(-100,-100); // w/ waters, robot backs up to prevent claw destrucking 
    msleep(700);
    create_stop();
    slow_arm_up(arm_building);
    square_up_back_create(black, 60);    
    turn_with_gyro_create(60,-45);
   	create_drive_direct(370,300); //waters move towards burning building
    msleep(700);
    create_stop();
    slow_hand(open,1); 
    shake_arm(); // waters on in the burning building 
    slow_arm(arm_building, 1);
}

void firefighter_in_burning()
{
	create_drive_direct(-300,-300); //back away from building
    msleep(600);
    create_stop();
    slow_arm(arm_firefighter, 1);
    slow_hand(closed,1); //grab ff off of ft
    slow_arm(arm_building-250,1);
	create_drive_direct(300,300); //ff above the burnign building
    msleep(700);
    create_stop(); 
    slow_hand(open,1); 
	create_drive_direct(300,300); //ft moved forward
    msleep(500);
    create_stop(); 
	create_drive_direct(-500,-500); //back up behind the black package line
    msleep(1600);
    create_stop();   
    square_up_back_create(black, 100);
	create_drive_direct(250,230); //moves to ensure create backs up to next black line 
    msleep(350);
    create_stop();     
    turn_with_gyro_create(100, 90);
    square_up_back_create(black, -100); //square up in front of non-burning building with claw towards electric lines
    
}
void transport_packages()
{
   	turn_with_gyro_create(100, 180); //turn towards building
    create_stop();
    square_up_back_create(black, 100);	
    create_stop();
    msleep(100);
    create_drive_direct(-200,-200); //backup to aline pack with opening of building
    msleep(350);
	create_stop();
    slow_hand(open,1); 
   	turn_with_gyro_create(100, -90); //turn towards packages
    create_stop();
    square_up_back_create(black, -100);	    
    msleep(100);
    turn_with_gyro_create(100, -90);
    create_stop();
    square_up_back_create(black, -100);	    
    create_line_follow(700,100); 
}
void grabbing_packages()
{
    slow_arm(down, 1);
    create_drive_direct(100,100); 
    msleep(250);
    create_stop();
    msleep(100);
    create_line_follow(325,100); //linefollow towards package 2
    create_stop();
    msleep(100);
    slow_arm(down, 1);
    slow_hand(tightish,1); //grab pack 2
    slow_arm(arm_building - 200,1);
    create_stop();
    msleep(300);
	transport_packages();
    create_stop();
    msleep(100);
    slow_arm(down, 1);
    slow_hand(tightish,1); //grab pack 3 and 4 at determined location
    slow_arm(arm_building - 200,1);
    transport_packages();
    create_stop();
    
}