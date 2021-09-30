#include <Globals.h>
#include <iostream>
#include <iostream>
#include "Geten.h"
#include "Player.h"

Geten::Geten() {
	rect.w = 300;
	rect.h = 250;
	originalPosX = rect.x = SCREEN_WIDTH - SCREEN_WIDTH / 4;
	rect.y = SCREEN_HEIGHT - (rect.h + 160);
	handVelocityY = SCREEN_HEIGHT / 1.5;
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

void Geten::resetWH(int w, int h) {
	/// default w = 300, default h = 250;
	Geten::rect.w = w;
	Geten::rect.h = h; 
}

void Geten::resetVel() {
	handVelocityY = SCREEN_HEIGHT / 1.5;
	handVelocityX = SCREEN_WIDTH / 80 * -1;
}


void Geten::updateHandAttackOne() {
	rect.y = rect.y - deltaTime * handVelocityY; 
    handVelocityY = handVelocityY + deltaTime * handGravity;
}

void Geten::updateHandAttackTwo() {
	handVelocityY = SCREEN_HEIGHT / 25;
	handVelocityY *= -1;
	rect.y = rect.y - handVelocityY;
	rect.x = rect.x + handVelocityX;
}

void Geten::updateHandAttackReset() {
	if (rect.x < originalPosX) {
		rect.x += constVelX;
	}
	else {
		idleB = true;
	}
}

bool Geten::handAI(SDL_Rect* playerRect) {
	// check where player is
	if (rect.x - playerRect->x <= 400) {
		idleB = false;
		return true;
	}
	return false;

	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/// make cooldown !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}