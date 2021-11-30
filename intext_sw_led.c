#include<16f887.h>
#fuses xt, nowdt, noprotect
#use delay(internal = 4MHZ)

#int_ext
void interrupt(){
   output_toggle(pin_B7);
}

void main(){
   set_tris_b(0x01);
   output_low(pin_B7);
   port_b_pullups(true);
   enable_interrupts(int_ext);
   ext_int_edge(H_to_L);
   enable_interrupts(global);
   while(true){
   
   }


}
