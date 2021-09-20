#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include <vector>
#include "Geten.h"
#include "Globals.h"
using std::vector;

class Player
{
	public:
		Player();
		virtual ~Player();
		static SDL_Texture* IMG;
		static SDL_Texture* bananaImage;
		static SDL_Texture* iceImage;
		SDL_Rect rect;
		SDL_Rect bananaRect;
		int hp = 100;
		int shield = 0;
		int punchRange = 0;
		int rangeAttackTimer = 500; // half a second delay before damage happens
		bool rangeAttackTimerB = false; // half a second delay before damage happens
		float velocityX = SCREEN_WIDTH / 90;
		float velocityY = SCREEN_HEIGHT >> 2;
		int gravity = -630; // smaller number => more gravity
		int bananaGravity = -200;
		float bananaVelX = SCREEN_WIDTH / 70;
		float bananaVelY = SCREEN_HEIGHT / 110;

		void draw(SDL_Renderer* render);
		void update(SDL_Event* e, bool isJumping);
		void jump(bool isJumpingSideways);
		void moveDown(bool isJumping);
		void checkBorders();
		bool rangePunch();
		void initBananaAttack(Geten* geten);
		void drawBanana(SDL_Renderer* render);
};

#endif // PLAYER_H