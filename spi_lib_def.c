/*
 * CFile1.c
 *
 * Created: 12/26/2016 12:30:21 AM
 *  Author: DEVKI_NANDAN
 */ 

#include <avr/io.h>
#include "spi_lib.h"
#define F_CPU 1600000
#include <util/delay.h>
#include "C:\Users\DEVKI_NANDAN\Documents\Atmel Studio\6.2\spi_m\spi_m\spi_lib.h"

void SetClock()
{
	PORTB |= (1 << PINB3);
}

void ClearClock()
{
	PORTB &= ~(1 << PINB3);
}

void SetData()
{
	PORTB |= (1 << PINB4);
}

void ClearData()
{
	PORTB &= ~(1 << PINB4);
}

void Set_SS()
{
	PORTB |=(1<<PINB2);
}

void Clear_SS()
{
	PORTB &=~(1<<PINB2);
}
void Spi_Master_Init()
{
	// set up SCK/MOSI as output Pins
	
	SPI_DIR_REG |= (1<<MOSI_PIN) | (1<<CLOCK_PIN)|(1<<SS_PIN);

	SPI_DIR_REG &= ~(1<<MISO_PIN);  // Data-In (MISO) AS input

}

unsigned char   SPI_Write(unsigned char  data)
{
	int  i;
	unsigned char  x;

	
	for (i=0;i<8;i++)

	{
		// set clock low
		ClearClock();

		_delay_us(100);
		
		// output bit
		if (data & 0x80)
		{
			SetData();
			Clear_SS();
		}
		else
		{
			ClearData();
			Set_SS();
		}

		// set clock high

		SetClock();
		Clear_SS();

		_delay_us(100);
		
		data <<= 1;
		
		if(SPI_IN_REG & (1<<MISO_PIN))
		{
			x |= _BV(i);
		}
		
	}

	return  x;
}

