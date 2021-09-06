#ifndef VILLAIN_H
#define VILLAIN_H
#include "Globals.h"
#include <SDL.h>
class Villain
{
	public:
		static SDL_Texture* IMG;
		void draw(SDL_Renderer* render);

		int hp = 100;
		SDL_Rect rect;
};

#endif // VILLAIN_H