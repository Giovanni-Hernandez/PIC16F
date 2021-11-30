#include<16f877a.h>
#use delay(clock=4MHZ)
#fuses xt, nowdt, protect

#int_timer1
void timer_1(){
   output_toggle(pin_b0);
   set_timer1(65286);
}

void main(){
   setup_timer_1(T1_internal|T1_div_by_2);
   set_timer1(65286);
   enable_interrupts(int_timer1);
   enable_interrupts(global);
   while(true){
      }
}

