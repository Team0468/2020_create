thread af_zero,af_one,af_two,af_three,af_three,af_four,af_five;

int filt_distribute;
float filter_out[6];
const int a_filter_ports[6];
int cet,CET_conf[4];

void moving_win();
void csf_threads();
void kf_threads();

int buffer(int port);
int i;
int sum;
int average;

int cet_out,cet_conf[4];