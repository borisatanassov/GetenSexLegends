#include "Ground.h"
#include "Globals.h"

SDL_Texture* Ground::IMG = nullptr;

Ground::Ground(int col) {
	rect.h = 160;
	rect.w = SCREEN_WIDTH / 6;
	rect.x = col * rect.w;
	rect.y = SCREEN_HEIGHT - rect.h;
}

Ground::~Ground() {
	//dtor
}


void Ground::draw(SDL_Renderer* render) {
	SDL_RenderCopy(render, Ground::IMG, NULL, &rect);
}