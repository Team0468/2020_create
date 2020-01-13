/*#define hand 3
#define arm 2
#define base 0
#define arm_max 1125
#define arm_min 400
#define arm_mid 525
#define hand_max 2047 //also start
#define hand_min 0
#define base_max 1500
#define base_min 0
#define base_start 150
#define left 2
#define right 1*/

#define down 2000
#define front 1850
#define closed 200
#define out 125

#define max 1500

//int out;
int in;
int between;
int up;
int arm_firefighter;
int arm_water;
int arm_building;
int arm_start;
//int down;
int mid;
//int front;
int back;
int half;
int open;
//int closed;
int firetruck;
int hand_valve;
int tight;
int tightish;
int ajar;

int turn;
int PID;
int square;

int check_building_one();
void slow_arm02 (int x );//this funtion slows 
void slow_arm (int x,int speed);//this funtion slows
//void slow_hand (int x );//this funtion slows 
void slow_hand ( int z, int speed );//this funtion slows 
void slow_base (int x );//this funtion slows 
void start_position();
void arm_out();
void slow_base_valve();//this funtion slows
void slow_start();
void slow_base_front();
void slow_arm_pre_valve();
void slow_arm_up();
void slow_arm_up2();
void slow_hand_open();
void slow_hand_small_open();
void slow_arm_down();
void slow_hand_close();
/*void short_pause();*/
void slow_arm_bucket();
void fast_hand();
void shake_arm();
void grab_water();
void pile_water();
void push_water();
void recover_water();
void first_water();
void all_water();
//void first_water_down();
//void all_water_drop();
//void shake_arm_bucket();
void fast_arm();
void slow_arm_building();
void slow_arm_water();
void fast_bd();
void fast_base();
void slow_base_half();
void towards_firetruck();
void at_firetruck();
void transport_firetruck();
void corner_waters();
void firefighter_in_burning();
void transport_packages();
void grabbing_packages();