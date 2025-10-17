
#include <stdio.h>
#include <SDL2/SDL.h>

#include "frontend/widgets/button.hpp"
#include "frontend/window.hpp"
#include "frontend/sprite.hpp"

int main(int argc, char** argv)
{
	//Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}


	window window("King of Dragon Pass", 800, 600);

	sprite sprite("mushroom", 0, "./mushroom.bmp", *window.sdl_render);
	
	window.sprites.push_back(&sprite);

	//SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);

	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			window.update();
		}
	}

	SDL_Quit();

	return 0;
}