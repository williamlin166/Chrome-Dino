#include"Dino.h"
#include"LTexture.h"
#include<string>

class Luffy : public Dino {
	
	const int width_atk, height_atk;
	int nog; // number of graph
	
	std::string atk_gph_srce;
	SDL_Rect rspriteClips_atk[ 12 ];
	LTexture lSSTexture_atk;
	SDL_Rect fist;
	SDL_Point weapon_pos;
	int frame_atk;
	
public:
	
	int CD;
	LTexture test_red;	
	Luffy();	
	void CD_tick();
	void printCD();
	void printy();
	int getCD()const;
	bool chkAtk();
	bool colatk(Barrier *b);
	bool operator-(Barrier *);
	bool chkWpn(bool);
	bool loadAtkMedia(SDL_Renderer* renderer);
	bool loadRed(SDL_Renderer*);
	void render_atk(SDL_Renderer* renderer);
	
};
