/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLDeleters
*/

#include "SDLDeleters.hpp"

namespace arcade {
	void SDLWindowDeleter::operator()(SDL_Window *window)
	{
		SDL_DestroyWindow(window);
	}

	void SDLRendererDeleter::operator()(SDL_Renderer *renderer)
	{
		SDL_DestroyRenderer(renderer);
	}

	void SDLSurfaceDeleter::operator()(SDL_Surface *surface)
	{
		SDL_FreeSurface(surface);
	}

	void SDLTextureDeleter::operator()(SDL_Texture *texture)
	{
		SDL_DestroyTexture(texture);
	}

	void SDLFontDeleter::operator()(TTF_Font *font)
	{
		TTF_CloseFont(font);
	}

	void SDLSoundDeleter::operator()(Mix_Chunk *sound)
	{
		Mix_FreeChunk(sound);
	}
} // namespace arcade