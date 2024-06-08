#include "Luffy.h"
#include<iostream>

const int atkgph_width = 549;
const int atkgph_height = 103;
const int fist_init_x = init_x + 56 , fist_init_y = init_y + 66;
const int fist_width = 50, fist_height = 30;

const int weapon_init_x = init_x + 56 , weapon_init_y = init_y + 66;

Luffy::Luffy() : Dino(1.2, "./graph/luffy.bmp"), CD(0), nog(0), width_atk(atkgph_width), height_atk(atkgph_height), atk_gph_srce("./graph/luffy_atk.bmp"), frame_atk(0)
{
	fist = {fist_init_x, fist_init_y, 50, 30};
	weapon_pos = {weapon_init_x, weapon_init_y};
}


void Luffy::CD_tick()
{
	if(CD>0) CD--;
}

void Luffy::printCD()
{
	std::cout<<"CD: "<<CD<<"\n";
}

int Luffy::getCD ()const
{
	return CD;
}

void Luffy::printy()
{
	std::cout<<"y: "<<y<<"\n";
}

bool Luffy::chkWpn(bool atk)
{
	return (atk || (weapon_pos.x>weapon_init_x));
}
bool Luffy::colatk(Barrier *b){
	if(fist.x+50>b->getx())return true;
	else return false;
}
bool Luffy::operator-(Barrier *b){
	if(fist.x+50>b->getx())return true;
	else return false;	
}
bool Luffy::loadAtkMedia(SDL_Renderer* renderer)
{
	printf("luffy loadAtkMedia loaded\n");
	
	bool success = true;

   	//Load sprite sheet texture
   	if( !lSSTexture_atk.loadFromFile( atk_gph_srce, renderer ) ) // dino pic
   	{
       	printf( "Failed to load walking animation texture!\n" );
       	success = false;
   	}
   	else
   	{
       	//Set sprite clips
       	for(int i=0; i<12; i++)
       	{
       		rspriteClips_atk[i].x = width_atk*i;
       		//std::cout<<rspriteClips_atk[i].x<<" ";
       		rspriteClips_atk[i].y = 0;
       		//std::cout<<rspriteClips_atk[i].y<<" ";
			rspriteClips_atk[i].w = width_atk;
			//std::cout<<rspriteClips_atk[i].w<<" ";
       		rspriteClips_atk[i].h = height_atk;
       		//std::cout<<rspriteClips_atk[i].h<<"\n";
	    }
    }

   	return success;
}

bool Luffy::loadRed(SDL_Renderer* renderer)
{
	//printf("luffy loadRed loaded\n");
	
	bool success = true;

   	//Load sprite sheet texture
   	if( !test_red.loadFromFile( "./graph/red.bmp", renderer ) ) // dino pic
   	{
       	printf( "Failed to load walking animation texture!\n" );
       	success = false;
   	}

   	return success;
}

bool Luffy::chkAtk()
{
//	std::cout<<"CD: "<<CD<<" y: "<<y<<" ini_y: "<<init_y<<"\n";
	return ((CD==0) && (y >= init_y));
}

void Luffy::render_atk(SDL_Renderer* renderer)
{
	if(nog < 12)
	{
		SDL_Rect* currentClip = &rspriteClips_atk[nog];
		//std::cout<<"luffy render: ";
		lSSTexture_atk.render(x, y, renderer, currentClip);
		//std::cout<<"fist render: ";
		//test_red.render(fist.x, fist.y, renderer);
		
		
		if(frame_atk - 10)
      		frame_atk ++;
		else
		{
			frame_atk = 0;
			nog++;
			fist.x += 40;
		}
	}
	else
	{
		nog = 0;
		CD = 1000;
		fist.x = fist_init_x;
	}
	//std::cout<<"fist: "<<fist.x<<" "<<fist.y<<" "<<fist.w<<" "<<fist.h<<"\n";
}
