#define down 2000
#define front 1850
#define closed 200
#define out 125
#define max 1500
#define hand 3
#define arm 1
#define base 0
#define arm_max 2000
#define arm_min 0
#define arm_mid 600
#define hand_max 2047 //also start
#define hand_min 0
#define hand_close 330
#define base_max 2000
#define base_min 0
#define base_start 1200
#define left 2
#define right 1
#define max 1500
#define bd_max 2047
#define bd_min 125
int in;
int between;
int up;
int mid;
int back;
int half;
int open;
int arm_building;
int tight;
int tightish;
int ajar;
int turn;
int PID;
int square;
void slow_arm02 (int x );//this funtion slows 
void slow_arm (int x,int speed);//this funtion slows
void slow_hand ( int z, int speed );//this funtion slows 
void slow_base (int x );//this funtion slows 
void start_position();
void arm_out();
void slow_base_valve();//this funtion slows
void slow_start();
void slow_base_front();
void slow_arm_up();
void slow_arm_up2();
void slow_hand_open();
void slow_hand_small_open();
void slow_arm_down();
void slow_hand_close();
void fast_hand();
void shake_arm();
void fast_arm();
int out_of_box();
int get_to_yellow();
int get_to_one();
int take_yellow();
int yellow_one();