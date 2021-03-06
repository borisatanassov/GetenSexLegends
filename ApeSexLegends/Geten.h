#ifndef GETEN_H
#define GETEN_H
#include "Globals.h"
#include "Villain.h"
#include "Player.h"
#include <SDL.h>

class Geten : public Villain
{
	public:
		Geten();
		virtual ~Geten();
		SDL_Rect dragonRect;
		SDL_Rect handAttackRect;
		float handVelocityX = SCREEN_WIDTH / 80 * -1;
		const float constVelX = SCREEN_WIDTH / 80;
		float handVelocityY = SCREEN_HEIGHT / 1.5;
		int handGravity = -650;
		int originalPosX;
		bool tempHandB = true;
		bool handAttackB = false;
		bool idleB = true;

		void checkBorders();
		void resetWH(int w, int h);
		void resetVel();
		void updateHandAttackOne(); // 36 frames
		void updateHandAttackTwo();
		void updateHandAttackReset();
		bool handAI(SDL_Rect* playerRect);

		// one byte per character and one per line

};

#endif // GETEN_H