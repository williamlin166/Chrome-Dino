#include "Brook.h"
#include<iostream>

Brook::Brook() : Dino(1.1, "./graph/brook.bmp")
{
	gph_srce2 = "./graph/brook2.bmp";
}

void Brook::printy()
{
	std::cout<<"y: "<<y<<"\n";
}

bool Brook::loadSecMedia(SDL_Renderer* renderer)
{
	bool success = true;
   	
   	printf("Brook loadSecMedia called\n");

   	//Load sprite sheet texture
   	if( !lSSTexture2.loadFromFile( gph_srce2, renderer ) ) // dino pic
   	{
       	printf( "Failed to load Brook second animation texture!\n" );
       	success = false;
   	}

   	return success;
}

void Brook::secRender(SDL_Renderer* renderer)
{
	SDL_Rect* currentClip = &rspriteClips[status * 2 + lor];
	lSSTexture2.render(init_x, y, renderer, currentClip);
	if(status == squat)
	{
		if(frame <= 13)
      		frame ++;
		else
		{
			frame = 0;
			lor = !lor;
		}
	}
	else
	{
		if(frame <= 10)
      		frame ++;
		else
		{
			frame = 0;
			lor = !lor;
		}
	}
}

