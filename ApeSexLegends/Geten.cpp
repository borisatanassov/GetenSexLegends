#include <Globals.h>
#include <iostream>
#include "Geten.h"

Geten::Geten() {
	rect.w = hitbox.w = 600;
	rect.h = hitbox.h = 600;
	rect.x = hitbox.x = SCREEN_WIDTH - SCREEN_WIDTH / 4 - hitbox.w/2;
	rect.y = hitbox.y = SCREEN_HEIGHT - (hitbox.h + 160);
}

Geten::~Geten() {
	//dtor
}