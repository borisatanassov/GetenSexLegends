#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
using std::string;

class Text
{
	public:
		Text(int x, int y, int w, int h);
		virtual ~Text();
		static TTF_Font* font;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Color color;
		SDL_Rect rect;

		void setFontStyle(TTF_Font* font, int style);
		void initializeTexture(SDL_Renderer* render, const char* text);
		void draw(SDL_Renderer* render);
		void cleanUp();
};

#endif // TEXT_H
