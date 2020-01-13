/*#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>

// turn 150 // square 250 // PID 150

// ----------------- //
thread baseback;     //  - DECLARE NAME OF THREADS.
thread basefront;    //
thread basehalf;     //
thread handopen;     //
thread armdown;      //
thread handclose;    //
thread handhalf;     //
thread armup;        //
thread armbuilding;  //
thread armwater;     //
// ----------------- //

int main()
{    

    // ---------------------------------------------- //
    baseback = thread_create(slow_base_valve);        //  - ASSIGN THREADS TO SPECIFIC FUNCTIONS.
    basefront = thread_create(slow_base_front);       //
    basehalf = thread_create(slow_base_half);         //
    handopen = thread_create(slow_hand_open);         //
    armdown = thread_create(slow_arm_down);           //
    handclose = thread_create(slow_hand_close);       //
    handhalf = thread_create(slow_hand_small_open);   //
    armup = thread_create(slow_arm_up);               //
    armbuilding = thread_create(slow_arm_building);   //
    armwater = thread_create(slow_arm_water);         //
    // ---------------------------------------------- //

    // -------------- //
    fast_bd(between); //
    fast_arm(mid);    //  - PREPARE SERVOS TO FIT IN START BOX.
    fast_hand(open);  //  - ALSO INCLUDES SHORT PAUSE BEFORE RUN.
    fast_base(back);  //  - PAUSE WILL BE REPLACED WITH WAITFORLIGHT.
    fast_bd(in);      //
    create_stop();    //
    msleep(2000);     //
	// -------------- //
    
    calibrate_gyro();
    create_connect();
    msleep(30);
    create_full();
    //wait_for_light();

    // --------------------------------- //
    thread_start(basefront);             //  - CODE TO EXIT START BASE.
    fast_bd(between);                    //
    square_up_back_create(white, -250);  //  - PICKS UP FIRST SET OF PACKAGES.
	PID_gyro_drive_create(-150,0.45);    //  - PREPARE FOR CAMERA READ.
    thread_start(handhalf);              //
    short_pause();                       //
    turn_with_gyro_create(175, -90);     //
    thread_start(armwater);              //
    PID_gyro_drive_create(-200,0.8);     //  # Physical square up.
    msleep(15);                          //
    PID_gyro_drive_create(225, 0.65);    //
	fast_hand(tight);                    //
    fast_arm(arm_water-125);             //
    PID_gyro_drive_create(150,0.525);    //  # Moves water off packages.
    fast_hand(ajar);                     //
    PID_gyro_drive_create(-150,0.55);    //  ** THIS VALUE HAS SEEN NUMEROUS CHANGES. **
    fast_arm(down-50);                   //
    fast_hand(tight);                    //  # Grabs packages.
    short_pause();                       //
    thread_start(armup);                 //
    square_up_front_create(white,250);   //  # Square up on main line.
    square_up_back_create(white,250);    //  # Prepare for camera read.
    // --------------------------------- //
    
    // --------------------------------- //
    turn_with_gyro_create(175,-90);      //  - START OF BURNING BUILDING = 1.
    short_pause();                       //  - DROPS PACKAGES IN THE SECOND BUILDING.
    PID_gyro_drive_create(200,0.9);      //
    square_up_back_create(black,250);    //
    PID_gyro_drive_create(-150,0.4);     //
    thread_start(armbuilding);           //
    turn_with_gyro_create(175,45);       //
    PID_gyro_drive_create(150,0.6);      //
    fast_hand(ajar);                     //  # Places packages in building 2 for 50 points.
    // --------------------------------- //
    
    // --------------------------------- //
    PID_gyro_drive_create(-175,0.55);    //  - MOVES TO GRAB SECOND SET OF PACKAGES.
    turn_with_gyro_create(175,-45);      //  - GRABS PACKAGES AND PUTS THEM IN SECOND BUILDING.
    short_pause();                       //
    square_up_front_create(white,250);   //
    short_pause();                       //
    thread_start(handhalf);              //
    PID_gyro_drive_create(-250,0.2);     //
    one_wheel_turn(500);                 //
    short_pause();                       //
    PID_gyro_drive_create(-250,0.15);    //
    square_up_back_create(white,250);    //
    short_pause();                       //
    turn_with_gyro_create(175,90);       //
    short_pause();                       //
    fast_arm(arm_water+15);              //
    msleep(400);                         //
	fast_hand(tight);                    //
    fast_arm(arm_water-75);              //  # Move water to side.
    turn_with_gyro_create(175,-45);      //
    fast_hand(ajar+400);                 //
    turn_with_gyro_create(175,45);       //
    fast_arm(down-35);                   //  # Grab packages.
    msleep(400);                         //
    fast_hand(tight);                    //
    thread_start(armbuilding);           //
    PID_gyro_drive_create(300,1.1);      //
    short_pause();                       //
	turn_with_gyro_create(175,90);       //
    square_up_back_create(black,-250);   //
    short_pause();                       //
    PID_gyro_drive_create(175,0.40);     //
    short_pause();                       //
    turn_with_gyro_create(175,90);       //
    fast_bd(out);                        //  # Bulldozes waters to one pile.
    PID_gyro_drive_create(300,1.00);     //
    square_up_back_create(black,250);    //
    PID_gyro_drive_create(-175,0.15);    //
    fast_bd(between);                    //  # Brings bulldozer back up.
    one_wheel_turn(500);                 //
    square_up_back_create(white,350);    //
    short_pause();                       //
    turn_with_gyro_create(250,-90);      //
    short_pause();                       //
    square_up_back_create(black,300);    //
    PID_gyro_drive_create(-150,0.4);     //
    turn_with_gyro_create(175,45);       //
    PID_gyro_drive_create(150,0.75);     //  ** CHANGED 0.6 TO 0.75 **
    fast_hand(ajar);                     //  # Places packages in building 2 for 50 points.
    // --------------------------------- //
    
    // --------------------------------- //
    PID_gyro_drive_create(-175,0.55);    //  - Backs up to grab waters.
    turn_with_gyro_create(175,-45);      //  - Scores 50-62.5% of waters.
    short_pause();                       //
    square_up_front_create(white,250);   //
    square_up_back_create(black,250);    //
    short_pause();                       //
    PID_gyro_drive_create(-175,0.35);    //
    thread_start(handhalf);              //
    short_pause();                       //
    turn_with_gyro_create(175,90);       //
    short_pause();                       //
    PID_gyro_drive_create(-175,0.15);    //
    fast_arm(down);                      //  # Grab water pile.
    msleep(400);                         //
    fast_hand(closed+400);               //
    PID_gyro_drive_create(175,0.15);     //
    fast_hand(tight);                    //
    PID_gyro_drive_create(-175,0.15);    //
    thread_start(armbuilding);           //
	create_stop();                       //
    msleep(500);                         //
    turn_with_gyro_create(200,-90);      //
    short_pause();                       //
    triple_square();                     //
    PID_gyro_drive_create(-175,0.40);    //
    short_pause();                       //
    turn_with_gyro_create(125,01);       //
    create_stop();                       //
    msleep(600);                         //
    fast_hand(ajar);                     //  # Drop waters in building 1 for (average of) 80 points [+10].
    arm_building = arm_building-50;      //
    // --------------------------------- //
    
    // --------------------------------- //
    thread_start(basehalf);              //  - This set scores the firetruck, picking up from dropping waters.
    turn_with_gyro_create(-125,01);      //
    thread_start(armup);                 //
    square_up_back_create(black,250);    //
    thread_start(handopen);              //
    bang();                              //
    PID_gyro_drive_create(-150,0.15);    //
    short_pause();                       //
    turn_with_gyro_create(175,-90);      //
    thread_start(basefront);             //
    fast_arm(down);                      //  # Movements to avoid firefighter tube.
    fast_hand(tight);                    //
    thread_start(basehalf);              //
    fast_arm(up);                        //
    short_pause();                       //
    turn_with_gyro_create(175,90);       //
    short_pause();                       //
    square_up_front_create(back,-250);   //
    thread_start(armbuilding);           //
    PID_gyro_drive_create(-275,1.25);    //
    fast_base(front);                    //
    fast_arm(down);                      //  # Places firetruck for 50 points.
    fast_hand(ajar);                     //
    fast_arm(arm_building);              //
    // --------------------------------- //
    
    // --------------------------------- //
	triple_square();                     //  - This set scores the "super package."
    one_wheel_turn(500);                 //  - "Super package" should be prepared by the other robot.
    short_pause();                       //
    PID_gyro_drive_create(-250,0.15);    //
    thread_start(handopen);              //
    square_up_back_create(white,250);    //
    short_pause();                       //
    turn_with_gyro_create(175,90);       //
    thread_start(armdown);               //
    short_pause();                       //
    PID_gyro_drive_create(250,1.72);     //
    fast_hand(tight);                    //  # Grabs "super package."
    thread_start(armbuilding);           //
    one_wheel_turn(500);                 //
    PID_gyro_drive_create(-250,0.25);    //
    square_up_back_create(white,250);    //
    short_pause();                       //
    turn_with_gyro_create(175,90);       //
    short_pause();                       //
    PID_gyro_drive_create(175,0.5);      //
    triple_square();                     //
    short_pause();                       //
    PID_gyro_drive_create(-150,0.45);    //
    turn_with_gyro_create(175,45);       //
    PID_gyro_drive_create(150,0.76);     //  
    fast_hand(ajar);                     //  # Places "super package" in building 2 for 100 points.
    fast_arm(up);                        //
    // --------------------------------- //
    
    // --------------------------------- //
    PID_gyro_drive_create(-175,0.65);    //  - This set scores the ambulance.
    turn_with_gyro_create(175,-45);      //  - Firefighter is ignored for now.
    short_pause();                       //
    square_up_front_create(white,250);   //
    short_pause();                       //
    one_wheel_turn(500);                 //
    PID_gyro_drive_create(-250,0.15);    //
    square_up_back_create(white,250);    //
    short_pause();                       //
    thread_start(handopen);              //
    thread_start(armbuilding);           //
    turn_with_gyro_create(175,90);       //
    short_pause(); short_pause();        //
    PID_gyro_drive_create(200,0.8);      //
    short_pause();                       //
    turn_with_gyro_create(150,45);       //
    fast_arm(down);                      //
    
    
    
    create_safe();
    msleep(30);
    create_disconnect();

    // ------------------------- //
    thread_destroy(baseback);    //  - ENDS ALL OF THE THREADS.
    thread_destroy(basefront);   //
    thread_destroy(basehalf);    //
    thread_destroy(handopen);    //
    thread_destroy(armdown);     //
    thread_destroy(handclose);   //
    thread_destroy(handhalf);    //
    thread_destroy(armup);       //
    thread_destroy(armbuilding); //
    thread_destroy(armwater);    //
    // ------------------------- //

    return 0;
}*/