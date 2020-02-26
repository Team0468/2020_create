#include <kipr/botball.h>
#include <create_comp_lib.h>
#include <create_functions.h>
#include <ross.h>
#include <reece.h>
#include <filter.h>
int clone_arm = 1;
int clone_base = 0;
int clone_hand = 3;
int clone_up = 1000;
int clone_down = 1990;
int clone_closed = 200;
int clone_open = 2000;
int clone_grab = 250;
int i = 0;

int reece()
{
    thread sweep_mepersons;
    thread handstend;
    thread raise_arm;
    thread open_claw;
    open_claw = thread_create(claw_open);
    raise_arm = thread_create(arm_raise);
    handstend = thread_create(hand_extend);
    sweep_mepersons = thread_create(arm_sweep);
    create_connect();
    calibrate_gyro();

    servo(clone_base,1150,2);
    msleep(1000);
    servo(clone_arm,clone_down-20,2);  //set up
    msleep(1000);
    servo(clone_hand,clone_open,2);
    msleep(1000);



    PID_gyro_drive_create(200,2); 
    turn_with_gyro_create(200,-90);   //go toward mepersons
    square_up_front_create(1,200);
        thread_start(raise_arm);
    turn_with_gyro_create(200,90);
    create_stop();

    PID_gyro_drive_create(-160,0.2);
    create_stop();//perfect stuff
    if(1 == 0){alternate();}
    else{
        turn_with_gyro_create(100,-45);
        PID_gyro_drive_create(100,.85);
        create_stop();
        thread_start(sweep_mepersons);
        turn_with_gyro_create(40,90);  //sweep action
        create_stop();


        servo(clone_arm,clone_down-150,2); //lower arm
        thread_start(open_claw);
        create_stop();

        create_drive_direct(-100,100);////////////////////////////////
        msleep(400);                                                //
        create_stop();                                              //
                      PID_gyro_drive_create(-100,1);
                      create_stop();
        servo(clone_arm,clone_down+100,2); //arm for scoop          //
        create_stop();                                              //  first scoop
        PID_gyro_drive_create(100,3);                               //
        thread_start(handstend);                                   //
        turn_with_gyro_create(100,-180);                            // 
        create_drive_direct(100,97);                               //
        msleep(2700);        ///////////////////////////////////////
        create_stop();
        
        
        servo(clone_arm,clone_down-200,2);//////////////////
        create_stop();                                    //
        turn_with_gyro_create(100,-180);                   //
        create_stop();                                     //
       // create_drive_direct(100,-100);                   //
       // msleep(150);                                    //
        create_stop();                                    //      second scoop
        servo(clone_hand,clone_closed,2);                    //
        servo(clone_arm,clone_down+100,2);                   //
        PID_gyro_drive_create(100,.6);                    //
        turn_with_gyro_create(100,90);                    //
        turn_with_gyro_create(100,45);                    //
        create_drive_direct(80,-80);                    //
        msleep(650);//////////////////////////////////////////
        create_stop();
    }


    create_disconnect();
    
    thread_destroy(open_claw);
    thread_destroy(raise_arm);
    thread_destroy(handstend);
    thread_destroy(sweep_mepersons);
    return 0;
}

void arm_sweep()
{
    msleep(110);
    servo(clone_hand,clone_closed+1000,4);
    msleep(500);
    servo(clone_hand,clone_closed,3);    
}
void hand_extend()
{
    msleep(600);
    servo(clone_hand,clone_open-1000,2);
}
void arm_raise()
{
     servo(clone_arm,clone_up+70,4); 
     servo(clone_hand,clone_closed,4);  
}
void claw_open()
{
  servo(clone_hand,clone_open,3);  
}
int reece2()
{
    /////////////////////////////////////////////////////////////////////
    //threads that run to set claw into postion for reece() procedure  //
    reece_base=thread_create(base_reece);                          //
    reece_arm=thread_create(arm_reece);                            //
    reece_hand=thread_create(hand_reece);                          //
    /////////////////////////////////////////////////////////////////////
    //thread sweep_mepersons; 1.1 3.63
    //sweep_mepersons = thread_create(arm_sweep);
    //servo(clone_hand,clone_closed,2);
    create_connect();
    calibrate_gyro();
    //servo(clone_hand,clone_open,2);
    thread_start(reece_arm);
    thread_start(reece_hand);
    thread_start(reece_base);

    //servo(clone_base,1150,2);
    //msleep(1000);
    //servo(clone_arm,clone_down,2);  //set up
    //msleep(1000);
    //servo(clone_hand,clone_open,2);
    //msleep(1000);



    PID_gyro_drive_create(200,2); 
    turn_with_gyro_create(200,-90);   //go toward mepersons
    square_up_front_create(1,200);
    msleep(500);
    PID_gyro_drive_create(76.2,1);
    turn_with_gyro_create(200,90);

    servo(clone_arm,clone_up+50,2);
    PID_gyro_drive_create(-160,0.2);
    //servo(clone_hand,clone_closed,2);
    msleep(1000);
    PID_gyro_drive_create(57.15,2.2);
    msleep(750);
    reece2_meeple_grab();
    reece2_meeple_grab();
    create_stop();

    return 0;
}

void reece2_meeple_grab(){
    create_drive_direct(-20,-20);
    servo(clone_hand,clone_closed,2);
    create_stop();//perfect stuff
    PID_gyro_drive_create(-150,1);
    servo(clone_arm,clone_down,2);
    servo(clone_hand,clone_open,2);
    servo(clone_arm,clone_up,2);
    PID_gyro_drive_create(100.3,2);

}
void base_reece()
{
    msleep(200);
    servo(clone_base,1150,2);
}
void arm_reece(){ servo(clone_arm,clone_up+50,2);}
void hand_reece(){servo(clone_hand,clone_open,2);}