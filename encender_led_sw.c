#include<16f887.h>
#use DELAY(CLOCK = 4M)
#fuses XT, NOPROTECT, NOWDT
#DEFINE SW PORTA, 1  //ENTRADAS -> 1
#DEFINE LED PORTB, 0 // SALIDAS -> 0
#BYTE PORTA = 0X05
#BYTE PORTB = 0X06

void main(){
   Set_Tris_A(0b00000010); // Se indica que el bit 1 del puerto A se configura como entrada
   Set_Tris_B(0b11111110); // Se indica que el bit 0 del puerto B se configura como salida
   while(true){
   
      if(bit_test(SW)){ // Si SW está activado
         bit_set(LED); // Encienda el LED
      }
      
      else{
         Bit_clear(LED); // Apaga el LED
      } 
   }
}
