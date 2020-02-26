thread reece_base;
thread reece_arm; 
thread reece_hand;
void base_reece(); 
void arm_reece(); 
void hand_reece();//married to above threads
int reece();
int clone_arm;
int clone_base;
int clone_hand;
int clone_up;
int clone_down;
int clone_closed;
int clone_open;
int clone_grab;
int i;
int reece2();

void reece2_meeple_grab();
void drive_for_distance(int distance);
void arm_sweep();
void hand_extend();
void arm_raise();
void claw_open();
 /*
    servo(clone_hand,clone_closed,2);
    servo(clone_arm,clone_up-90,2);


    turn_with_gyro_create(25,45);
    servo(clone_arm,clone_down-200,2);
    servo(clone_hand,clone_grab,2);      //drop meperson
    servo(clone_hand,clone_open,2);

    servo(clone_arm,clone_down+200,2);
    create_stop();
    PID_gyro_drive_create(100,1.5);
    turn_with_gyro_create(100,-45);
    PID_gyro_drive_create(100,1);
    turn_with_gyro_create(40,-180);
    turn_with_gyro_create(50,45);
    PID_gyro_drive_create(200,1);
    */