#include "Platform.h"
#include "Globals.h"

SDL_Texture* Platform::IMG = nullptr;

void Platform::draw(SDL_Renderer* render) {
	SDL_RenderCopy(render, Platform::IMG, NULL, &rect);
}
