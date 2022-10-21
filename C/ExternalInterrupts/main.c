

#include <xc.h>
#include <stdint.h>
#include <avr/interrupt.h> //Necesaria para utilizar interrupciones

#define MAX_VAL  9
#define MIN_VAL  0

uint8_t counter = MIN_VAL;

int main(void)
{
	//Entradas y salidas
	DDRD = 0x00;
	PORTD = (1<<PORTD2) | (1<<PORTD3); //Activar resistencias de pull up en el pin D2 y D3
	DDRB = 0x0F;
	
	//Interrupciones
	EICRA = (1<<ISC11) | (1<<ISC01);
	EIMSK = (1<<INT1) | (1<<INT0);
	
	sei(); //Habilitamos las interrupciones globales
	while(1)
	{
		
	}
}

//ISR para las dos interrupciones externas
ISR(INT0_vect){
	if(counter < MAX_VAL){
		counter++;
		PORTB = counter;
	}
}

ISR(INT1_vect){
	if(counter > MIN_VAL){
		counter--;
		PORTB = counter;
	}
}