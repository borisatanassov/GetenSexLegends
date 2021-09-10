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
		SDL_Rect dragonRect;
		SDL_Rect handAttackRect;
		float handVelocityX = SCREEN_WIDTH / 80 * -1;
		float handVelocityY = SCREEN_HEIGHT / 1.5;
		int handGravity = -650;

		void checkBorders();
		bool handAttack();
		void updateHandAttackOne();
		void updateHandAttackTwo();
};

#endif // GETEN_H