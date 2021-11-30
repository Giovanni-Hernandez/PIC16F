#include<16f887.h>
#fuses xt, nowdt, noprotect
#use delay(clock = 4M)
#byte PORTB = 0x06

int8 i;
void main(){
   set_tris_b(0x00); // Configura el puerto b como salida
   PORTB = 0;
   while(true){
  
   for(i=0;i<9;i++){
      output_b(0x01<<i); // Enciende el bit 0, luego bit 1, luego bit 2,..., hasta bit 8
      delay_ms(500); // Retardo en ms 
      }
   }
}
