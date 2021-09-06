#include "Background.h"
#include "Globals.h"
#include "Ground.h"

SDL_Texture* Background::IMG = nullptr;

Background::Background(int col) {
	rect.x = col * SCREEN_WIDTH;
	rect.y = 0;
	rect.h = SCREEN_HEIGHT - 160;
	rect.w = SCREEN_WIDTH * 1.5;
}

Background::~Background() {
	//dtor
}

void Background::draw(SDL_Renderer* render) {
	SDL_RenderCopy(render, Background::IMG, NULL, &rect);
}