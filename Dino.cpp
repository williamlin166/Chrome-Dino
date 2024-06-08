#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include "LTexture.h"
#include "Dino.h"
#include "Barrier.h"
#include <iostream>
#include <string>

const double dt = 0.05f, gravity = 60.0f, init_y = 250.0f;
const int graph_width = 120, graph_height = 103, init_x = 10;

Dino::Dino(double n, std::string str) : x(init_x), width(graph_width), height(graph_height), g(gravity), ajt(false), release_up(true), init_v(120.0f*n), extra_life(true)
{
	y = init_y;
	frame = 0;
	lor = 0;
	v = 0;
	gph_srce = str;
	//jump_snd_srce = "./mp3/Dino jump.mp3";

}

void Dino::operator~()
{
	std::cout<<"dino reset.\n";
	status = run;
	y = init_y+1;
	frame = 0;
	lor = 0;
	ajt = false;
	release_up = true;
	extra_life = true;
}

bool Dino::loadMedia(SDL_Renderer* renderer) // load dino pic & cut it into pieces
{
   	bool success = true;
   	
   	printf("dino loadMedia called\n");

   	//Load sprite sheet texture
   	if( !lSSTexture.loadFromFile( gph_srce, renderer ) ) // dino pic
   	{
       	printf( "Failed to load walking animation texture!\n" );
       	success = false;
   	}
   	else
   	{
       	//Set sprite clips
       	for(int i=0; i<7; i++)
       	{
       		rspriteClips[i].x = width*i;
       		rspriteClips[i].y = 0;
       		rspriteClips[i].w = width;
       		rspriteClips[i].h = height;
	    }
	    dColliders[0].x = init_x+40.0f;
      	dColliders[0].y = init_y;
       	dColliders[0].w = 40.0f;
       	dColliders[0].h = 30.0f;
       	dColliders[1].x = init_x;
      	dColliders[1].y = init_y+30.0f;
       	dColliders[1].w = 56.0f;
       	dColliders[1].h = 28.0f;
       	dColliders[2].x = init_x+20.0f;
      	dColliders[2].y = init_y+30.0f+24.0f;
       	dColliders[2].w = 32.0f;
       	dColliders[2].h = 24;
       	dColliders[3].x = init_x;
      	dColliders[3].y = init_y+30.0f;
       	dColliders[3].w = 95;
       	dColliders[3].h = 10000;
    }

   	return success;
}

bool Dino::loadMusic()
{
	bool success = true;
   	
   	printf("dino loadMusic called\n");
	
	Mix_Music* music = Mix_LoadMUS("./mp3/Dino jump.mp3");
	
	std::cout<<"music: "<<music<<"\n";
	
	//if(!music) {
    //    std::cout << "Mix_LoadMUS(\"song1.mp3\"): %s\n" << Mix_GetError();
    //    success = false;
    //}
    //else
    {
    	mJump = music;
	}
	//Mix_PlayMusic(mJump, 1);
	
	//std::cout<<"mJump: "<<mJump<<"\n";

   	return success;
}
	
void Dino::setRec()
{
	this -> rPosition.x = this -> x;
   	this -> rPosition.y = this -> y;
   	this -> rPosition.w = width;
   	this -> rPosition.h = height;
}

void Dino::move(Key key, Barrier *b, State& state, Character& chr)
{
	bool col = false;
	bool dj = (chr == cNaruto || chr == cSasuke);
	bool wat = (chr == cNaruto || chr == cSasuke || chr == cBrook);
	
	//std::cout<<"mJump(in move): "<<mJump<<"\n";
	
	// set the correct Y value
	
	if(key == up || y < init_y)                 // °_¸õ
		status = jump;
	else if(key == down && this -> y >= init_y) // ÃÛ¤U 
		status = squat;
	else
		status = run;
	
	if(key != up)
		release_up = true;
	
	if(y > init_y)
	{
		y = init_y;
		v = 0;
		ajt = false;
	}
	else if(y == init_y && status == jump)
	{
		v = -init_v;
		release_up = false;
	}
	else if(key == up && dj && !ajt && release_up)
	{
		std::cout<<"double!\n";
		v = -init_v;
		ajt = true;
		release_up = false;
	}
	else
	{
		v += g * dt;
	}
	y += v * dt;
	
	dColliders[0].y = y;
   	dColliders[1].y = y+30.0f;
   	dColliders[2].y = y+30.0f+24.0f;
   	dColliders[3].y = y;
	
	if(key==down)
	{
		if(wat&&(b->n==6 || b->n==7)){}
		else if(checkCollision(key,dColliders[3],b->bColliders))
		col = true;
	}
	else 
		for(int i=0;i<3;i++)
		{
			
		if(wat&&(b->n==6 || b->n==7)){}
		else if(checkCollision(key,dColliders[i],b->bColliders))
				col = true;
		}
	if(col && (chr == cBrook) && extra_life)
	{
		chr = cSecBrook;
		extra_life = false;
	}
	else if(col)
		state = end;
	
	setRec();
	
}
bool Dino::checkCollision(Key k,SDL_Rect&a,SDL_Rect&b){
	double leftA, leftB;
    double rightA, rightB;
    double topA, topB;
    double bottomA, bottomB;
	//std::cout<<"wei";
    //Go through the A boxes
     
        //Calculate the sides of rect A
        leftA = a.x;
        rightA = a.x + a.w;
        topA = a.y;
        bottomA = a.y + a.h;
	
        //Go through the B boxes
          //Calculate the sides of rect B
            leftB = b.x;//std::cout<<b.x<<' ';
            rightB = b.x + b.w;
            topB = b.y;
            bottomB = b.y + b.h;
			
			/*std::cout<<topA<<' '<<bottomB<<' ';
			std::cout<<topB<<' '<<bottomA<<' ';
			std::cout<<rightA<<' '<<leftB<<' ';
			std::cout<<leftA<<' '<<rightB<<' ';*/
            //If no sides from A are outside of B
            if( bottomA <= topB )
    		{
       		 return false;
  			}
   			 if( topA >= bottomB )
   			{
        	return false;
    		}
    		if( rightA <= leftB )
    		{
        	return false;
    		}
    		if( leftA >= rightB )
    		{
        	return false;
    		}
  			std::cout<<"wei<3";
    		
			return true;

}
void Dino::operator>>(SDL_Renderer* renderer)
{
	SDL_Rect* currentClip = &rspriteClips[status * 2 + lor];
	lSSTexture.render(x, y, renderer, currentClip);
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

void Dino::render_d(SDL_Renderer* renderer)
{
	SDL_Rect* currentClip = &rspriteClips[6];
	lSSTexture.render(init_x, y, renderer, currentClip);
	
}
