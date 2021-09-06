#ifndef GETEN_H
#define GETEN_H
#include "Globals.h"
#include "Villain.h"
#include <SDL.h>

class Geten : public Villain
{
	public:
		Geten();
		virtual ~Geten();
		SDL_Rect hitbox;
		SDL_Rect dragonRect;
		SDL_Rect handAttackRect;
};

#endif // GETEN_H