/*
 * Driving Motors.cpp
 *
 * Created: 11/11/2022 6:47:43 AM
 * Author : Dubuisson Samuel 
 */
 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= (1 << PORTD5); // defining the register 
	TCCR0A |= (1 << WGM00 | 1 << COM0A1);
	TCCR0B |= (1 << CS10 | 1 << CS12);
	TIMSK0 |= (1 << OCIE0A);
	sei();
	OCR0A = 255; 
   
    while (1) 
    {
		OCR0A = 0; //100% DC
		_delay_ms(10000);
		OCR0A = 128; // 50% DC
		_delay_ms(10000);
		OCR0A = 63; // 75% DC
		_delay_ms(10000);
		OCR0A = 159; // 25% DC
		_delay_ms(10000);
    }
}

