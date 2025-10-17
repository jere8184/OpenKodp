
#pragma once

#include <string>

#include "SDL2/SDL_render.h"

using sprite_id = int;

struct sprite
{
	sprite(const std::string &name, sprite_id id, const std::string& file_path, SDL_Renderer& renderer) :
		name(name),
		id(id)
	{
		texture = load_texture(file_path, renderer);
	}

	~sprite()
	{
		SDL_DestroyTexture(texture);
	}

	static SDL_Texture* load_texture(const std::string& file_path, SDL_Renderer& renderer)
	{
		SDL_Surface* surface = SDL_LoadBMP(file_path.c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(&renderer, surface);
		SDL_FreeSurface(surface);
		return texture;
	}

	std::string name;
	sprite_id id;
	SDL_Texture* texture;
};