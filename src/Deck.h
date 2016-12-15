#pragma once

#include "Card.h"
#include "ofImage.h"

#define ROWS 2
#define COLS 4

class Deck {
public:
	float x, y;
	float offset;
	float cardWidth, cardHeight;

	Card cards[ROWS][COLS];
	ofImage imgs[4];
	ofImage bImg;
	
	Deck();
	void loadImages();
	void placeCards();
	void suffle();
	void draw();
	Card *getCard(float x, float y);
	void enableAllCards();
};