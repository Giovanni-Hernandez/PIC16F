#include<16f877a.h>
#use delay(clock=4MHZ)
#fuses xt, nowdt, protect

#int_timer0
void timer_0(){
   output_toggle(pin_b0);
   set_timer0(6);
}

void main(){
   setup_timer_0(rtcc_internal|rtcc_div_4);
   set_timer1(6);
   enable_interrupts(int_timer0);
   enable_interrupts(global);
   while(true){
      }
}

