#include <pentabug/music.h>

#include <avr/io.h>

#include <pentabug/timer.h>
#include <pentabug/lifecycle.h>
#include <pentabug/hal.h>

static void tune(void) {
	buzzer_inv();
}

void set_note(uint16_t note, uint8_t octave) {
	if(note != NOTE_PAUSE) {
		// bring buzzer to a state where inverting it creates sound
		buzzer_up();
		// start timer with doubled frequency of tone we want to play
		start_timer(PRESCALE_8, note >> octave, tune);
	} else {
		// do nothing when paused
		stop_note();
	}
}

void stop_note(void) {
	// turn buzzer off to save energy
	buzzer_off();
	// we do not need the timer anymore
	stop_timer();
}

void play_melody(uint16_t notes[], size_t len, uint8_t octave, uint16_t speed) {
	uint16_t length = 1;
	uint16_t pause = speed / 8;

	size_t i;
	size_t j;

	for(i = 0; i < len; ++i) {
		if(notes[i] == MLDY_PAUSE) {
			// user defined pause
			++i;
			wait_ms(speed * notes[i]);
		} else if(notes[i] == MLDY_LENGTH) {
			// sets length for next tone
			++i;
			length = notes[i];

		} else if(notes[i] == MLDY_OCTSHIFT_DOWN) {
			if(octave > 0) {
				--octave;
			}
		} else if(notes[i] == MLDY_OCTSHIFT_UP) {
			++octave;
		} else {
			// play note
			set_note(notes[i], octave);
			test_stop_app();
			for(j = 0; j<length; j++){
				wait_ms(speed);
			}

			// blink eyes
			led_inv(RIGHT);
			led_set(LEFT, !led_state(RIGHT));

			// pause
			stop_note();
			test_stop_app();
			wait_ms(pause);

			// reset length for next note
		//	length = 1;				//	don't reset, so less writing.
		}
	}
}
