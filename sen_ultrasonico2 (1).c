#include <16f877a.h>
#device adc=10
#include <stdio.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT
#use DELAY (CLOCK=4MHz)
#use rs232 (baud=9600,parity=N,xmit=pin_c6,rcv=pin_c7,bits=8)

float distancia,tiempo;
#define trigger pin_B1
#define echo pin_B0

int Timer2,Postcaler;
int16 duty;

void main(){
   setup_timer_1(T1_internal|T1_div_by_1);
   Timer2=249;
   Postcaler=1;
   setup_timer_2(t2_div_by_16,Timer2,Postcaler);
   setup_ccp1(ccp_pwm);
   while(true){
      output_high(trigger);
      delay_us(10);
      output_low(trigger);
      
      while(!input(echo));
      set_timer1(0);
      
      while(input(echo));
      tiempo = get_timer1();
      distancia=(tiempo/2)*(0.0343);
      
      duty = distancia*1023/400; //Se toman 1023bit de la resolucion max con 400mts
      set_pwm1_duty(duty);
      
      printf("\rDistancia = %f",distancia);
      printf("\rTiempo = %f",tiempo);
      
      delay_ms(500);
   }
}
