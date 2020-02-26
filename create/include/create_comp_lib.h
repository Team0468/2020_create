void move(int l_speed,int r_speed);
int white;
int black;
int physical;
int black_speed;
void square_up(int ending,int speed);
double bias;
double avg;
double calibrate_gyro();
void drive_with_gyro(int speed, double time);
void PID_gyro_drive(int speed, double time);
void turn_with_gyro_create(int speed, int deg);
void turn_with_gyro(int speed, int deg);
void PID_gyro_drive_create(int speed, double time);
void square_up_front_create(int ending,int speed);
void linefollow_create(double time, int speed, int side); //time in seconds (must have create_stop(); right after)
void square_up_back_create(int ending,int speed);
void turn_90();
void reach_material();
void create_line_follow();
void create_line_follow_materials();
void bang();
void back_til_black();
void one_wheel_turn();
void short_pause();
void triple_square();
void square_up_lblack_rwhite_create();
void square_up_rblack_lwhite_create();
void straight_distance(double distance, double base_speed);
void turn_create(int deg);
void PID_gyro_drive_create_et(int speed, int buff);