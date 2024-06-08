#include"SDL2/SDL.h"
#include"Skin.h"
#include "LTexture.h"

const int lock_width = 150;
const int lock_height = 90;

Skin::Skin()
{
    position.x = 0;
    position.y = 0;
    
    width = 0;
    height = 0;
}

Skin::Skin(int x,int y,int w,int h,bool unlock_initial,int unlock_score_initial)
{
	position.x = x;
    position.y = y;
	
	width = w;
    height = h;	
    
    unlock = unlock_initial;
    unlock_score = unlock_score_initial;
}

//bool Skin::operator~()		//bool Skin::mouse_inside()
bool Skin::mouse_inside()
{	
	int mouse_x=0;
	int mouse_y=0;
	
	SDL_GetMouseState(&mouse_x,&mouse_y);
	
	bool inside = true;	
	
	if(mouse_x < position.x) {inside = false;}
	else if(mouse_x > position.x + width) {inside = false;}
	else if(mouse_y < position.y) {inside = false;}
	else if(mouse_y > position.y + height) {inside = false;}
	
	return inside;	
}

void Skin::set_skin_path(const std::string path)
{
	skin_path = path;
}

bool Skin::loadMedia_skin(SDL_Renderer* renderer)
{
   	bool success = true;
   	
   	if( !SkinTexture.loadFromFile( skin_path, renderer ) )
   	{
       	printf( "Failed to load skin texture!\n" );
       	success = false;
   	}

   	return success;
}

void Skin::render_skin(SDL_Renderer* renderer)
{
	SkinTexture.render(position.x, position.y, renderer, NULL);
}

void Skin::set_lock_path(std::string path)
{
	lock_path = path;
}

bool Skin::loadMedia_lock(SDL_Renderer* renderer)
{
   	bool success = true;
   	
   	if( !LockTexture.loadFromFile( lock_path, renderer ) )
   	{
       	printf( "Failed to load lock texture!\n" );
       	success = false;
   	}

   	return success;
}

void Skin::render_lock(SDL_Renderer* renderer)
{
	LockTexture.render(position.x+width/2-lock_width/2, position.y+height/2-lock_height/2, renderer, NULL);
}

int Skin::get_unlock_score()
{
	return unlock_score;
}
