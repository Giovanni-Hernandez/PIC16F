#include<16f877a.h>
#device ADC=10
#fuses XT, NOWDT, NOPROTECT, NOLVP, PUT, BROWNOUT
#use delay(clock = 4MHz)
#use RS232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8)

float distancia, tiempo;
#define trigger pin_B1
#define echo pin_B0

void main(){
   setup_timer_1(T1_internal|T1_div_by_1);
   while(true)
   {
      output_high(trigger);
      delay_us(10);
      output_low(trigger);
      
      while(!input(echo));
      set_timer1(0);
      
      while(input(echo));
      tiempo = get_timer1();
      distancia = (tiempo/2)*(0.0343);
      
      printf("\rDistancia = %f", distancia);
      printf("\rTiempo = %f", tiempo);
      
      delay_ms(500);
   }


}
