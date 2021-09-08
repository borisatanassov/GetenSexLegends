#include <Globals.h>
#include <iostream>
#include "Geten.h"

Geten::Geten() {
	rect.w = hitbox.w = 600;
	rect.h = hitbox.h = 600;
	rect.x = SCREEN_WIDTH - SCREEN_WIDTH / 4 - hitbox.w/2;
	hitbox.x = rect.x + rect.w/4;
	rect.y = hitbox.y = SCREEN_HEIGHT - (rect.h + 160);
}


Geten::~Geten() {
	//dtor
}

void Geten::checkBorders() {
	if (hitbox.x > SCREEN_WIDTH - hitbox.w) {
		hitbox.x = SCREEN_WIDTH - hitbox.w;
	}
	if (hitbox.x + hitbox.w < hitbox.w) {
		hitbox.x = 0;
	}
}

bool Geten::handAttack() {
	return true;
}

void Geten::updateHandAttackOne() {
	/*if (handVelocityY > 0) {
		rect.y = hitbox.y = rect.y - deltaTime * handVelocityY;
		handVelocityY = handVelocityY + deltaTime * handGravity;
	}
	else {
		handVelocityY = SCREEN_WIDTH / 65 * -1;
		rect.y = hitbox.y = rect.y - deltaTime * handVelocityY;
		handVelocityY = handVelocityY + deltaTime * handGravity;
		rect.x = hitbox.x = rect.x - deltaTime * handVelocityX;
		handVelocityX = handVelocityX + deltaTime * handGravity;
	}*/
	rect.y = hitbox.y = rect.y - deltaTime * handVelocityY; // in main check if handVelY > 0 and do this function else do the second one
    handVelocityY = handVelocityY + deltaTime * handGravity;
}

void Geten::updateHandAttackTwo() {
	handVelocityY = SCREEN_HEIGHT / 90;
	handVelocityY *= -1;
	rect.y = hitbox.y = rect.y - handVelocityY;


	rect.x = hitbox.x = rect.x + deltaTime * handVelocityX;
	handVelocityX = handVelocityX + deltaTime * handGravity;
}