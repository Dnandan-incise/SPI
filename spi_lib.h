/*
 * IncFile1.h
 *
 * Created: 12/26/2016 12:27:10 AM
 *  Author: DEVKI_NANDAN
 */ 


#ifndef spi_lib
#define spi_lib
/* SPI port and pin definitions.
 */
#define _BV(bit)       (1 << (bit)) 
#define  OUT_REG	    PORTB	//!<  port output register.
#define  SPI_IN_REG	        PINB	//!<  port input register.
#define  SPI_DIR_REG	    DDRB	//!<  port direction register.
#define  CLOCK_PIN	    PINB3	//!<  clock I/O pin.
#define  MISO_PIN	    PINB1	//!<  data input pin or miso.
#define  MOSI_PIN	PINB4	//!<  data output pin or mosi pin.
#define  SS_PIN     PINB2  //slave select pin.
unsigned char   Transmitt_Receive(unsigned char  data);

void SetClock();
void ClearClock();
void SetData();
void ClearData();
void Spi_Master_Init();
void Set_SS();
void Clear_SS();
unsigned char   Transmitt_Receive(unsigned char  data);





#endif /* INCFILE1_H_ */