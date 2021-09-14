#include <SDL.h>
#include <string>
#include <cmath>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <SDL_ttf.h>
#include "Globals.h"
#include "Player.h"
#include "Background.h"
#include "Platform.h"
#include "Villain.h"
#include "Text.h"
#include "Ground.h"
#include "FastIceAttack.h"
#include "Geten.h"
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

SDL_Texture* loadTexture(SDL_Renderer* render, string fileName) {
	SDL_Texture* res;
	SDL_Surface* tmp = SDL_LoadBMP(fileName.c_str());
	res = SDL_CreateTextureFromSurface(render, tmp);
	SDL_FreeSurface(tmp);
	return res;
}


/// Functions for initializing Vectors

vector<SDL_Texture*> initGetenIdleAnimationV(vector<SDL_Texture*> getenIdleV, SDL_Renderer* render, 
	SDL_Texture* (*loadTexture)(SDL_Renderer* render, string filename)) {
	getenIdleV.push_back(loadTexture(render, "player_images\\geten_images_idle\\geten_idle1.bmp"));
	getenIdleV.push_back(loadTexture(render, "player_images\\geten_images_idle\\geten_idle2.bmp"));
	return getenIdleV;
}

vector<SDL_Texture*> initGetenDragonAnimationV(vector<SDL_Texture*> getenAnimationV, SDL_Renderer* render,
	SDL_Texture* (*loadTexture)(SDL_Renderer* render, string filename)) {
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten1.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten2.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten3.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten4.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten5.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten6.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten7.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten8.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten9.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten10.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten11.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten12.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten13.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten14.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten15.bmp"));
	getenAnimationV.push_back(loadTexture(render, "player_images\\geten_images\\geten16.bmp"));
	return getenAnimationV;
}

vector<SDL_Texture*> initMonkeSaiyanV(vector<SDL_Texture*> monkeSaiyan, SDL_Renderer* render,
	SDL_Texture* (*loadTexture)(SDL_Renderer* render, string filename)) {
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan0.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan1.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan2.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan3.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan4.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan5.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan6.bmp"));
	monkeSaiyan.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan7.bmp"));
	return monkeSaiyan;
}
///  END


void drawTitleScreen(SDL_Renderer* render, SDL_Texture* titleScreen) {
	SDL_Rect tempRect;
	tempRect.x = tempRect.y = 0;
	tempRect.w = SCREEN_WIDTH;
	tempRect.h = SCREEN_HEIGHT;
	SDL_RenderCopy(render, titleScreen, NULL, &tempRect);
}

char collision(SDL_Rect* rect1, SDL_Rect* rect2, float velX, float velY) {
	if (rect1->x + rect1->w + velX > rect2->x) {
		if (rect1->x + velX < rect2->x + rect2->w) {
			if (rect1->y + rect1->h > rect2->y) {
				if (rect1->y < rect2->y + rect2->h) {
					return 'x';
				}
			}
		}
	}

	if (rect1->x + rect1->w > rect2->x) {
		if (rect1->x < rect2->x + rect2->w) {
			if (rect1->y + rect1->h + velY > rect2->y) {
				if (rect1->y + velY < rect2->y + rect2->h) {
					return 'y';
				}
			}
		}
	}

	return '0';
}

bool groundCollision(SDL_Rect* geten, SDL_Rect* ground) {
	if (geten->y + geten->h > ground->y) {
		return true;
	}
}

void startAnimateSuperSayanMonke(int* frameCounter, int FPS, Player* player, SDL_Texture* monkeSayn0, SDL_Texture* monkeSayn1,
	SDL_Texture* monkeSayn2, SDL_Texture* monkeSayn3, SDL_Texture* monkeSayn4) {
	if (*frameCounter <= (FPS / 5)) {
		player->IMG = monkeSayn0;
	}
	else if (*frameCounter <= 2 * (FPS / 5)) {
		player->IMG = monkeSayn1;
	}
	else if (*frameCounter <= 3 * (FPS / 5)) {
		player->IMG = monkeSayn2;
	}
	else if (*frameCounter <= 4 * (FPS / 5)) {
		player->IMG = monkeSayn3;
	}
	else if (*frameCounter <= 5 * (FPS / 5)) {
		player->IMG = monkeSayn4;
	}
}

