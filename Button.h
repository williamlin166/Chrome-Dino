#include"SDL2/SDL.h"
#include "LTexture.h"

class Button
{	
	public:
    	
    	Button();   	
    	Button(int x,int y,int w,int h);

    	//bool operator~();		//bool mouse_inside();
    	bool mouse_inside();
    	
    	void set_graph_path(const std::string path);
    	
		bool loadMedia(SDL_Renderer* renderer);
		
		void render(SDL_Renderer* renderer);
	
	private:

    	SDL_Point position;
    	
		int width;
		int height;
		
		std::string graph_path;
		
		LTexture ButtonTexture;
};
