#include <Windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include "Player.h"
#include "Ground.h"
#include "Globals.h"
#include "Geten.h"
using std::vector;
using std::cout;
using std::endl;

SDL_Texture* Player::IMG = nullptr;
SDL_Texture* Player::bananaImage = nullptr;


Player::Player() {   
    rect.h = 180;
	rect.w = 150;
	rect.x = SCREEN_WIDTH / 4;
    rect.y = SCREEN_HEIGHT - rect.h - 160; // spawn position on y; idk why it works this way; FIX LATER
}

Player::~Player()
{
	//dtor
}

void Player::draw(SDL_Renderer* render) {
	SDL_RenderCopy(render, Player::IMG, NULL, &rect);
}

void Player::jump(bool isJumpingSideways) { 
    if (isJumpingSideways) {
        rect.x += velocityX;
    }
    rect.y = rect.y - deltaTime * velocityY; // meth; should probably make a single vector out of velX and velY 
    velocityY = velocityY + deltaTime * gravity;  // but I'm too lazy and this works well enough
}

void Player::moveDown(bool isJumping) { 
    const Uint8* key = SDL_GetKeyboardState(NULL); // get all pressed keys
    if (isJumping) {
        if (key[SDL_SCANCODE_DOWN]) {
            gravity -= 1000;
        }
    }
}

void Player::update(SDL_Event* e, bool isJumping) {
    const Uint8* key = SDL_GetKeyboardState(NULL); // get all pressed keys
    if (!isJumping) { // ground movement left || right
        if(key[SDL_SCANCODE_RIGHT]) {
            velocityX = SCREEN_HEIGHT / 75;
            rect.x += velocityX;
        }
        if(key[SDL_SCANCODE_LEFT]) {
            velocityX = SCREEN_HEIGHT / 75;
            rect.x -= velocityX;
        }
    }    
}

void Player::checkBorders() {
    if (rect.x > SCREEN_WIDTH - rect.w) {
        rect.x = SCREEN_WIDTH - rect.w;
    }
    if (rect.x + rect.w < rect.w) {
        rect.x = 0;
    }
}


bool Player::initBananaAttack(SDL_Rect* getenRect) {
    // rect init
    bananaRect.x = rect.x + rect.w;
    bananaRect.y = rect.y;
    bananaRect.h = 200;
    bananaRect.w = 200;

    // Finding smaller and bigger positions
    int minX = min(rect.x, getenRect->x);
    int minY = min(rect.y, getenRect->y);
    int maxX = max(rect.x, getenRect->x);
    int maxY = max(rect.y, getenRect->y);
    int a = maxY - minY;
    int b = maxX - minX;
    bananaVelX = sqrt(a*a + b*b); // Theoremus Pythagorus
    bananaVelY = SCREEN_HEIGHT >> 1;
    return true;
}

void Player::uninitBananaAttack() {
    bananaRect.h = bananaRect.w = 0;
    bananaVelX = bananaVelY = 0;
}

void Player::updateBanana() {
    bananaRect.x = bananaRect.x + bananaVelX * deltaTime;
    bananaRect.y = bananaRect.y - bananaVelY * deltaTime;
    bananaVelY = bananaVelY + bananaGravity * deltaTime;
}

void Player::drawBanana(SDL_Renderer* render) {
    SDL_RenderCopy(render, Player::bananaImage, NULL, &bananaRect);
}