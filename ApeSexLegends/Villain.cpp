#include "Villain.h"
#include "Globals.h"

SDL_Texture* Villain::IMG = nullptr;

void Villain::draw(SDL_Renderer* render) {
    SDL_RenderCopy(render, Villain::IMG, NULL, &rect);
}