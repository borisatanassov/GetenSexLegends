#include <Globals.h>
#include <iostream>
#include "Geten.h"

Geten::Geten() {
	rect.w = 300;
	rect.h = 250;
	rect.x = SCREEN_WIDTH - SCREEN_WIDTH / 4;
	rect.y = SCREEN_HEIGHT - (rect.h + 160);
}


Geten::~Geten() {
	//dtor
}

void Geten::checkBorders() {
	if (rect.x > SCREEN_WIDTH - rect.w) {
		rect.x = SCREEN_WIDTH - rect.w;
	}
	if (rect.x < 0) {
		rect.x = 0;
	}
}

bool Geten::handAttack() {
	return true;
}

void Geten::updateHandAttackOne() {
	/*if (handVelocityY > 0) {
		rect.y = rect.y = rect.y - deltaTime * handVelocityY;
		handVelocityY = handVelocityY + deltaTime * handGravity;
	}
	else {
		handVelocityY = SCREEN_WIDTH / 65 * -1;
		rect.y = rect.y = rect.y - deltaTime * handVelocityY;
		handVelocityY = handVelocityY + deltaTime * handGravity;
		rect.x = rect.x = rect.x - deltaTime * handVelocityX;
		handVelocityX = handVelocityX + deltaTime * handGravity;
	}*/
	rect.y = rect.y - deltaTime * handVelocityY; // in main check if handVelY > 0 and do this function else do the second one
    handVelocityY = handVelocityY + deltaTime * handGravity;
}

void Geten::updateHandAttackTwo() {
	handVelocityY = SCREEN_HEIGHT / 25;
	handVelocityY *= -1;
	rect.y = rect.y - handVelocityY;
	rect.x = rect.x + handVelocityX;
}