/*
 * CFile1.c
 *
 * Created: 12/26/2016 12:30:21 AM
 *  Author: DEVKI_NANDAN
 */ 
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

void Spi_Master_Init()
{
	// set up SCK/MOSI as output Pins
	
	DIR_REG |= (1<<DATAOUT_PIN) | (1<<CLOCK_PIN);

	DIR_REG &= ~(1<<DATAIN_PIN);  // Data-In (MISO) AS input

}

unsigned char   Transmitt_Receive(unsigned char  data)
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
		}
		else
		{
			ClearData();
		}

		// set clock high

		SetClock();

		_delay_us(100);
		
		data <<= 1;
		
		if(IN_REG & (1<<DATAIN_PIN))
		{
			x |= _BV(i);
		}
		
	}

	return  x;
}

