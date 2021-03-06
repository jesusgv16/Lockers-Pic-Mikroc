/************------------------*******************/
  #define M1 PORTB.F1
  #define M2 PORTB.F2
  #define M3 PORTB.F3
  #define M4 PORTB.F4
  #define M5 PORTB.F5
  #define M6 PORTB.F6
  #define M7 PORTB.F7
  #define M8 PORTE.F2
  #define M9 PORTE.F3
/************------------------*******************/
  #define S1 PORTC.F0
  #define S2 PORTC.F1
  #define S3 PORTC.F2
  #define S4 PORTC.F4
  #define S5 PORTC.F5
  #define S6 PORTC.F6
  #define S7 PORTC.F7
  #define S8 PORTE.F0
  #define S9 PORTE.F1
/************------------------*******************/

extern char kp;
extern int tecla;
int temp; //variable temporal que almacena la contraseña
int  n_aleatorio;

extern char fija[7]=" ",fija1[7]=" ", fija2[7]=" ", fija3[7]=" ", fija4[7]=" ", fija5[7]=" ", fija6[7]=" ", fija7[7]=" ", fija8[7]=" ", fija9[7]=" ";

// LCD module connections
sbit LCD_RS at RA0_bit;
sbit LCD_EN at RA1_bit;
sbit LCD_D4 at RA2_bit;
sbit LCD_D5 at RA3_bit;
sbit LCD_D6 at RA4_bit;
sbit LCD_D7 at RA5_bit;

sbit LCD_RS_Direction at TRISA0_bit;
sbit LCD_EN_Direction at TRISA1_bit;
sbit LCD_D4_Direction at TRISA2_bit;
sbit LCD_D5_Direction at TRISA3_bit;
sbit LCD_D6_Direction at TRISA4_bit;
sbit LCD_D7_Direction at TRISA5_bit;
// End LCD module connections


char  keypadPort at PORTD;

int teclado(){
    kp = 0;
    do{
      // kp = Keypad_Key_Press();
      kp = Keypad_Key_Click();
    }while (!kp);

    switch (kp) {
      case  1: kp = '1'; break; // 1
      case  2: kp = '2'; break; // 2
      case  3: kp = '3'; break; // 3
      case  4: kp = 'A'; break; // A
      case  5: kp = '4'; break; // 4
      case  6: kp = '5'; break; // 5
      case  7: kp = '6'; break; // 6
      case  8: kp = 'B'; break; // B
      case  9: kp = '7'; break; // 7
      case 10: kp = '8'; break; // 8
      case 11: kp = '9'; break; // 9
      case 12: kp = 'C'; break; // C
      case 13: kp = '*'; break; // *
      case 14: kp = '0'; break; // 0
      case 15: kp = '#'; break; // #
      case 16: kp = 'D'; break; // D
    }
    return kp;
}
int teclados(){
    kp = 0;
    do{
      // kp = Keypad_Key_Press();
      kp = Keypad_Key_Click();
    }while (!kp);

    switch (kp) {
      case  1: kp = '1'; break; // 1
      case  2: kp = '2'; break; // 2
      case  3: kp = '3'; break; // 3
      case  4: kp = 'A'; break; // A
      case  5: kp = '4'; break; // 4
      case  6: kp = '5'; break; // 5
      case  7: kp = '6'; break; // 6
      case  8: kp = 'B'; break; // B
      case  9: kp = '7'; break; // 7
      case 10: kp = '8'; break; // 8
      case 11: kp = '9'; break; // 9
      case 12: kp = 'C'; break; // C
      case 13: kp = '*'; break; // *
      case 14: kp = '0'; break; // 0
      case 15: kp = '#'; break; // #
      case 16: kp = 'D'; break; // D
    }
    return kp;
}


void menu_p(){
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_out(1,1,"Select a locker");
     Lcd_Out(2,1,"to open: '1-9'");

}


void delay1(){
  delay_ms(20);
  }

void delay2(){
  delay_ms(2000);
  }

void vacio(){
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_out(1,1,"Locker vacio");
    delay_ms(400);
    menu_p();
}





int password(){ //funcion para generacion de la contraseña
    n_aleatorio = rand()%(90000)+10000;//Numero aleatorio entre 99999 y 10000
      if (n_aleatorio<0) //se asegura de que no alla numeros negativos
      {
       n_aleatorio=n_aleatorio*(-1);
      }
  }

void contras(){

temp=password();
    intToStr(temp,fija1);
    Lcd_out(1,1,"Pass1:");
    Lcd_out(2,1,fija1);
    delay1();
temp=password();
    intToStr(temp,fija2);
    Lcd_out(1,1,"Pass2:");
    Lcd_out(2,1,fija2);
    delay1();
temp=password();
    intToStr(temp,fija3);
    Lcd_out(1,1,"Pass3:");
    Lcd_out(2,1,fija3);
    delay1();
temp=password();
    intToStr(temp,fija4);
    Lcd_out(1,1,"Pass4:");
    Lcd_out(2,1,fija4);
    delay1();
temp=password();
    intToStr(temp,fija5);
    Lcd_out(1,1,"Pass5:");
    Lcd_out(2,1,(fija5));
    delay1();
temp=password();
    intToStr(temp,fija6);
    Lcd_out(1,1,"Pass6:");
    Lcd_out(2,1,fija6);
    delay1();
temp=password();
    intToStr(temp,fija7);
    Lcd_out(1,1,"Pass7:");
    Lcd_out(2,1,fija7);
    delay1();
temp=password();
    intToStr(temp,fija8);
    Lcd_out(1,1,"Pass8:");
    Lcd_out(2,1,fija8);
    delay1();
temp=password();
    intToStr(temp,fija9);
    Lcd_out(1,1,"Pass9:");
    Lcd_out(2,1,fija9);
    delay1();

}
