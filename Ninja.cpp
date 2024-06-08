#include "Ninja.h"
#include<iostream>

const int atkgph_width_n = 120;
const int atkgph_height_n = 103;
const int atkgph_width_s = 120;
const int atkgph_height_s = 103;
const int init_CD = 1000;

const int weapon_init_x = init_x + 56 , weapon_init_y = init_y;

Ninja::Ninja(int a) : Dino(1, ""), CD(init_CD), nog(0)
{
	switch(a)
	{
		case 0:
			gph_srce = "./graph/naruto.bmp";
			atk_gph_srce = "./graph/naruto.bmp";
			weapon_gph_srce = "./graph/rasengan.bmp";
			width_atk = atkgph_width_n;
			height_atk = atkgph_height_n;
			break;
		
		case 1:
			gph_srce = "./graph/sasuke.bmp";
			atk_gph_srce = "./graph/sasuke.bmp";
			weapon_gph_srce = "./graph/fireball.bmp";
			width_atk = atkgph_width_s;
			height_atk = atkgph_height_s;
			break;
	}
	
	weapon_pos = {weapon_init_x, weapon_init_y};
}

void Ninja::operator~()
{
	std::cout<<"ninja reset.\n";
	status = run;
	y = init_y+1;
	frame = 0;
	lor = 0;
	ajt = false;
	release_up = true;
	extra_life = true;
	CD = 0;
}

void Ninja::CD_tick()
{
	if(CD>0) CD--;
}

void Ninja::printCD()
{
	std::cout<<"CD: "<<CD<<"\n";
}

int Ninja::getCD() const
{
	return CD;
}

int Ninja::getStatus()const
{
	return status;
}

void Ninja::printy()
{
	std::cout<<"y: "<<y<<"\n";
}

void Ninja::printWpnX()
{
	std::cout<<"WpnX: "<<weapon_pos.x<<"\n";
}

bool Ninja::loadWeaponMedia(SDL_Renderer* renderer)
{
//	printf("ninja loadWeaponMedia loaded\n");
	
	bool success = true;
	
	if( !weapon.loadFromFile( weapon_gph_srce, renderer ) ) // dino pic
   	{
       //	printf( "Failed to load ninja weapon texture!\n" );
       	success = false;
   	}
   	
   	return success;
}

bool Ninja::loadAtkMedia(SDL_Renderer* renderer)
{
//	printf("ninja loadAtkMedia loaded\n");
	
	bool success = true;

   	//Load sprite sheet texture
   	if( !lSSTexture_atk.loadFromFile( atk_gph_srce, renderer ) ) // dino pic
   	{
       	printf( "Failed to load ninja walking animation texture!\n" );
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

bool Ninja::loadRed(SDL_Renderer* renderer)
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

bool Ninja::chkAtk()
{
	return ((CD==0) && (y >= init_y));
}

bool Ninja::chkWpn(bool atk)
{
	return (atk || (weapon_pos.x>weapon_init_x));
}

void Ninja::render_atk(SDL_Renderer* renderer)
{
	if(nog < 2)
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



bool Ninja::operator-(Barrier *b){
	if(weapon_pos.x+weapon.getWidth()>b->getx())return true;
	else return false ;	
}
void Ninja::render_weapon(SDL_Renderer* renderer)
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
