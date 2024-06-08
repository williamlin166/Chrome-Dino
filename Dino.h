#include"SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include"LTexture.h"
#include"Barrier.h"
#pragma once

extern const double dt, g, init_y;
extern const int graph_width, graph_height, init_x;
extern const int window_size_width, window_size_height, window_position_x, window_position_y;

enum Key { none, up, down };
enum Status { run, jump, squat, dead };
enum State { home, playing, shop, end };
enum Character {cDino, cLuffy, cBrook, cSasuke, cNaruto, cDoraemon, cSecBrook};

class Dino
{
	const int width, height;
	SDL_Rect rPosition;
	const double g;
	const double init_v;
	double v;
	
protected:
	const int x;
	      int frame;
	double y;
	bool ajt;   // already jump twice
	bool release_up;
	double extra_life;
	SDL_Rect rspriteClips[ 7 ];
	Status status;
	bool lor;   // left_of_right: 0 for left, 1 for right. 
	
	std::string gph_srce;    //graph_source
	
	std::string jump_snd_srce;
	Mix_Music* mJump, *mDead;
	
	LTexture lSSTexture;    //sprite sheet texture
	SDL_Rect dColliders[4];
	
public:
	
	Dino(double, std::string);
	void operator~ ();
	bool loadMedia(SDL_Renderer*); // load dino pic & cut it into pieces
	bool loadMusic();
	void setRec();
	void move(Key, Barrier*, State&, Character&);
	void dble_jump();
	void move(Key);
	bool checkCollision(Key, SDL_Rect&, SDL_Rect&);
	void operator>>(SDL_Renderer*); 
	void render_d(SDL_Renderer*);
	
};
