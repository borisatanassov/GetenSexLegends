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

bool Geten::handAttack() {
	return true;
}

void Geten::updateHandAttack() {
	if (handVelocityY > 0) {
		rect.y = hitbox.y = rect.y - deltaTime * handVelocityY;
		handVelocityY = handVelocityY + deltaTime * handGravity;
	}
	else {
		handVelocityY = SCREEN_WIDTH / 65 * -1;
		rect.y = hitbox.y = rect.y - deltaTime * handVelocityY;
		handVelocityY = handVelocityY + deltaTime * handGravity;
		rect.x = hitbox.x = rect.x - deltaTime * handVelocityX;
		handVelocityX = handVelocityX + deltaTime * handGravity;
	}
}