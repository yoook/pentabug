#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>


#define LED_L (1 << PORTC0)
#define LED_R (1 << PORTC2)
#define MOTOR_ON (0<<PORTB1)
#define MOTOR_OFF (1<<PORTB1)



void init_leds(void){
	//enable LED channels as output
	DDRC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3);
	// both LEDs off
	PORTC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3));


	 //TCCR2A = (1 << WGM21);
	  //TCCR2B = (1 << CS20)|(1 << CS21);
	  //OCR2A = 255; /* TOP */
	  //	TCNT2 = 0;
	  //	/*enable interrupt*/
	  //	TIMSK2 |=  (1<<OCIE2A);


  	return;
};

void inline led_on(int leds){
 	PORTC |= leds;
};

void inline led_off(int leds){
	PORTC &= ~leds;
};



void init_buzzr(){
	//its on B2 and C5, for reasons
	DDRC |= (1 << PORTC5);
	DDRB |= (1 << PORTB2);
	//switch it off
	buzzr_off();
	return;
};

void buzzr_up(){
	PORTC &= ~(1 << PORTC5);
	PORTB |= (1 << PORTB2);
	return;
};

void buzzr_down(){
	PORTC |= (1 << PORTC5);
	PORTB &= ~(1 << PORTB2);
};

void inline buzzr_off(){
	PORTC &= ~(1 << PORTC5);
	PORTB &= ~(1 << PORTB2);
};
void buzzr_inv(){
	PORTC ^= (1 << PORTC5);
	PORTB ^= (1 << PORTB2);
};

void init_switch(){
	return;
};

void init_motor(void)
{
	/* vibration motor on B1, initially off: */
	DDRB  |= (1 << PORTB1);
	PORTB &= ~( 1<<PORTB1);
	return;
}

void set_motor(int val){
	PORTB = ~(val);
	PORTB = PORTB;
	return;
};



void __attribute__((noreturn)) 
main(void)
{
	init_motor();
	init_buzzr();
	init_leds();


	/* hardware initialisation: */


	for(;;) /* ever */  {
		//do something
	//	led_off(LED_L|LED_R);
		_delay_ms(100);	
		led_on(LED_L);
		_delay_ms(100);	
		led_off(LED_L);
		led_on(LED_R);
		_delay_ms(100);
		led_off(LED_R);	
		set_motor(MOTOR_ON);
		_delay_ms(200);
		set_motor(MOTOR_OFF);
	
		buzzr_up();
		for (int i=0; i<100; i++){
			_delay_ms(2);
			buzzr_inv();
	
		};
		buzzr_off();
	}
	/* never  return 0; */
}

