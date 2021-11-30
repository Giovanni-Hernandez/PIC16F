#include <16f887.h>
#device adc=10
#include <stdio.h>
#fuses XT, NOWDT, NOPROTECT
#use delay(clock = 4MHZ)
#use rs232(baud = 9600, parity = N, xmit = pin_c6, rcv = pin_c7, bits = 8)
#BYTE PORTB = 0X06
#BYTE PORTD = 0X08

void leersensor1();
void leersensor2();
void encenderLED();
void apagarLED();
void secuenciaLEDs();
char dato;
float valor;

#int_rda

void rda_isr(){
   dato = getc();
   switch(dato){
      case '1':
         leersensor1();
         break;
      
      case '2':
         leersensor2();
         break;
     
     case '3':
         encenderLED();
         break;
      
     case '4':
         apagarLED();
         break;
         
     case '5':
         secuenciaLEDs();
         break;
      }
   
}


void main(){
   set_tris_d(0b11111110);
   set_tris_b(0x00); // Configura el puerto b como salida
   PORTB = 0;
   PORTD = 0;
   printf("Introduzca una opcion:\r\n");
   printf("1. Leer dato sensor 1\r\n");
   printf("2. Leer dato sensor 2\r\n");
   printf("3. Encendido LED D0\r\n");
   printf("4. Apagado LED D0\r\n");
   printf("5. Rotación ascendente y descendente LEDs\r\n");
   enable_interrupts(int_rda);
   enable_interrupts(global);
   while(true){
   
   }

}

void leersensor1(){
   setup_adc_ports(all_analog);
   setup_adc(adc_clock_internal);
   set_adc_channel(0);
   delay_us(50);
   valor = ((read_adc()*500.0)/1023.0);
   printf("El dato del sensor 1: %2.2f°C\r\n", valor);

}

void leersensor2(){
   setup_adc_ports(all_analog);
   setup_adc(adc_clock_internal);
   set_adc_channel(1);
   delay_us(50);
   valor = ((read_adc()*500.0)/1023.0);
   printf("El dato del sensor 2: %.2f°C\r\n", valor);

}

void encenderLED(){
   bit_set(PORTD,0);
   printf("El LED se encendió\r\n");
}

void apagarLED(){
   bit_clear(PORTD,0);
   printf("El LED se apagó\r\n");
}

void secuenciaLEDs(){
   unsigned char i = 0;
   for( i=0; i<9; i++){
      output_b(0x01<<i);
      delay_ms(100);
   }
   for( i=0; i<9; i++){
      output_b(0x80>>i);
      delay_ms(100);
   }
}
