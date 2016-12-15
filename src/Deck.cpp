#include "Deck.h"

Deck::Deck() {
	cardWidth = 150;
	cardHeight = 200;
	offset = 50;
	x = 150;
	y = 200;
}

void Deck::loadImages() {
	// Se cargan imágenes frontales
	imgs[0].load("fCard.jpg");
	imgs[1].load("fCard1.jpg");
	imgs[2].load("fCard2.jpg");
	imgs[3].load("fCard3.jpg");
	
	// Se carga imagen posterior
	bImg.load("bCard2.png");

	// Se asigna imagen posterior a cartas
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cards[i][j].setBackImg(&bImg);
		}
	}

	// Se asignan imágenes frontales a cartas
	cards[0][0].setFrontImag(&imgs[0]);
	cards[0][1].setFrontImag(&imgs[0]);
	cards[0][2].setFrontImag(&imgs[1]);
	cards[0][3].setFrontImag(&imgs[1]);
	cards[1][0].setFrontImag(&imgs[2]);
	cards[1][1].setFrontImag(&imgs[2]);
	cards[1][2].setFrontImag(&imgs[3]);
	cards[1][3].setFrontImag(&imgs[3]);

	// Se asignan ids
	cards[0][0].setId(0);
	cards[0][1].setId(0);
	cards[0][2].setId(1);
	cards[0][3].setId(1);
	cards[1][0].setId(2);
	cards[1][1].setId(2);
	cards[1][2].setId(3);
	cards[1][3].setId(3);
}

void Deck::placeCards() {
	// Se colocan las cartas en la posición 
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			float posX = x + (j * (cardWidth + offset));
			float posY = y + (i * (cardHeight + offset));
			cards[i][j].setPosition(posX, posY);
			cards[i][j].setSize(cardWidth, cardHeight);
		}
	}
}

void Deck::suffle() {
	srand(time(NULL));
	// Coloca las cartas de forma aleatoria
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			int m = rand() % ROWS;
			int n = rand() % COLS;
			Card c = cards[i][j];
			cards[i][j] = cards[m][n];
			cards[m][n] = c;
		}
	}
}

void Deck::draw() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cards[i][j].draw();
		}
	}
}

Card * Deck::getCard(float x, float y) {
	Card *card = NULL;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (cards[i][j].isPointInside(x, y)) {
				card = &cards[i][j];
			}
		}
	}
	return card;
}

void Deck::enableAllCards() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cards[i][j].enable = true;
			cards[i][j].faceUp = false;
		}
	}
}
