#include "Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
TTF_Font* Text::font = TTF_OpenFont("fonts\\toon-around.ttf", 10);

Text::Text(int x, int y, int w, int h) {
	font = TTF_OpenFont("fonts\\toon-around.ttf", 80);
	color = { 144, 0, 0, 255 };

	rect.x = x; // 16
	rect.y = y; // 9
	rect.w = w; // 80
	rect.h = h; // 80
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
}

Text::~Text() {
	//dtor
}

void Text::setFontStyle(TTF_Font* font, int style) { // 1 = b, 2 = i, 3 = u, 4 = st
	switch (style) {
		case 1:
			TTF_SetFontStyle(font, TTF_STYLE_BOLD);
			break;
		case 2:
			TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
			break;
		case 3:
			TTF_SetFontStyle(font, TTF_STYLE_UNDERLINE);
			break;
		case 4:
			TTF_SetFontStyle(font, TTF_STYLE_STRIKETHROUGH);
			break;
	}
}

void Text::initializeTexture(SDL_Renderer* render, const char* text) {
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(render, surface);
}

void Text::draw(SDL_Renderer* render) {
	SDL_RenderCopy(render, texture, NULL, &rect);
}

void Text::cleanUp() {
	SDL_FreeSurface(surface);
	surface = nullptr;
	delete surface;
	SDL_DestroyTexture(texture);
	texture = nullptr;
	delete texture;
}