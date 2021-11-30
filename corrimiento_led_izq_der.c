#include<16f887.h>
#fuses MCLR, XT, NOWDT, NOPROTECT
#use delay(clock = 4M)
#byte PORTB = 0x06

void main(){
   set_tris_b(0x00); // Configura el puerto b como salida
   PORTB = 0;
   while(true){
   
      PORTB = 0X01;
      delay_ms(500);
      while(!bit_test(PORTB,7)){
         PORTB = PORTB << 1;
         delay_ms(500);
      }
      delay_ms(500);
      while(!bit_test(PORTB,0)){
         PORTB = PORTB>>1;
         delay_ms(500);
      }
   }
}
