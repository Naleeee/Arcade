/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLWindow
*/

#ifndef SDLWINDOW_HPP_
#define SDLWINDOW_HPP_

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SDLDeleters.hpp"
#include "SDLImage.hpp"
#include "SDLText.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <unordered_map>

namespace arcade {
	class SDLWindow : public IWindow {
	public:
		SDLWindow() = default;
		explicit SDLWindow(std::string_view windowName);
		SDLWindow(SDLWindow const &other) = delete;
		SDLWindow(SDLWindow &&other) = delete;
		~SDLWindow() noexcept = default;
		SDLWindow &operator=(SDLWindow const &other) = delete;
		SDLWindow &operator=(SDLWindow &&other) = delete;

		// GETTERS
		FVector getSize() const noexcept final;
		Input getInput() noexcept final;

		// FUNCTIONS
		void clear() noexcept final;
		void refresh() noexcept final;
		void draw(IImage &) noexcept final;
		void draw(IText &) noexcept final;

	private:
		SDLWindowPtr window_;
		SDLRendererPtr renderer_;
	};
} // namespace arcade
#endif /* !SDLWINDOW_HPP_ */
