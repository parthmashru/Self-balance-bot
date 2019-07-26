/*
 * UART Test.c
 *
 * Created: 24-07-2019 05:23:17 PM
 * Author : PARTH
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define baudrate 9600
#define FOSC 8000000UL
#define UBRR 51

//int intdata;

void uart_init (void)
{
	UBRR0H = (UBRR >> 8);
	UBRR0L = UBRR;
	UCSR0C |=(1<<UCSZ01)|(1<<UCSZ02);
	UCSR0B |=(1<<RXEN0)|(1<<TXEN0);
	
}
 
void uart_transmit (char data)
{
	while (!( UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
}

char uart_receive (void)
{
	while (!( UCSR0A & (1<<RXC0)));
	return UDR0;
}

void usart_transmit_string(char str[])
{
	int i=0;
	while(str[i] != NULL)
	{
		
		uart_transmit(str[i]);
		i++;
		_delay_ms(100);
	}
}

int main(void)
{
	
	uart_init();
    int intdata=9;
	char data[10] ;
	

    while (1) 
    {
		
		//data=uart_receive();
		itoa(intdata,data,10);
		usart_transmit_string(data);
		_delay_ms(50);
    }
}

