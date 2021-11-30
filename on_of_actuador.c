#include <16f887.h>
#device adc = 10;
#use delay(internal= 4MHZ)
#include <stdio.h>
#include <lcd.c>
#fuses XT, NOWDT, NOPROTECT
#define T1 25
#define T2 35
#BYTE PORTA = 0X05
#BYTE PORTB = 0X06
#BYTE PORTD = 0X08

void main(){
   int16 datoS1, datoS2;
   float TS1, TS2;
   
   set_tris_a(0x03); // 0000 0011 RA0, RA1 como entradas
   set_tris_b(0b11111100);  // RB0 Y RB1 como salidas
   set_tris_d(0x00);
   PORTB = 0; //Comienza con todos los motores apagados
   setup_adc_ports(all_analog); // Entrada analógica
   setup_adc(adc_clock_internal);
   
   lcd_init();
   lcd_gotoxy(4,1);
   lcd_putc("BIENVENIDO");
   lcd_gotoxy(5,2);
   lcd_putc("GIO HDEZ");
   delay_ms(2000);
   lcd_putc("\f");
   
   
   while(true){
      
      set_adc_channel(0); // Canal a utilizar por la funcion
      delay_ms(100);
      datoS1 = read_adc();
      set_adc_channel(1);
      delay_ms(100);
      datoS2 = read_adc();
    
      
      TS1 = ((datoS1 * 5.0) / 1023.0)*100;
      TS2 = ((datoS2 * 5.0) / 1023.0)*100;

      lcd_gotoxy(1,1);
      printf(lcd_putc, "TSensor1:%.2fC",TS1);
      lcd_gotoxy(1,2);
      printf(lcd_putc, "TSensor2:%.2fC",TS2);
      if(BIT_TEST(PORTA,0)){
      lcd_gotoxy(11,1);
      printf(lcd_putc, "%.2fC",TS1);
      }
      if(BIT_TEST(PORTA,1)){
      lcd_gotoxy(11,2);
      printf(lcd_putc, "%.2fC",TS2);
      }

      if(TS1 >= T1){
         if(TS2 >= T2){
            output_b(0x03); // Los dos motores se encienden
         }else{
            output_b(0x01); // El motor del sensor 1 se enciende y el del motor 2 se apaga
         }
      }else{
         if(TS2 < T2){
            output_b(0x00); // Los dos motores se apagan
         }else{
            output_b(0x02); // El motor del sensor 2 se enciende y el motor 1 se apaga
         }
      }
     
     
      
      
   }

}
