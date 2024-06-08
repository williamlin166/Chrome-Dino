#include"SDL2/SDL.h"
#include"Score.h"
#include "LTexture.h"

Score::Score()
{
    position.x = 0;
    position.y = 0;
    
    width = 0;
    height = 0;
}

Score::Score(int x,int y,int w,int h)
{
	position.x = x;
    position.y = y;
	
	width = w;
    height = h;	
}

void Score::set_score_path(const std::string path[10])
{
	for(int i=0;i<10;i++)
	{
		score_path[i] = path[i];
	}		
}

bool Score::loadMedia(SDL_Renderer* renderer)
{
   	bool success = true;
   	
   	for(int i=0;i<10;i++)
	{
		if( !ScoreTexture[i].loadFromFile(score_path[i], renderer) )
   		{
    		printf( "Failed to load score texture!\n" );
    		success = false;
   		}
	}

   	return success;
}

void Score::render(SDL_Renderer* renderer,int digit)
{
	ScoreTexture[digit].render(position.x, position.y, renderer, NULL);
}

int Score::get_value()
{
	return value;
}

void Score::set_value(int new_value)
{
	value = new_value;
}

