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
		float handVelocityX = SCREEN_WIDTH / 90;
		float handVelocityY = SCREEN_HEIGHT / 1.5;
		int handGravity = -650;

		bool handAttack();
		void updateHandAttack();
};

#endif // GETEN_H