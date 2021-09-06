#ifndef GROUND_H
#define GROUND_H
#include "Globals.h"
#include <SDL.h>

class Ground
{
	public:
		Ground(int col);
		virtual ~Ground();

		static SDL_Texture* IMG;
		void draw(SDL_Renderer* render);

		SDL_Rect rect;
};

#endif // GROUND_H