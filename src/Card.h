#pragma once
#include "ofImage.h"
#include "ofRectangle.h"

class Card {
public:
	//Vars
	ofRectangle rect;
	bool faceUp;
	ofImage *frontImg;
	ofImage *backImg;
	int id;
	bool enable;

	//Constructor
	Card(float x, float y, float w, float h, ofImage *fImg, ofImage *bImg);
	Card();

	//Methods
	void draw();
	bool isFaceUp();
	bool isEnable();
	void setId(int id);
	void setSize(float width, float height);
	void flip(); // Interfaz entre la clase rect y la clase carta, que simplifica las herencias
	bool isPointInside(float x, float y);
	void setPosition(float x, float y);
	void setFrontImag(ofImage * fImg);
	void setBackImg(ofImage * bImg);
};