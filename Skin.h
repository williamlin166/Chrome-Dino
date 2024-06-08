#include"SDL2/SDL.h"
#include "LTexture.h"

extern const int lock_width;
extern const int lock_height;

class Skin
{	
	public:
    	
    	bool unlock;
    	
    	Skin();   	
    	Skin(int x,int y,int w,int h,bool unlock_initial,int unlock_score_initial);
		
    	//bool operator~();		//bool mouse_inside();
    	bool mouse_inside();
    	
    	void set_skin_path(const std::string path);   	
		bool loadMedia_skin(SDL_Renderer* renderer);		
		void render_skin(SDL_Renderer* renderer);
		
		void set_lock_path(std::string path);   	
		bool loadMedia_lock(SDL_Renderer* renderer);		
		void render_lock(SDL_Renderer* renderer);
		
		int get_unlock_score();
		
	private:

    	SDL_Point position;
    	
		int width;
		int height;
		
		int unlock_score;
		
		std::string skin_path;
		std::string lock_path;
		
		LTexture SkinTexture;		
		LTexture LockTexture;
};