void contAnimateSuperSayanMonke(int* frameCounter, int FPS, Player* player, SDL_Texture* monkeSayn5, SDL_Texture* monkeSayn6, SDL_Texture* monkeSayn7) {
	if (*frameCounter <= (FPS / 7)) {
		player->IMG = monkeSayn5;
	}
	else if (*frameCounter <= 2 * (FPS / 7)) {
		player->IMG = monkeSayn6;
	}
	else if (*frameCounter <= 3 * (FPS / 7)) {
		player->IMG = monkeSayn7;
	}
	else if (*frameCounter <= 4 * (FPS / 7)) {
		player->IMG = monkeSayn6;
	}
	else if (*frameCounter <= 5 * (FPS / 7)) {
		player->IMG = monkeSayn5;
	}
	else if (*frameCounter <= 6 * (FPS / 7)) {
		player->IMG = monkeSayn6;
	}
	else if (*frameCounter <= 7 * (FPS / 7)) {
		player->IMG = monkeSayn7;
	}
	else if (*frameCounter <= 8 * (FPS / 7)) {
		player->IMG = monkeSayn6;
	}
}

void getenHandAnimation(Geten* geten, vector<SDL_Texture*> getenAnimationV) {
	int num = static_cast<int>(SDL_GetTicks() / 200) % (getenAnimationV.size());
	geten->IMG = getenAnimationV[num];
}

void getenIdleAnimation(Geten* geten, vector<SDL_Texture*> getenIdleV) {
	int num = static_cast<int>(SDL_GetTicks() / 250) % (getenIdleV.size());
	geten->rect.w = 430;
	geten->rect.h = 380;
	geten->IMG = getenIdleV[num];
}

