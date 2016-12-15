#include "Card.h"

Card::Card(float x, float y, float w, float h, ofImage * fImg, ofImage * bImg) 
	:rect(x, y, w, h), frontImg(fImg), backImg(bImg) {

}

Card::Card() :rect(0, 0, 0, 0) {
	enable = true;
}

void Card::draw() {
	if (enable) {
		if (faceUp) { // Si la carta está arriba 
					  // Dibuja la imagen frontal
			frontImg->draw(rect.x, rect.y, rect.width, rect.height);
		}
		else { // Si la carta está abajo
			   // Dibuja la imagen trasera
			backImg->draw(rect.x, rect.y, rect.width, rect.height);
		}
	}
}

bool Card::isFaceUp() {
	return faceUp;
}

bool Card::isEnable() {
	return enable;
}

void Card::setId(int id) {
	this->id = id;
}

void Card::setSize(float width, float height) {
	rect.setWidth(width);
	rect.setHeight(height);
}

void Card::flip() {
	faceUp = !faceUp;
}

bool Card::isPointInside(float x, float y) {
	return rect.inside(x, y);
}

void Card::setPosition(float x, float y) {
	rect.setPosition(x, y);
}

void Card::setFrontImag(ofImage * fImg) {
	frontImg = fImg;
}

void Card::setBackImg(ofImage * bImg) {
	backImg = bImg;
}