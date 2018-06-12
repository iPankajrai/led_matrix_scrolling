//#include<ilibrary/matrix.h>
#include<avr/io.h>
#define F_CPU 1600000UL
#include<util/delay.h>
unsigned char row[8]= { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void a()
{
 unsigned char clm[8]= {0xBD,0xBD,0xBD,0x81,0xBD,0xBD,0xDB,0xE7};
 for(int k=0;k<8;k++){
  for (int j=0; j<500; j++)
  {  for(int i=0; i<8; i++)
      {PORTB= row[i];
	   PORTA= ~((~clm[i])<<k);
	   PORTA|= ~(255<<k);
	   _delay_ms(1);}
   }
   }
   PORTB= 0b00000000;
   PORTA= 0b11111111;
   _delay_ms(200);
}

void main()
{DDRB=0b11111111;
DDRA= 0b11111111;

while(1)
{

/*for (int i=0; i<8; i++)
 {
   PORTB=(0b00000001<<i);
   
   PORTA= value[i];
   _delay_ms(1);
  }*/
  a();

}
}
