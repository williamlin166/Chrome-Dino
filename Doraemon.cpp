#include "Doraemon.h"
#include<iostream>

const int atkgph_width_n = 120;
const int atkgph_height_n = 103;
const int atkgph_width_s = 120;
const int atkgph_height_s = 103;
const int init_CD = 100;

const int weapon_init_x = init_x + 56 , weapon_init_y = init_y + 66;

Doraemon::Doraemon() : Dino(1.5, "./graph/doraemon.bmp"), CD(init_CD), nog(0)
{
	atk_gph_srce = "./graph/doraemon.bmp";
	weapon_gph_srce = "./graph/air cannon.bmp";
	width_atk = atkgph_width_n;
	height_atk = atkgph_height_n;
		
	weapon_pos = {weapon_init_x, weapon_init_y};
}

void Doraemon::CD_tick()
{
	if(CD>0) CD--;
}

void Doraemon::printCD()
{
	std::cout<<"CD: "<<CD<<"\n";
}

void Doraemon::printy()
{
	std::cout<<"y: "<<y<<"\n";
}

void Doraemon::printWpnX()
{
	std::cout<<"WpnX: "<<weapon_pos.x<<"\n";
}

bool Doraemon::loadWeaponMedia(SDL_Renderer* renderer)
{
	printf("doraemon loadWeaponMedia loaded\n");
	
	bool success = true;
	
	if( !weapon.loadFromFile( weapon_gph_srce, renderer ) ) // dino pic
   	{
       	printf( "Failed to load ninja weapon texture!\n" );
       	success = false;
   	}
   	
   	return success;
}

bool Doraemon::loadAtkMedia(SDL_Renderer* renderer)
{
	printf("doraemon loadAtkMedia loaded\n");
	
	bool success = true;

   	//Load sprite sheet texture
   	if( !lSSTexture_atk.loadFromFile( atk_gph_srce, renderer ) ) // dino pic
   	{
       	printf( "Failed to load doraemon walking animation texture!\n" );
       	success = false;
   	}
   	else
   	{
       	//Set sprite clips
       	for(int i=0; i<4; i++)
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

bool Doraemon::chkAtk()
{
	return ((CD==0) && (y >= init_y));
}

bool Doraemon::chkWpn(bool atk)
{
	return (atk || (weapon_pos.x>weapon_init_x));
}

void Doraemon::render_atk(SDL_Renderer* renderer)
{
	if(nog < 4)
	{
		SDL_Rect* currentClip = &rspriteClips_atk[nog];
		lSSTexture_atk.render(x, y, renderer, currentClip);
		SDL_RenderPresent( renderer );
		if(frame - 10)
      		frame ++;
		else
		{
			frame = 0;
			nog++;
		}
	}
	else
	{
		nog = 0;
		CD = init_CD;
	}
}

void Doraemon::render_weapon(SDL_Renderer* renderer)
{
	if(weapon_pos.x < 1400)
	{
		weapon.render(weapon_pos.x, weapon_pos.y, renderer);
		weapon_pos.x += 4;
	}
	else
	{
		weapon_pos.x = weapon_init_x;
	}
}
