#include "Todoroki.h"
#include "Globals.h"

Todoroki::Todoroki() {
    rect.h = 160;
    rect.w = 110;
    rect.x = 1920;//SCREEN_WIDTH - SCREEN_WIDTH / 4;
    rect.y = SCREEN_HEIGHT - rect.h - 160; // spawn position on y; idk why it works this way
}


Todoroki::~Todoroki()
{
    //dtor
}
