#include<16f877a.h>
#device ADC=10
#fuses XT, NOWDT, NOPROTECT, NOLVP, PUT, BROWNOUT
#use delay(clock = 4MHz)
#use RS232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8)

float distancia, tiempo;
#define trigger pin_B1
#define echo pin_B0

int Timer2, postcaler;

void main(){

   setup_adc_ports(all_analog);
   setup_adc(adc_clock_internal);
   Timer2 = 249;
   Postcaler = 1;
   setup_ccp1(ccp_pwm);
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
      
      set_pwm1_duty(distancia*1023/200); //Se toman 1023bit de la resolucion max con 400mts
      
      
      printf("\rDistancia = %f", distancia);
      printf("\rTiempo = %f", tiempo);
      
      delay_ms(500);
   }


}
