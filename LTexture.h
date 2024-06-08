#include "SDL2/SDL.h"
#include<string>
#include<stdint.h>
#pragma once

class LTexture
{
	public:
    	LTexture();
    	~LTexture();
    	bool loadFromFile( std::string path, SDL_Renderer* renderer );
    	void operator~();
    	void setColor( Uint8 red, Uint8 green, Uint8 blue );
    	void setBlendMode( SDL_BlendMode blending );
    	void setAlpha( Uint8 alpha );
    	void render( int, int, SDL_Renderer* renderer, SDL_Rect* clip = NULL);
    	int getWidth()const;
    	int getHeight()const;
	
	private:
    	SDL_Texture* mTexture;
    	int mWidth;
    	int mHeight;
};
