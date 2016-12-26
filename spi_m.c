/*
 * spi_m.c
 *
 * Created: 12/25/2016 11:36:19 PM
 *  Author: DEVKI_NANDAN
 */ 


#include <avr/io.h>
#include "spi_lib.h"
#define F_CPU 1600000
#include<util/delay.h>
int main(void)
{
	DDRD |=0xFF;
	Spi_Master_Init();
	//while(1)
	//{
		PORTD = SPI_Write(0b10000001);
		_delay_ms(1000);
		_delay_ms(1000);
	//}
}