
#include "SDL2/SDL.h"
#include "LTexture.h"
#include "Barrier.h"
#include <iostream>
#include <cmath>
using namespace std;
const double init_y_b=100.0f, init_x_b = 1600.0f,dt_b =0.05f;

Barrier::Barrier(int a, double t) 
{
	//std::cout<<t;
	v = t;
	n = a;
	
	frame = 0;
	lor = false;
	x = init_x_b;
	isUsing = false;

	switch(a){
		case 0:			
			image_path = "./graph/bird.bmp";
			//testRec = "./graph/test 0.bmp";
			y=init_y_b+110;
			bColliders.x = init_x_b+6;
		  	bColliders.y = y+2;
		   	bColliders.w = 72.0f;
		   	bColliders.h = 30.0f;
		   	
		   	break;
		case 1:
			image_path = "./graph/bird.bmp";
			//testRec = "./graph/test 0.bmp";
			y=init_y_b+65;
			bColliders.x = init_x_b+6;
		  	bColliders.y = y+2;
		   	bColliders.w = 72.0f;
		   	bColliders.h = 30.0f;
		   	break;
		case 2:
			image_path = "./graph/cactus1.bmp";
			//testRec = "./graph/test1.bmp";
			y=init_y_b+160;
			bColliders.x = init_x_b+2;
		  	bColliders.y = y+2;
		   	bColliders.w = 42.0f;
		   	bColliders.h = 100.0f;
		   	break;
		case 3:
			image_path = "./graph/cactus2.bmp";
		//	testRec = "./graph/test2.bmp";
			y=init_y_b+160;
			bColliders.x = init_x_b+2;
		  	bColliders.y = y+2;
		   	bColliders.w = 93.0f;
		   	bColliders.h = 100.0f;
		   	break;
		case 4:
			image_path = "./graph/cactus3.bmp";
			//testRec = "./graph/test3.bmp";
			y=init_y_b+160;
			bColliders.x = init_x_b+2;
		  	bColliders.y = y+2;
		   	bColliders.w = 140.0f;
		   	bColliders.h = 100.0f;
		   	break;
		case 5:
			image_path = "./graph/cactus4.bmp";
		//	testRec = "./graph/test4.bmp";
			y=init_y_b+160;
			bColliders.x = init_x_b+2;
		  	bColliders.y = y+2;
		   	bColliders.w = 142.0f;
		   	bColliders.h = 100.0f;
		   	break;
		case 6:
			image_path = "./graph/water3.bmp";
		//	testRec = "./graph/test5.bmp";
			y=init_y_b+242;
			bColliders.x = init_x_b+2;
		  	bColliders.y = y-20;
		   	bColliders.w = 85.0f;
		   	bColliders.h = 45.0f;
		   	break;
		case 7:
			image_path = "./graph/water4.bmp";
			//testRec = "./graph/test6.bmp";
			y=init_y_b+242;
			bColliders.x = init_x_b+2;
		  	bColliders.y = y-20;
		   	bColliders.w = 114.0f;
		   	bColliders.h = 45.0f;
		   	break;
	};

}

double Barrier::getx()
{
	return x;
}

void Barrier::resetx()
{
	x=init_x_b;	
}

Barrier::~Barrier(){
	
}

bool Barrier::loadMedia(SDL_Renderer* renderer) // load dino pic & cut it into pieces
{
   	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !lSSTexture1.loadFromFile( image_path, renderer  ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;

}

bool Barrier::move(uint32_t duration,int score)
{
	bool del = true;
	if(x<-300){
		bColliders.x = init_x_b;
		x = init_x_b;
		del = false;
	}
	
	v -= double(score)/5000.0f;
	x += v * dt_b;
	
	bColliders.x = x;
	
	return del;
	//	std::cout<<bColliders.y;
}
	
void Barrier::render(SDL_Renderer* renderer, bool state)
{
	if(n == 0 || n == 1)
	{
		SDL_Rect currentClip = {91.0f*lor, 0, 91.0f, 82.0f};
		lSSTexture1.render(x, y, renderer, &currentClip);
		if(!state)
		{
			if(frame <= 30)
	      		frame ++;
			else
			{
				frame = 0;
				lor = !lor;
			}
		}
	}
	else
		lSSTexture1.render(x, y, renderer, NULL);
}
