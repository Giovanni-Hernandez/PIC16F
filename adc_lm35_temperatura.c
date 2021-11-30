#include <16f887.h>
#device adc = 10;
#include <stdio.h>
#fuses XT, NOWDT, NOPROTECT
#use delay(internal= 4MHZ)
#use rs232(baud = 9600, parity = N, xmit = pin_c6, rcv = pin_c7, bits = 8)

void main(){
   int16 datoS1, datoS2, datoS3;
   float VS1, VS2, VS3, TS1, TS2, TS3;
   
   set_tris_a(0x07); // 0000 0111 RA0, RA1, RA2 como entradas
   setup_adc_ports(all_analog); // Entrada analógica
   setup_adc(adc_clock_internal);
   
   while(true){
      set_adc_channel(0); // Canal a utilizar por la funcion
      delay_ms(500);
      datoS1 = read_adc();
      set_adc_channel(1);
      delay_ms(500);
      datoS2 = read_adc();
      set_adc_channel(2);
      delay_ms(500);
      datoS3 = read_adc();
      
      VS1 = (datoS1 * 5.0) / 1023.0;
      TS1 = VS1 * 100.0;
      printf("--SENSOR1--\r\n");
      printf("Lectura en LSB: %4Ld\r\n", datoS1);
      printf("Valor en voltaje: %0.2f\r\n", VS1);
      printf("T1: %0.2f °C\r\n", TS1);
      
      printf("\r\n--SENSOR2--\r\n");
      VS2 = (datoS2 * 5.0) / 1023.0;
      TS2 = VS2 * 100.0;
      printf("Lectura en LSB: %4Ld\r\n", datoS2);
      printf("Valor en voltaje: %0.2f\r\n", VS2);
      printf("T2: %0.2f °C\r\n", TS2);
      
      printf("\r\n--SENSOR3--\r\n");
      VS3 = (datoS3 * 5.0) / 1023.0;
      TS3 = VS3 * 100.0;
      printf("Lectura en LSB: %4Ld\r\n", datoS2);
      printf("Valor en voltaje: %0.2f\r\n", VS2);
      printf("T3: %0.2f °C\r\n\r\n", TS3);
      
      printf("\r\n--PROMEDIO TEMPERATURA--\r\n");
      printf("TP: %.2f °C\r\n\r\n",((TS1+TS2+TS3)/3));
      
      delay_ms(3000);
      
   }

}
