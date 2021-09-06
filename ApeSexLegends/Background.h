#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Globals.h"
#include <SDL.h>

class Background
{
	public:
		Background(int col);
		virtual ~Background();
		SDL_Rect rect;
		void draw(SDL_Renderer* render);
		static SDL_Texture* IMG;
};

#endif // BACKGROUND_H

