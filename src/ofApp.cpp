#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	card1 = NULL; // Sin seleccionar carta1
	card2 = NULL; // Sin seleccionar carta2
	maxTurn = 6;
	totalPairs = 4;
	pairCount = 0;
	turnCount = 0;
	gameOver = false;
	deck.loadImages();
	deck.placeCards();
	deck.suffle();
	deck.placeCards();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	deck.draw();
	string score = "Pares: " + ofToString(pairCount) + " Turno: " + ofToString(turnCount);
	ofDrawBitmapString(score, 20, 20);
	if (gameOver) {
		ofDrawBitmapString(gameOverMsg, ofGetWidth() / 2, ofGetHeight() / 2);
	}
}

void ofApp::selectCard(float x, float y){
	if (card1 == NULL && card2 == NULL) {
		Card *card = deck.getCard(x, y);
		if (card != NULL) {
			if (card->isEnable() && !card->isFaceUp()) {
				card->flip();
				card1 = card;
			}
		}
	}
	else if (card1 != NULL && card2 == NULL) {
		Card *card = deck.getCard(x, y);
		if (card != NULL) {
			if (card->isEnable() && !card->isFaceUp()) {
				card->flip();
				card2 = card;
			}
		}
	}
	else {
		//Comparo Cartas
		if (compareCards()) {
			card1->enable = false;
			card2->enable = false;
			pairCount++;
		}
		else {
			card1->flip();
			card2->flip();
		}
		turnCount++;
		
		if (turnCount > maxTurn) {
			// Perdiste
			gameOver = true;
			gameOverMsg = "Perdiste";
		}
		else if (pairCount == totalPairs) {
			// Ganaste
			gameOver = true;
			gameOverMsg = "Ganaste";
		}

		card1 = NULL;
		card2 = NULL;
	}
}

bool ofApp::compareCards() {
	if (card1->id == card2->id) {
		return true;
	}
	return false;
}

void ofApp::resetGame() {
	turnCount = 0;
	pairCount = 0;
	deck.enableAllCards();
	deck.suffle();
	deck.placeCards();
	gameOver = false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	selectCard(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
