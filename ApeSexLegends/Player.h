#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include <vector>
#include "Globals.h"
#include "Geten.h"
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
		float velocityX = SCREEN_WIDTH / 90;
		float velocityY = SCREEN_HEIGHT >> 2;
		int gravity = -630; // smaller number => more gravity
		int bananaGravity = -900;
		float bananaVelX = SCREEN_WIDTH >> 1;
		float bananaVelY = SCREEN_HEIGHT >> 1;

		void draw(SDL_Renderer* render);
		void update(SDL_Event* e, bool isJumping);
		void jump(bool isJumpingSideways);
		void moveDown(bool isJumping);
		void checkBorders();
		bool initBananaAttack(SDL_Rect* getenRect);
		void uninitBananaAttack();
		void updateBanana();
		void checkBananaBorders(bool* bananaUninitB, bool* monkeRangePunching, bool* bananaInitialized);
		void drawBanana(SDL_Renderer* render);
};

#endif // PLAYER_H