#include <Globals.h>
#include <iostream>
#include "Geten.h"

Geten::Geten() {
	rect.w = 600;
	rect.h = 600;
	rect.x = SCREEN_WIDTH - (rect.w + 200);
	rect.y = SCREEN_HEIGHT - (rect.h + 160);
	hitbox.w = 240;
	hitbox.h = 350;
	hitbox.x = rect.x + (rect.w - hitbox.w) - 100;
	hitbox.y = rect.y + (rect.h - hitbox.h);
}

Geten::~Geten() {
	//dtor
}