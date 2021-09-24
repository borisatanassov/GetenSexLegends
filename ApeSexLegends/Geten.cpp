#include <Globals.h>
#include <iostream>
#include "Geten.h"
#include "Player.h"

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

void Geten::resetWH(int w, int h) {
	/// default w = 300, default h = 250;
	Geten::rect.w = w;
	Geten::rect.h = h;
}

bool Geten::handAttack() {
	return true;
}

void Geten::updateHandAttackOne() {
	rect.y = rect.y - deltaTime * handVelocityY; // in main check if handVelY > 0 and do this function else do the second one
    handVelocityY = handVelocityY + deltaTime * handGravity;
}

void Geten::updateHandAttackTwo() {
	handVelocityY = SCREEN_HEIGHT / 25;
	handVelocityY *= -1;
	rect.y = rect.y - handVelocityY;
	rect.x = rect.x + handVelocityX;
}

/*void Geten::AI(Player* player) {
	// check where player is
	if (rect.x - player->rect.x <= 300) {
		handAttackB = true;
	}




	// make cooldown
}*/