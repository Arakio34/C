#define <stdio.h>
#define <stdlib.h>
#define <SDL2/SDL.h>

int main(){
	SDL_Window *window=NULL;
	if(0 != SDL_Init(SDL_INIT_VIDEO)){
		fprintf(stderr, "Erreur SDLINIT : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 640 , 480,SDL_WINDOW_SHOWN);
	if(NULL==window){
		fprintf(stderr,"Erreur SDL_CreatWindow : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	SDL_Quit();
return EXIT_SUCCESS;
}
