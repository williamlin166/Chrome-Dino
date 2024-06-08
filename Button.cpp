#include"SDL2/SDL.h"
#include"Button.h"
#include "LTexture.h"

Button::Button()
{
    position.x = 0;
    position.y = 0;
    
    width = 0;
    height = 0;
}

Button::Button(int x,int y,int w,int h)
{
	position.x = x;
    position.y = y;
	
	width = w;
    height = h;	
}

//bool Button::operator~()			//bool Button::mouse_inside()
bool Button::mouse_inside()
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

void Button::set_graph_path(const std::string path)
{
	graph_path = path;
}

bool Button::loadMedia(SDL_Renderer* renderer)
{
   	bool success = true;
   	
   	if( !ButtonTexture.loadFromFile( graph_path, renderer ) )
   	{
       	printf( "Failed to load button texture!\n" );
       	success = false;
   	}

   	return success;
}

void Button::render(SDL_Renderer* renderer)
{
	ButtonTexture.render(position.x, position.y, renderer, NULL);
}
