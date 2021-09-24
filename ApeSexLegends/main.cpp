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

vector<SDL_Texture*> initMonkeSaiyanV(vector<SDL_Texture*> monkeSaiyanV, SDL_Renderer* render,
	SDL_Texture* (*loadTexture)(SDL_Renderer* render, string filename)) {
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan0.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan1.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan2.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan3.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan4.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan5.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan6.bmp"));
	monkeSaiyanV.push_back(loadTexture(render, "player_images\\monke_sayn_images\\Monkey_sayan7.bmp"));
	return monkeSaiyanV;
}

vector<SDL_Texture*> initBananaV(vector<SDL_Texture*> bananaV, SDL_Renderer* render,
	SDL_Texture* (*loadTexture)(SDL_Renderer* render, string filename)) {
	bananaV.push_back(loadTexture(render, "world_images\\banana\\banana1.bmp"));
	bananaV.push_back(loadTexture(render, "world_images\\banana\\banana2.bmp"));
	bananaV.push_back(loadTexture(render, "world_images\\banana\\banana3.bmp"));
	bananaV.push_back(loadTexture(render, "world_images\\banana\\banana4.bmp"));
	return bananaV;
}
///  END

/// Animation Functions
void animateSaiyanMonkeOne(Player* player, vector<SDL_Texture*>monkeSaiyanV) {
	int num = static_cast<int>(SDL_GetTicks() / 200) % 5;
	player->IMG = monkeSaiyanV[num];
}

void animateSaiyanMonkeTwo(Player* player, vector<SDL_Texture*>monkeSaiyanV) {
	int num = static_cast<int>(SDL_GetTicks() / 100) % 4;
	player->IMG = monkeSaiyanV[num + 4]; // becoz math	
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
/// END

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

void animateBanana(Player* player, vector<SDL_Texture*> bananaV) {
	int num = static_cast<int>(SDL_GetTicks() / 100) % 4;
	player->bananaImage = bananaV[num]; // becoz math
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
	vector<SDL_Texture*> monkeSaiyanV;
	monkeSaiyanV = initMonkeSaiyanV(monkeSaiyanV, render, &loadTexture);
	vector<SDL_Texture*> bananaV;
	bananaV = initBananaV(bananaV, render, &loadTexture);
	Player::bananaImage = bananaV[0];
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
	int fastIceCooldown = 5000;
	int fastIceTimer = 1000;
	int secondsCounter = 0;
	int tempInt = 0;

	bool startGame = false;
	bool fIterationAnimateSayanMonke = true;
	bool isJumping = false;
	bool isJumpingSideways = false;
	bool atEndOfMap = false;

	bool fastIceAttacked = false;
	bool fastIceTimerActivated = false;
	bool fastIceDrawn = false;
	bool fastIceCollision = false;
	bool getPlayerPosition = false;

	bool monkeRangePunching = false;
	bool monkeRangeAnimateU = false;
	bool bananaInitB = false;
	bool bananaUninitB = false;
	bool bananaInitialized = false;
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
			if (!bananaInitialized) {
				if (key[SDL_SCANCODE_E]) {
					bananaInitB = true;
					monkeRangePunching = player->rangePunch();
					monkeRangeAnimateU = player->rangePunch();
				}
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
		

		/// FRAME COUNTER AND ANIMATIONS
		
		// Updating Geten's position
		//geten->AI(player);
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

		// Monke Saiyan animation
	
		if (secondsCounter == 2000000000) {
			secondsCounter = 999; // JIC somebody decides to run the game 18518.5185185 hours the 4 byte integer would overflow;
		}
		if (secondsCounter <= 999) {
			animateSaiyanMonkeOne(player, monkeSaiyanV);
		}
		else {
			animateSaiyanMonkeTwo(player, monkeSaiyanV);
		}

		// Banana animation and update
		if (bananaInitB) {
			bananaInitialized = player->initBananaAttack(geten);
			bananaInitB = false;
		}
		else if (bananaUninitB) {
			player->uninitBananaAttack();
			bananaUninitB = false;
			bananaInitialized = false;
		}

		if (monkeRangeAnimateU) {
			animateBanana(player, bananaV);
			player->updateBanana();
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
				if(collision(&(player->bananaRect), &(geten->rect), 0, 0) != '0') {
					geten->hp -= 20;
					bananaUninitB = true;
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
		player->drawBanana(render);
		if (geten->hp > 0) {
			geten->draw(render);
			hpTextGeten->draw(render);
		}
		if (getPlayerPosition) {
			tempPlayerPositionX = geten->rect.x; // checking player position for ice drawing;
		}
		if (fastIceAttacked) {
			fastIceDrawn = fastIceAttackGeten->drawIce(render, &tempPlayerPositionX);
			fastIceCollision = false;
			getPlayerPosition = false;
		}
		geten->resetWH(300, 250); // need to reset because when animating it the w and h change 
		secondsCounter += 33;
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