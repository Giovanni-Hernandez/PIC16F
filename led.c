#include<16F887.h>
#fuses MCLR, INTRC_IO, NOWDT
#use delay(clock = 4M)

void main(){
   output_b(0x00);
   while(TRUE){
      output_high(PIN_B0);
      delay_ms(500);
      output_low(PIN_B0);
      delay_ms(500);
   }
}
