/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLWindow
*/

#include "SDLWindow.hpp"

namespace arcade {
	SDLWindow::SDLWindow(std::string_view windowName)
	{
		window_.reset(SDL_CreateWindow(windowName.data(), SDL_WINDOWPOS_CENTERED,
									   SDL_WINDOWPOS_CENTERED, 1920, 1010, SDL_WINDOW_SHOWN));
		if (window_ == nullptr)
			throw error::GraphicError(SDL_GetError());

		renderer_.reset(SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED));
		if (renderer_ == nullptr)
			throw error::GraphicError(SDL_GetError());
	}

	FVector SDLWindow::getSize() const noexcept
	{
		int x = 0, y = 0;

		SDL_GetWindowSize(window_.get(), &x, &y);
		return {static_cast<float>(x), static_cast<float>(y)};
	}

	Input SDLWindow::getInput() noexcept
	{
		static std::unordered_map<SDL_Keycode, arcade::Input> SDLKeys(
			{{SDLK_a, arcade::Input::AKEY_A},
			 {SDLK_b, arcade::Input::AKEY_B},
			 {SDLK_c, arcade::Input::AKEY_C},
			 {SDLK_d, arcade::Input::AKEY_D},
			 {SDLK_e, arcade::Input::AKEY_E},
			 {SDLK_f, arcade::Input::AKEY_F},
			 {SDLK_g, arcade::Input::AKEY_G},
			 {SDLK_h, arcade::Input::AKEY_H},
			 {SDLK_i, arcade::Input::AKEY_I},
			 {SDLK_j, arcade::Input::AKEY_J},
			 {SDLK_k, arcade::Input::AKEY_K},
			 {SDLK_l, arcade::Input::AKEY_L},
			 {SDLK_m, arcade::Input::AKEY_M},
			 {SDLK_n, arcade::Input::AKEY_N},
			 {SDLK_o, arcade::Input::AKEY_O},
			 {SDLK_p, arcade::Input::AKEY_P},
			 {SDLK_q, arcade::Input::AKEY_Q},
			 {SDLK_r, arcade::Input::AKEY_R},
			 {SDLK_s, arcade::Input::AKEY_S},
			 {SDLK_t, arcade::Input::AKEY_T},
			 {SDLK_u, arcade::Input::AKEY_U},
			 {SDLK_v, arcade::Input::AKEY_V},
			 {SDLK_w, arcade::Input::AKEY_W},
			 {SDLK_x, arcade::Input::AKEY_X},
			 {SDLK_y, arcade::Input::AKEY_Y},
			 {SDLK_z, arcade::Input::AKEY_Z},
			 {SDLK_0, arcade::Input::AKEY_NUM0},
			 {SDLK_1, arcade::Input::AKEY_NUM1},
			 {SDLK_2, arcade::Input::AKEY_NUM2},
			 {SDLK_3, arcade::Input::AKEY_NUM3},
			 {SDLK_4, arcade::Input::AKEY_NUM4},
			 {SDLK_5, arcade::Input::AKEY_NUM5},
			 {SDLK_6, arcade::Input::AKEY_NUM6},
			 {SDLK_7, arcade::Input::AKEY_NUM7},
			 {SDLK_8, arcade::Input::AKEY_NUM8},
			 {SDLK_9, arcade::Input::AKEY_NUM9},
			 {SDLK_ESCAPE, arcade::Input::AKEY_ESC},
			 {SDLK_LCTRL, arcade::Input::AKEY_LCTRL},
			 {SDLK_LSHIFT, arcade::Input::AKEY_LSHIFT},
			 {SDLK_LALT, arcade::Input::AKEY_LALT},
			 {SDLK_LGUI, arcade::Input::AKEY_LSYSTEM},
			 {SDLK_RCTRL, arcade::Input::AKEY_RCTRL},
			 {SDLK_RSHIFT, arcade::Input::AKEY_RSHIFT},
			 {SDLK_RALT, arcade::Input::AKEY_RALT},
			 {SDLK_RGUI, arcade::Input::AKEY_RSYSTEM},
			 {SDLK_MENU, arcade::Input::AKEY_MENU},
			 {SDLK_LEFTBRACKET, arcade::Input::AKEY_LBRACKET},
			 {SDLK_RIGHTBRACKET, arcade::Input::AKEY_RBRACKET},
			 {SDLK_SEMICOLON, arcade::Input::AKEY_SEMICOLON},
			 {SDLK_COMMA, arcade::Input::AKEY_COMMA},
			 {SDLK_PERIOD, arcade::Input::AKEY_DOT},
			 {SDLK_QUOTE, arcade::Input::AKEY_QUOTE},
			 {SDLK_SLASH, arcade::Input::AKEY_SLASH},
			 {SDLK_BACKSLASH, arcade::Input::AKEY_BACKSLASH},
			 {SDLK_BACKQUOTE, arcade::Input::AKEY_TILDE},
			 {SDLK_EQUALS, arcade::Input::AKEY_EQUAL},
			 {SDLK_KP_EQUALS, arcade::Input::AKEY_EQUAL},
			 {SDLK_KP_EQUALSAS400, arcade::Input::AKEY_EQUAL},
			 {SDLK_MINUS, arcade::Input::AKEY_MINUS},
			 {SDLK_KP_ENTER, arcade::Input::AKEY_ENTER},
			 {SDLK_RETURN, arcade::Input::AKEY_ENTER},
			 {SDLK_SPACE, arcade::Input::AKEY_SPACE},
			 {SDLK_KP_SPACE, arcade::Input::AKEY_SPACE},
			 {SDLK_BACKSPACE, arcade::Input::AKEY_BACKSPACE},
			 {SDLK_KP_BACKSPACE, arcade::Input::AKEY_BACKSPACE},
			 {SDLK_TAB, arcade::Input::AKEY_TAB},
			 {SDLK_KP_TAB, arcade::Input::AKEY_TAB},
			 {SDLK_PAGEUP, arcade::Input::AKEY_PAGEUP},
			 {SDLK_PAGEDOWN, arcade::Input::AKEY_PAGEDOWN},
			 {SDLK_HOME, arcade::Input::AKEY_START},
			 {SDLK_END, arcade::Input::AKEY_END},
			 {SDLK_INSERT, arcade::Input::AKEY_INSERT},
			 {SDLK_DELETE, arcade::Input::AKEY_DELETE},
			 {SDLK_KP_PLUS, arcade::Input::AKEY_PLUS},
			 {SDLK_KP_MINUS, arcade::Input::AKEY_MINUS},
			 {SDLK_KP_MULTIPLY, arcade::Input::AKEY_MULTIPLY},
			 {SDLK_KP_DIVIDE, arcade::Input::AKEY_DIVIDE},
			 {SDLK_LEFT, arcade::Input::AKEY_LEFT},
			 {SDLK_RIGHT, arcade::Input::AKEY_RIGHT},
			 {SDLK_UP, arcade::Input::AKEY_UP},
			 {SDLK_DOWN, arcade::Input::AKEY_DOWN},
			 {SDLK_KP_0, arcade::Input::AKEY_NUMPAD0},
			 {SDLK_KP_1, arcade::Input::AKEY_NUMPAD1},
			 {SDLK_KP_2, arcade::Input::AKEY_NUMPAD2},
			 {SDLK_KP_3, arcade::Input::AKEY_NUMPAD3},
			 {SDLK_KP_4, arcade::Input::AKEY_NUMPAD4},
			 {SDLK_KP_5, arcade::Input::AKEY_NUMPAD5},
			 {SDLK_KP_6, arcade::Input::AKEY_NUMPAD6},
			 {SDLK_KP_7, arcade::Input::AKEY_NUMPAD7},
			 {SDLK_KP_8, arcade::Input::AKEY_NUMPAD8},
			 {SDLK_KP_9, arcade::Input::AKEY_NUMPAD9},
			 {SDLK_F1, arcade::Input::AKEY_F1},
			 {SDLK_F2, arcade::Input::AKEY_F2},
			 {SDLK_F3, arcade::Input::AKEY_F3},
			 {SDLK_F4, arcade::Input::AKEY_F4},
			 {SDLK_F5, arcade::Input::AKEY_F5},
			 {SDLK_F6, arcade::Input::AKEY_F6},
			 {SDLK_F7, arcade::Input::AKEY_F7},
			 {SDLK_F8, arcade::Input::AKEY_F8},
			 {SDLK_F9, arcade::Input::AKEY_F9},
			 {SDLK_F10, arcade::Input::AKEY_F10},
			 {SDLK_F11, arcade::Input::AKEY_F11},
			 {SDLK_F12, arcade::Input::AKEY_F12},
			 {SDLK_F13, arcade::Input::AKEY_F13},
			 {SDLK_F14, arcade::Input::AKEY_F14},
			 {SDLK_F15, arcade::Input::AKEY_F15},
			 {SDLK_PAUSE, arcade::Input::AKEY_NULL},
			 {SDLK_UNKNOWN, arcade::Input::AKEY_NULL}});
		SDL_Event event;

		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					return arcade::Input::AEVENT_STOP;
				case SDL_KEYDOWN:
					return SDLKeys[event.key.keysym.sym];
				default:
					break;
			}
		}
		return Input::AKEY_NULL;
	}

	void SDLWindow::clear() noexcept
	{
		SDL_RenderClear(renderer_.get());
	}

	void SDLWindow::refresh() noexcept
	{
		SDL_RenderPresent(renderer_.get());
	}

	void SDLWindow::draw(IImage &image) noexcept
	{
		auto &child = dynamic_cast<SDLImage &>(image);

		if (child.surface_ == nullptr)
			return;
		child.texture_.reset(SDL_CreateTextureFromSurface(renderer_.get(), child.surface_.get()));
		if (child.texture_ == nullptr)
			return;

		if (SDL_RenderCopyEx(renderer_.get(), child.texture_.get(), nullptr, &child.rect_,
							 child.rotation_, nullptr, SDL_FLIP_NONE) < 0)
			return;
	}

	void SDLWindow::draw(IText &text) noexcept
	{
		auto &child = dynamic_cast<SDLText &>(text);

		if (child.surface_ == nullptr)
			return;
		child.texture_.reset(SDL_CreateTextureFromSurface(renderer_.get(), child.surface_.get()));
		if (child.texture_ == nullptr)
			return;

		if (SDL_RenderCopyEx(renderer_.get(), child.texture_.get(), nullptr, &child.rect_,
							 child.rotation_, nullptr, SDL_FLIP_NONE) < 0)
			return;
	}
} // namespace arcade
