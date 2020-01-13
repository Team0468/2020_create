#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>

int main()
{
    create_connect();
    slow_arm(arm_start,5);
    slow_hand(closed,60);
    slow_base(back);
    while(right_button() != 1){}
    start_position();
    create_stop();
    msleep(3000);//waitforlight
    create_stop();
	towards_firetruck();
    at_firetruck();
    transport_firetruck();
	corner_waters();
   	firefighter_in_burning();
	grabbing_packages();
    
      
    create_disconnect();
   return 0; 
}    