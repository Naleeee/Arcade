/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLDeleters
*/

#ifndef SDLDELETERS_HPP_
#define SDLDELETERS_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

namespace arcade {
	struct SDLWindowDeleter {
		void operator()(SDL_Window *window);
	};

	struct SDLRendererDeleter {
		void operator()(SDL_Renderer *renderer);
	};

	struct SDLSurfaceDeleter {
		void operator()(SDL_Surface *surface);
	};

	struct SDLTextureDeleter {
		void operator()(SDL_Texture *texture);
	};

	struct SDLFontDeleter {
		void operator()(TTF_Font *font);
	};

	struct SDLSoundDeleter {
		void operator()(Mix_Chunk *sound);
	};

	using SDLWindowPtr = std::unique_ptr<SDL_Window, SDLWindowDeleter>;
	using SDLRendererPtr = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>;
	using SDLSurfacePtr = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>;
	using SDLTexturePtr = std::unique_ptr<SDL_Texture, SDLTextureDeleter>;
	using SDLFontPtr = std::unique_ptr<TTF_Font, SDLFontDeleter>;
	using SDLSoundPtr = std::unique_ptr<Mix_Chunk, SDLSoundDeleter>;
} // namespace arcade

#endif /* !SDLDELETERS_HPP_ */
