// Code by Pixel, DroidTeam
// Basic music, it is the first part of the Pokemon Red/Blue Intro soundtrack
// Currently the Speaker is set to Digital Pin 8

#include "pitches.h"
#define speakerPIN 8

int melody1[] = {
  NOTE_D3, NOTE_D3, NOTE_F4, NOTE_D3, NOTE_D3, NOTE_AS4, NOTE_D3, NOTE_D3, NOTE_CS3, NOTE_D3, NOTE_D3, NOTE_F4, NOTE_D3, NOTE_D3, NOTE_AS4, NOTE_B4
};

int melody2[] = {
	NOTE_DS3, NOTE_C5, NOTE_C3
};

int noteDurations[] = {
  8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 2
};

int noteDurations2[] = {
	2, 2, 2
};

void setup() {
	Serial.begin(57600);
}

void loop() {
	for (int thisNote = 0; thisNote < 16; thisNote++) {
		int noteDuration = (1000 / noteDurations[thisNote]) * (analogRead(0) / 100);		
		tone(speakerPIN, melody1[thisNote], noteDuration);
		int pauseBetweenNotes = noteDuration * (analogRead(0) / 100);
		if (pauseBetweenNotes < 125) pauseBetweenNotes = 125;
		Serial.println(pauseBetweenNotes);
		delay(pauseBetweenNotes);
		noTone(speakerPIN);
	}
	for (int thisNote = 0; thisNote < 3; thisNote++) {
		int noteDuration = (1000 / noteDurations2[thisNote]) * (analogRead(0) / 100);		
		tone(speakerPIN, melody2[thisNote], noteDuration);
		int pauseBetweenNotes = noteDuration * (analogRead(0) / 100);
		if (pauseBetweenNotes < 125) pauseBetweenNotes = 125;
		Serial.println(pauseBetweenNotes);
		delay(pauseBetweenNotes);
		noTone(speakerPIN);
	}
}