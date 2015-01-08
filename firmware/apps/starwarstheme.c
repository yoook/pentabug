#include <stdlib.h>

#include <pentabug/music.h>
#include <pentabug/hal.h>
#include <pentabug/helper.h>
#include <pentabug/app.h>


static uint16_t notes1[] = {
	MLDY_LENGTH, 2, NOTE_D, NOTE_D, NOTE_D,
	MLDY_LENGTH, 12, NOTE_G, MLDY_OCTSHIFT_UP, NOTE_D,
	MLDY_LENGTH, 2, NOTE_C, MLDY_OCTSHIFT_DOWN, NOTE_B, NOTE_A, MLDY_OCTSHIFT_UP, MLDY_LENGTH, 12, NOTE_G, MLDY_LENGTH, 6, NOTE_D,

	MLDY_LENGTH, 2, NOTE_C, MLDY_OCTSHIFT_DOWN, NOTE_B, NOTE_A, MLDY_OCTSHIFT_UP, MLDY_LENGTH, 12, NOTE_G, MLDY_LENGTH, 6, NOTE_D,
	MLDY_LENGTH, 2, NOTE_C, MLDY_OCTSHIFT_DOWN, NOTE_B, MLDY_OCTSHIFT_UP, NOTE_C, MLDY_OCTSHIFT_DOWN, MLDY_LENGTH, 12, NOTE_A
};

static uint16_t notes2[] = {
	MLDY_LENGTH, 4, NOTE_D, MLDY_LENGTH, 2, NOTE_D,
	MLDY_LENGTH, 9, NOTE_E, MLDY_LENGTH, 3, NOTE_E, MLDY_OCTSHIFT_UP, NOTE_C, MLDY_OCTSHIFT_DOWN, NOTE_B, NOTE_A, NOTE_G
};

static uint16_t notes3[] = {
	MLDY_LENGTH, 2, NOTE_G, NOTE_A, NOTE_B, MLDY_LENGTH, 3, NOTE_A, NOTE_E, MLDY_LENGTH, 6, NOTE_Gb
};

static uint16_t notes4[] = {
	MLDY_LENGTH, 5, MLDY_OCTSHIFT_UP, NOTE_D, MLDY_LENGTH, 1, MLDY_OCTSHIFT_DOWN, NOTE_A, MLDY_LENGTH, 12, NOTE_A
};

static uint16_t notes5[] = {
	MLDY_LENGTH, 4, MLDY_OCTSHIFT_UP, NOTE_D, MLDY_LENGTH, 2, NOTE_D,

	MLDY_LENGTH, 4, NOTE_G, MLDY_LENGTH, 2, NOTE_F, MLDY_LENGTH, 4, NOTE_Eb, MLDY_LENGTH, 2, NOTE_D, MLDY_LENGTH, 4, NOTE_C, MLDY_OCTSHIFT_DOWN, MLDY_LENGTH, 2, NOTE_Bb, MLDY_LENGTH, 4, NOTE_A, MLDY_LENGTH, 2, NOTE_G,
	MLDY_LENGTH, 18, MLDY_OCTSHIFT_UP, NOTE_D, MLDY_OCTSHIFT_DOWN
};

static uint16_t notes6[] = {
	MLDY_LENGTH, 2, NOTE_G, NOTE_G, NOTE_G, MLDY_LENGTH, 3, NOTE_G, MLDY_LENGTH, 15, NOTE_PAUSE
};

static void music(void) {
	play_melody(notes1, ARRAY_SIZE(notes1), 4, 80);
	play_melody(notes1, ARRAY_SIZE(notes1), 4, 80);
	play_melody(notes2, ARRAY_SIZE(notes2), 4, 80);
	play_melody(notes3, ARRAY_SIZE(notes3), 4, 80);
	play_melody(notes2, ARRAY_SIZE(notes2), 4, 80);
	play_melody(notes4, ARRAY_SIZE(notes4), 4, 80);
	play_melody(notes2, ARRAY_SIZE(notes2), 4, 80);
	play_melody(notes3, ARRAY_SIZE(notes3), 4, 80);
	play_melody(notes5, ARRAY_SIZE(notes5), 4, 80);
	play_melody(notes1, ARRAY_SIZE(notes1), 4, 80);
	play_melody(notes1, ARRAY_SIZE(notes1), 4, 80);
	play_melody(notes6, ARRAY_SIZE(notes6), 4, 80);
}

REG(music);