bool rangeAttackCountDown(int* timer, bool* start) {
	if (*start) {
		if (*timer >= 0) {
			*timer -= 30;
		}
		else {
			*timer = 500; 
			*start = false;
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
	/// SDL INITIALIZATION
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_Window* win = SDL_CreateWindow("Ape Sex Legends", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Renderer* render = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	Ground::IMG = loadTexture(render, "world_images\\ground_tiles.bmp");
	Player::IMG = loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan1.bmp");
	Background::IMG = loadTexture(render, "world_images\\background_apesex.bmp");
	Geten::IMG = loadTexture(render, "player_images\\geten_initial_attack.bmp");
	SDL_Texture* titleScreenImage = loadTexture(render, "world_images\\background_image.bmp");
	vector<SDL_Texture*> monkeSaiyan;
	monkeSaiyan = initMonkeSaiyanV(monkeSaiyan, render, &loadTexture);
	vector<SDL_Texture*> getenAnimationV;
	getenAnimationV = initGetenDragonAnimationV(getenAnimationV, render, &loadTexture);
	vector<SDL_Texture*> getenIdleV;
	getenIdleV = initGetenIdleAnimationV(getenIdleV, render, &loadTexture);
	
	// Initializing Objects
	Text* hpTextPlayer = new Text(16, 9, 80, 80);
	Text* hpTextGeten = new Text(SCREEN_WIDTH - 96, 9, 80, 80);
	Text* titleScreenText = new Text(SCREEN_WIDTH - 1750, (SCREEN_HEIGHT >> 1) - 300, 1600, 400);
	titleScreenText->color.r = 0;
	titleScreenText->color.g = 0;
	titleScreenText->color.b = 0;
	vector <Ground*> ground;
	for (int i = 0; i < 24; i++) {
		ground.push_back(new Ground(i));
	}
	vector <Background*> background;
	for (int i = 0; i < 2; i++) {
		background.push_back(new Background(i));
	}
	background[1]->rect.x = background[0]->rect.w;
	Player* player = new Player();
	Geten* geten = new Geten();
	FastIceAttack* fastIceAttackGeten = new FastIceAttack();
	fastIceAttackGeten->iceIMG = loadTexture(render, fastIceAttackGeten->imagePath);
	SDL_Event e;

	int tempPlayerPositionX = 0;
	int secondsCounter = 1;
	int frameCounter = 1;
	int secondsCounterGeten = 3500;
	int fastIceCooldown = 5000;
	int fastIceTimer = 1000;
	int tempInt = 0;

	bool startGame = false;
	bool firstIterationAnimateSayanMonke = true;
	bool firstIterationAnimateGeten = true;
	bool isJumping = false;
	bool isJumpingSideways = false;
	bool atEndOfMap = false;

	bool fastIceAttacked = false;
	bool fastIceTimerActivated = false;
	bool fastIceDrawn = false;
	bool fastIceCollision = false;
	bool getPlayerPosition = false;

	bool tempB = false;
	bool monkeRangePunching = false;
	bool fastIceCooldownB = false;

	/// TITLE SCREEN
	while (!startGame) {
		SDL_RenderClear(render);
		SDL_PollEvent(&e);
		if (e.type == SDL_KEYDOWN) {
			const Uint8* key = SDL_GetKeyboardState(NULL);
			if (key[SDL_SCANCODE_SPACE]) {
				startGame = true;
			}
		}
		titleScreenText->initializeTexture(render, "El Banditos Presents: \n Ape Sex Legends");
		if (SDL_GetTicks() / 300 % 2 != 0) {
			titleScreenText->rect.y += 1;
			titleScreenText->rect.x -= 1;
		}
		else {
			titleScreenText->rect.x += 1;
			titleScreenText->rect.y -= 1;
		}
 		// draw
		drawTitleScreen(render, titleScreenImage);
		titleScreenText->draw(render);
		SDL_RenderPresent(render);
		SDL_Delay(FPS);
	}



	while (player->hp > 0) {
		SDL_RenderClear(render);
		SDL_PollEvent(&e);
		/// UPDATING THE PLAYER'S POSITION 
		if (e.type == SDL_KEYDOWN) {
			const Uint8* key = SDL_GetKeyboardState(NULL);
			if (key[SDL_SCANCODE_K]) {
				if (!fastIceDrawn && fastIceCooldown == 5000) {
					fastIceAttacked = true;
					fastIceTimerActivated = true;
					getPlayerPosition = true;
				}
			}
			if (key[SDL_SCANCODE_E]) {
				monkeRangePunching = player->rangePunch();
				player->rangeAttackTimerB = true;
			}
			if (player->rect.y + player->rect.h >= ground[0]->rect.y) { // if the player is in the air => jumping disabled
				if (key[SDL_SCANCODE_RIGHT] && key[SDL_SCANCODE_UP]) {
					isJumpingSideways = true;
					player->gravity = -600;
					player->velocityY = SCREEN_HEIGHT >> 1;
					player->velocityX = SCREEN_HEIGHT / 90;
					isJumping = true;
				}
				else if (key[SDL_SCANCODE_LEFT] && key[SDL_SCANCODE_UP]) {
					isJumpingSideways = true;
					player->gravity = -600;
					player->velocityY = SCREEN_HEIGHT >> 1;
					player->velocityX = (SCREEN_HEIGHT / 90) * -1;
					isJumping = true;
				}
				else if (key[SDL_SCANCODE_UP]) {
					isJumpingSideways = false;
					player->gravity = -600;
					player->velocityY = SCREEN_HEIGHT >> 1;
					player->velocityX = 0;
					isJumping = true;
				}
			}
			player->update(&e, isJumping);
		}

		if (isJumping) {
			player->jump(isJumpingSideways);
			player->moveDown(isJumping);
		}
		player->checkBorders();
		

		/// UPDATING GETEN'S POSITION
		if (geten->handAttackB) {
			if (geten->handVelocityY > 0) {
				geten->updateHandAttackOne();
			}
			else {
				geten->updateHandAttackTwo();
			}
		}
		else if (geten->idleB) {
			getenIdleAnimation(geten, getenIdleV);	
		}
		geten->checkBorders();


		/// FRAME COUNTER AND ANIMATIONS
	

		switch (frameCounter) {
		case FPS + 1:
			frameCounter = 1;
			break;
		case FPS:
			if (secondsCounter <= 100) {
				secondsCounter++;
			}
			break;
		}
		// Ice timer    
		if (fastIceTimerActivated) {
			fastIceTimer -= 30;
		}
		if (fastIceTimer < 0) {
			fastIceTimer = 0;
			fastIceTimerActivated = false;
			fastIceAttacked = false;
			fastIceDrawn = false;
			fastIceCooldownB = true;
			fastIceTimer = 1000;
		}
		if (fastIceCooldownB) {
			fastIceCooldown -= 30;
		}
		if (fastIceCooldown < 0) {
			fastIceCooldownB = false;
			fastIceCooldown = 5000;
		}


		// Check HP
		string tempText = to_string(player->hp);
		char const* pchar = tempText.c_str();
		hpTextPlayer->initializeTexture(render, pchar);

		/// COLLISION
		for (int i = 0; i < ground.size(); i++) {
			if (collision(&(player->rect), &(ground[i]->rect), player->velocityX, player->velocityY) != '0') {
				if (player->rect.y + player->rect.h > ground[i]->rect.y) {
					player->rect.y = ground[i]->rect.y - player->rect.h;
					player->velocityY = 0;
					player->velocityX = 0;
					isJumpingSideways = false;
					isJumping = false;
				}	
			}
		}
		if (geten->hp > 0) {
			tempText = to_string(geten->hp); // init the text here so we don't have to check the hp twice
			pchar = tempText.c_str();
			hpTextGeten->initializeTexture(render, pchar);
			if (monkeRangePunching) {
				tempInt = player->rect.y - player->rect.h * (3 / 4);
				if (rangeAttackCountDown(&player->rangeAttackTimer, &player->rangeAttackTimerB)) {
					if (tempInt <= geten->rect.y + geten->rect.h && tempInt >= geten->rect.y) {
						geten->hp -= 20;
					}
					monkeRangePunching = false;
				}
			}
			if (collision(&(player->rect), &(geten->rect), player->velocityX, player->velocityY) == 'x') {
				player->rect.x = geten->rect.x - player->rect.w;
			}
			else if (collision(&(player->rect), &(geten->rect), player->velocityX, player->velocityY) == 'y') {
				player->rect.y = geten->rect.y - player->rect.h;
			}			
			for (int i = 0; i < ground.size(); i++) {
				if (collision(&(geten->rect), &(ground[i]->rect), 0, 0) != '0') {
					if (geten->rect.y + geten->rect.h > ground[i]->rect.y) {
						geten->rect.y = ground[i]->rect.y - geten->rect.h;
						geten->handVelocityX = 0;
						geten->handVelocityY = 0;
					}
				}
			}
		}
		if (!fastIceCollision) {
			if (collision(&player->rect, &(fastIceAttackGeten->fastIceRect), 0, 0) != '0') {
				if (fastIceDrawn) {
					player->hp -= 10;
					fastIceCollision = true;
					fastIceAttacked = false;
				}
			}
		}

		

		/// RENDERING
		for (int i = 0; i < background.size(); i++) {
			background[i]->draw(render);
		}
		for (int i = 0; i < ground.size(); i++) {
			ground[i]->draw(render);
		}
		player->draw(render);
		hpTextPlayer->draw(render);
		if (geten->hp > 0) {
			geten->draw(render);
			hpTextGeten->draw(render);
		}
		geten->resetWH(300, 250); // need to reset because when animating it the w and h change 
		if (getPlayerPosition) {
			tempPlayerPositionX = geten->rect.x; // checking player position for ice drawing;
		}
		if (fastIceAttacked) {
			fastIceDrawn = fastIceAttackGeten->drawIce(render, &tempPlayerPositionX);
			fastIceCollision = false;
			getPlayerPosition = false;
		}
		SDL_RenderPresent(render);
		SDL_Delay(FPS);
	}



	/// END OF PROGRAM
	delete player; // Offload objects from memory
	delete fastIceAttackGeten;
	hpTextPlayer->cleanUp();
	hpTextGeten->cleanUp();
	titleScreenText->cleanUp();
	delete hpTextPlayer;
	delete hpTextGeten;
	delete titleScreenText;
	for (int i = 0; i < ground.size(); i++) {
		delete ground[i];
	}
	for (int i = 0; i < background.size(); i++) {
		delete background[i];
	}
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	TTF_Quit();
	SDL_Quit();
	return 0;
}