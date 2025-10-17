
#pragma once 

#include <string>
#include <memory>
#include <vector>

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

#include "frontend/sprite.hpp"


struct window
{
	std::string name;
	SDL_Window* sdl_window;
	SDL_Renderer* sdl_render;
	std::vector<sprite*> sprites;

	window(const std::string& name, int width, int height)
	{
		this->sdl_window =SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
		this->sdl_render = SDL_CreateRenderer(this->sdl_window, -1, SDL_RENDERER_ACCELERATED);
	}

	void update()
	{
		SDL_RenderClear(this->sdl_render);
		
		for (sprite* sprite : this->sprites)
		{
			SDL_RenderCopy(this->sdl_render, sprite->texture, nullptr, nullptr);
		}

		SDL_RenderPresent(this->sdl_render);
	}

	~window()
	{
		SDL_DestroyRenderer(sdl_render);
		SDL_DestroyWindow(sdl_window);
	}
};