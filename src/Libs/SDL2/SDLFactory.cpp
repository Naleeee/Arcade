/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLFactory
*/

#include "SDLFactory.hpp"

namespace arcade {
	SDLFactory::~SDLFactory() noexcept
	{
		Mix_CloseAudio();
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	std::unique_ptr<IWindow> SDLFactory::createWindow(std::string_view windowName) const
	{
		return std::make_unique<SDLWindow>(windowName);
	}

	std::unique_ptr<IImage> SDLFactory::createImage(std::string_view filePath) const
	{
		return std::make_unique<SDLImage>(filePath);
	}

	std::unique_ptr<IText> SDLFactory::createText(std::string_view filePath) const
	{
		return std::make_unique<SDLText>(filePath);
	}

	std::unique_ptr<ISound> SDLFactory::createSound(std::string_view filePath) const
	{
		return std::make_unique<SDLSound>(filePath);
	}

	extern "C" std::unique_ptr<IGraphicFactory> createGraphicFactory()
	{
		if (!getenv("DISPLAY")) {
			throw error::GraphicError("No display variable in environment");
		}
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
			throw error::GraphicError(SDL_GetError());
		}
		if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
			throw error::GraphicError(IMG_GetError());
		}
		if (TTF_Init() < 0) {
			throw error::GraphicError(TTF_GetError());
		}
		if (Mix_Init(MIX_INIT_OGG) < 0) {
			throw error::GraphicError(Mix_GetError());
		}
		if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) {
			throw error::GraphicError(Mix_GetError());
		}
		return std::make_unique<SDLFactory>();
	}
} // namespace arcade
