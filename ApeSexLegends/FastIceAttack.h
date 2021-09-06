#ifndef FASTICEATTACK_H
#define FASTICEATTACK_H
#include <SDL.h>
#include <string>
#include "Globals.h"
using std::string;

class FastIceAttack	
{
	public:
		FastIceAttack(string user);
		virtual ~FastIceAttack();
		SDL_Texture* iceIMG = nullptr;
		string imagePath;
		bool drawIce(SDL_Renderer* render, int* playerPos);

		int user;
		SDL_Rect fastIceRect;
};

#endif // FASTICEATTACK_H

