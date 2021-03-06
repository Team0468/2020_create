#include <diagnostic.h>
//#include <create_functions.h>
#include <kipr/botball.h>


int diag_conf[6][2];
////////////////////
int diag_out[6];  //
////////////////////

///////////////////////////////
void diag_conf_setup(){
    int min=0,max=1;
    int /*SET=1 ,*/CET=2;
    
    diag_conf[CET][min]=10;
    diag_conf[CET][max]=100;
    
}
int diag_av(int port){
    int i, sum;
    while(i<10){
        i++;
        sum+=analog(port);
    }
    return sum/10;
}
///////////////////////////////
void diagnostic(){
    diag_conf_setup();//diag_out
    int i,in[6]={diag_av(0),diag_av(1),diag_av(2),diag_av(3),diag_av(4),diag_av(5)};
    
    while(i<6){
        if(in[i]>diag_conf[i][0] || in<diag_conf[i][1]){
            diag_out[i]=0;
        }else{
            diag_out[i]=1;
        }
    }
}