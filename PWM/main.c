/*
 * main.c
 *
 *  Created on: Dec 23, 2019
 *      Author: marof
 */
#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000UL
uint8_t sine_wave[256] = {
0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC,
0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D
};

int main(void)
{
DDRB|=(1<<PB2)|(1<<PB1);//OC1A and OC1B as output
int i=5;
int j=5;

//Setup 10bit Fast PWM Mode 7
// WGM13=0, WGM12=1, WGM11=0, WGM10= 1 is for fastPWM in 8bit mode.
// Here TOP= 0x03FF or 1023
// For more information 2313 datasheet table 46 pg 106
OCR1B = 0;
TCCR1B|=(1<<WGM12);
TCCR1A|=(1<<COM1A1)|(0<<COM1A0)|(1<<COM1B1)|(0<<COM1B0)|(0<<WGM11)|(1<<WGM10);


//COM1A1:COM1A0 =10 COM1B1:COM1B0 =10 and for Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at TOP
//For more information 2313 datasheet table 44 pg 104
// PWM_Frequency= F_osc / (PreScaler*(1+TOP))= 16MHz / (1*(1023+1))= 15625 = 15.63 KHz
// Resolution= log(TOP+1)/log(2)= 10 bit

TCCR1B|=(0<<CS12)|(0<<CS11)|(1<<CS10);//CS12->10 = 001 is for 1:1 timer pre-scaler. Start timer
OCR1B = 600;
while(1)
{


for (i = 0; i<255; i++)
{
OCR1B=sine_wave[i];
_delay_ms(10);
}


}
}
