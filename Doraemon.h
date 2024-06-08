#include"Dino.h"
#include"LTexture.h"
#include<string>

class Doraemon : public Dino {
	
	int width_atk, height_atk;
	int CD, nog; // number of graph
	
	std::string atk_gph_srce, weapon_gph_srce;
	SDL_Rect rspriteClips_atk[ 6 ];
	LTexture lSSTexture_atk, weapon;
	SDL_Point weapon_pos;
	
public:
	
	Doraemon();
	
	void CD_tick();
	void printCD();
	void printy();
	void printWpnX();
	bool chkAtk();
	bool chkWpn(bool);
	bool loadAtkMedia(SDL_Renderer* renderer);
	bool loadWeaponMedia(SDL_Renderer* renderer);
	void render_atk(SDL_Renderer* renderer);
	void render_weapon(SDL_Renderer* renderer);
	
};
