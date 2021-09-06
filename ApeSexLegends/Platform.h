#ifndef PLATFORM_H
#define PLATFORM_H
#include "Globals.h"
#include <SDL.h>

class Platform
{
	public:
		static SDL_Texture* IMG;
		void draw(SDL_Renderer* render);

		SDL_Rect rect;
};

#endif // PLATFORM_H