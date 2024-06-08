#pragma once
#include "SDL2/SDL.h"

//#include "LTexture.h"

extern const double  init_y_b, init_x_b,dt_b;
class Barrier
{
	friend class Dino;
	int frame;
	bool isUsing, lor;
	LTexture lSSTexture1;
	double x,y,n;
	
public:
	~Barrier();
	Barrier(int, double);
	double v;
	std::string image_path;
	double getx();
	void resetx();
	bool loadMedia(SDL_Renderer*); // load dino pic & cut it into pieces
	SDL_Rect bColliders;
	bool move(uint32_t,int);
	void render(SDL_Renderer*, bool); 

};
