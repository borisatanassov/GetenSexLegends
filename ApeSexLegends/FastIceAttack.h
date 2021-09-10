#ifndef FASTICEATTACK_H
#define FASTICEATTACK_H
#include <SDL.h>
#include <string>
#include "Globals.h"
using std::string;

class FastIceAttack	
{
	public:
		FastIceAttack();
		virtual ~FastIceAttack();
		SDL_Texture* iceIMG = nullptr;
		string imagePath;
		bool drawIce(SDL_Renderer* render, int* playerPos);

		SDL_Rect fastIceRect;
};

#endif // FASTICEATTACK_H

