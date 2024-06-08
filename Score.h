#include"SDL2/SDL.h"
#include "LTexture.h"

class Score
{	
	public:
  		
    	Score();   	
 		Score(int x,int y,int w,int h);
 		
 		void set_score_path(const std::string path[10]);
		bool loadMedia(SDL_Renderer* renderer);
		void render(SDL_Renderer* renderer,int digit);
 	
		int get_value();
		void set_value(int new_value);
		
	private:
    	
    	SDL_Point position;
    	
		int width;
		int height;
		
		int value;
		
		std::string score_path[10];
		LTexture ScoreTexture[10];
			
};
