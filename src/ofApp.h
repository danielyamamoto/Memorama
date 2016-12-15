#pragma once

#include "ofMain.h"
#include "Card.h"
#include "Deck.h"

class ofApp : public ofBaseApp{

	public:
		Deck deck;
		Card* card1;
		Card* card2;

		int pairCount;
		int turnCount;
		int maxTurn;
		int totalPairs;
		bool gameOver;
		string gameOverMsg;

		void setup();
		void update();
		void draw();

		void selectCard(float x, float y);
		bool compareCards();
		void resetGame();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
