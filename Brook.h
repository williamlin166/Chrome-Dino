#include"Dino.h"
#include"LTexture.h"
#include<string>

class Brook : public Dino {
	
	LTexture lSSTexture2;
	std::string gph_srce2;
	
public:
	
	Brook();
	
	void printy();
	bool loadSecMedia(SDL_Renderer* renderer);
	void secRender(SDL_Renderer* renderer);
	
};
