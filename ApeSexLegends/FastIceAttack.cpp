#include "FastIceAttack.h"
#include <string>
using std::string;

FastIceAttack::FastIceAttack() {
	imagePath = "world_images\\fast_ice_left.bmp";	
}

FastIceAttack::~FastIceAttack()
{
	//dtor
}

bool FastIceAttack::drawIce(SDL_Renderer* render, int* playerPos) {	
	fastIceRect.h = 150;
	fastIceRect.w = 300;
	if (*playerPos >= SCREEN_WIDTH - (400 + fastIceRect.w)) { 
		fastIceRect.x = SCREEN_WIDTH - fastIceRect.w;
	}
	else {
		fastIceRect.x = *playerPos - 400;
	}
	fastIceRect.y = SCREEN_HEIGHT - fastIceRect.h - 160;
	SDL_RenderCopy(render, FastIceAttack::iceIMG, NULL, &fastIceRect);
	return true;
}
