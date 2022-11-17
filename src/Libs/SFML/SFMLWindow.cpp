/*
** EPITECH PROJECT, 2022
** Window
** File description:
** window
*/

#include "SFMLWindow.hpp"

#include "SFMLImage.hpp"
#include "SFMLSound.hpp"
#include "SFMLText.hpp"

namespace arcade {

	// CTOR / DTOR
	SFMLWindow::SFMLWindow(std::string_view windowName)
	{
		window_.create(sf::VideoMode(1920, 1010), std::string(windowName));
		window_.setFramerateLimit(60);
	}

	// NOLINTNEXTLINE
	SFMLWindow::~SFMLWindow()
	{
		window_.close();
	}

	// GETTERS
	FVector SFMLWindow::getSize() const noexcept
	{
		return FVector {static_cast<float>(window_.getSize().x),
						static_cast<float>(window_.getSize().y)};
	}

	Input SFMLWindow::getInput() noexcept
	{
		static std::unordered_map<sf::Keyboard::Key, arcade::Input> SFMLKeys({
			{sf::Keyboard::Key::A, arcade::Input::AKEY_A},
			{sf::Keyboard::Key::B, arcade::Input::AKEY_B},
			{sf::Keyboard::Key::C, arcade::Input::AKEY_C},
			{sf::Keyboard::Key::D, arcade::Input::AKEY_D},
			{sf::Keyboard::Key::E, arcade::Input::AKEY_E},
			{sf::Keyboard::Key::F, arcade::Input::AKEY_F},
			{sf::Keyboard::Key::G, arcade::Input::AKEY_G},
			{sf::Keyboard::Key::H, arcade::Input::AKEY_H},
			{sf::Keyboard::Key::I, arcade::Input::AKEY_I},
			{sf::Keyboard::Key::J, arcade::Input::AKEY_J},
			{sf::Keyboard::Key::K, arcade::Input::AKEY_K},
			{sf::Keyboard::Key::L, arcade::Input::AKEY_L},
			{sf::Keyboard::Key::M, arcade::Input::AKEY_M},
			{sf::Keyboard::Key::N, arcade::Input::AKEY_N},
			{sf::Keyboard::Key::O, arcade::Input::AKEY_O},
			{sf::Keyboard::Key::P, arcade::Input::AKEY_P},
			{sf::Keyboard::Key::Q, arcade::Input::AKEY_Q},
			{sf::Keyboard::Key::R, arcade::Input::AKEY_R},
			{sf::Keyboard::Key::S, arcade::Input::AKEY_S},
			{sf::Keyboard::Key::T, arcade::Input::AKEY_T},
			{sf::Keyboard::Key::U, arcade::Input::AKEY_U},
			{sf::Keyboard::Key::V, arcade::Input::AKEY_V},
			{sf::Keyboard::Key::W, arcade::Input::AKEY_W},
			{sf::Keyboard::Key::X, arcade::Input::AKEY_X},
			{sf::Keyboard::Key::Y, arcade::Input::AKEY_Y},
			{sf::Keyboard::Key::Z, arcade::Input::AKEY_Z},
			{sf::Keyboard::Key::Num0, arcade::Input::AKEY_NUM0},
			{sf::Keyboard::Key::Num1, arcade::Input::AKEY_NUM1},
			{sf::Keyboard::Key::Num2, arcade::Input::AKEY_NUM2},
			{sf::Keyboard::Key::Num3, arcade::Input::AKEY_NUM3},
			{sf::Keyboard::Key::Num4, arcade::Input::AKEY_NUM4},
			{sf::Keyboard::Key::Num5, arcade::Input::AKEY_NUM5},
			{sf::Keyboard::Key::Num6, arcade::Input::AKEY_NUM6},
			{sf::Keyboard::Key::Num7, arcade::Input::AKEY_NUM7},
			{sf::Keyboard::Key::Num8, arcade::Input::AKEY_NUM8},
			{sf::Keyboard::Key::Num9, arcade::Input::AKEY_NUM9},
			{sf::Keyboard::Key::Escape, arcade::Input::AKEY_ESC},
			{sf::Keyboard::Key::LControl, arcade::Input::AKEY_LCTRL},
			{sf::Keyboard::Key::LShift, arcade::Input::AKEY_LSHIFT},
			{sf::Keyboard::Key::LAlt, arcade::Input::AKEY_LALT},
			{sf::Keyboard::Key::LSystem, arcade::Input::AKEY_LSYSTEM},
			{sf::Keyboard::Key::RControl, arcade::Input::AKEY_RCTRL},
			{sf::Keyboard::Key::RShift, arcade::Input::AKEY_RSHIFT},
			{sf::Keyboard::Key::RAlt, arcade::Input::AKEY_RALT},
			{sf::Keyboard::Key::RSystem, arcade::Input::AKEY_RSYSTEM},
			{sf::Keyboard::Key::Menu, arcade::Input::AKEY_MENU},
			{sf::Keyboard::Key::LBracket, arcade::Input::AKEY_LBRACKET},
			{sf::Keyboard::Key::RBracket, arcade::Input::AKEY_RBRACKET},
			{sf::Keyboard::Key::SemiColon, arcade::Input::AKEY_SEMICOLON},
			{sf::Keyboard::Key::Semicolon, arcade::Input::AKEY_SEMICOLON},
			{sf::Keyboard::Key::Comma, arcade::Input::AKEY_COMMA},
			{sf::Keyboard::Key::Period, arcade::Input::AKEY_DOT},
			{sf::Keyboard::Key::Quote, arcade::Input::AKEY_QUOTE},
			{sf::Keyboard::Key::Slash, arcade::Input::AKEY_SLASH},
			{sf::Keyboard::Key::BackSlash, arcade::Input::AKEY_BACKSLASH},
			{sf::Keyboard::Key::Backslash, arcade::Input::AKEY_BACKSLASH},
			{sf::Keyboard::Key::Tilde, arcade::Input::AKEY_TILDE},
			{sf::Keyboard::Key::Equal, arcade::Input::AKEY_EQUAL},
			{sf::Keyboard::Key::Hyphen, arcade::Input::AKEY_MINUS},
			{sf::Keyboard::Key::Enter, arcade::Input::AKEY_ENTER},
			{sf::Keyboard::Key::Return, arcade::Input::AKEY_ENTER},
			{sf::Keyboard::Key::Space, arcade::Input::AKEY_SPACE},
			{sf::Keyboard::Key::BackSpace, arcade::Input::AKEY_BACKSPACE},
			{sf::Keyboard::Key::Backspace, arcade::Input::AKEY_BACKSPACE},
			{sf::Keyboard::Key::Tab, arcade::Input::AKEY_TAB},
			{sf::Keyboard::Key::PageUp, arcade::Input::AKEY_PAGEUP},
			{sf::Keyboard::Key::PageDown, arcade::Input::AKEY_PAGEDOWN},
			{sf::Keyboard::Key::Home, arcade::Input::AKEY_START},
			{sf::Keyboard::Key::End, arcade::Input::AKEY_END},
			{sf::Keyboard::Key::Insert, arcade::Input::AKEY_INSERT},
			{sf::Keyboard::Key::Delete, arcade::Input::AKEY_DELETE},
			{sf::Keyboard::Key::Add, arcade::Input::AKEY_PLUS},
			{sf::Keyboard::Key::Subtract, arcade::Input::AKEY_MINUS},
			{sf::Keyboard::Key::Multiply, arcade::Input::AKEY_MULTIPLY},
			{sf::Keyboard::Key::Divide, arcade::Input::AKEY_DIVIDE},
			{sf::Keyboard::Key::Left, arcade::Input::AKEY_LEFT},
			{sf::Keyboard::Key::Right, arcade::Input::AKEY_RIGHT},
			{sf::Keyboard::Key::Up, arcade::Input::AKEY_UP},
			{sf::Keyboard::Key::Down, arcade::Input::AKEY_DOWN},
			{sf::Keyboard::Key::Numpad0, arcade::Input::AKEY_NUMPAD0},
			{sf::Keyboard::Key::Numpad1, arcade::Input::AKEY_NUMPAD1},
			{sf::Keyboard::Key::Numpad2, arcade::Input::AKEY_NUMPAD2},
			{sf::Keyboard::Key::Numpad3, arcade::Input::AKEY_NUMPAD3},
			{sf::Keyboard::Key::Numpad4, arcade::Input::AKEY_NUMPAD4},
			{sf::Keyboard::Key::Numpad5, arcade::Input::AKEY_NUMPAD5},
			{sf::Keyboard::Key::Numpad6, arcade::Input::AKEY_NUMPAD6},
			{sf::Keyboard::Key::Numpad7, arcade::Input::AKEY_NUMPAD7},
			{sf::Keyboard::Key::Numpad8, arcade::Input::AKEY_NUMPAD8},
			{sf::Keyboard::Key::Numpad9, arcade::Input::AKEY_NUMPAD9},
			{sf::Keyboard::Key::F1, arcade::Input::AKEY_F1},
			{sf::Keyboard::Key::F2, arcade::Input::AKEY_F2},
			{sf::Keyboard::Key::F3, arcade::Input::AKEY_F3},
			{sf::Keyboard::Key::F4, arcade::Input::AKEY_F4},
			{sf::Keyboard::Key::F5, arcade::Input::AKEY_F5},
			{sf::Keyboard::Key::F6, arcade::Input::AKEY_F6},
			{sf::Keyboard::Key::F7, arcade::Input::AKEY_F7},
			{sf::Keyboard::Key::F8, arcade::Input::AKEY_F8},
			{sf::Keyboard::Key::F9, arcade::Input::AKEY_F9},
			{sf::Keyboard::Key::F10, arcade::Input::AKEY_F10},
			{sf::Keyboard::Key::F11, arcade::Input::AKEY_F11},
			{sf::Keyboard::Key::F12, arcade::Input::AKEY_F12},
			{sf::Keyboard::Key::F13, arcade::Input::AKEY_F13},
			{sf::Keyboard::Key::F14, arcade::Input::AKEY_F14},
			{sf::Keyboard::Key::F15, arcade::Input::AKEY_F15},
			{sf::Keyboard::Key::Pause, arcade::Input::AKEY_NULL},
			{sf::Keyboard::Key::KeyCount, arcade::Input::AKEY_NULL},
			{sf::Keyboard::Key::Dash, arcade::Input::AKEY_NULL},
			{sf::Keyboard::Key::Unknown, arcade::Input::AKEY_NULL},
		});
		sf::Event event {};

		if (window_.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				return arcade::Input::AEVENT_STOP;
			} else if (event.type == sf::Event::EventType::KeyPressed) {
				return SFMLKeys[event.key.code];
			}
		}
		return Input::AKEY_NULL;
	}

	// FUNCTIONS
	void SFMLWindow::clear() noexcept
	{
		window_.clear(sf::Color::Black);
	}

	void SFMLWindow::refresh() noexcept
	{
		window_.display();
	}

	void SFMLWindow::draw(IImage &sprite) noexcept
	{
		auto &child = dynamic_cast<SFMLImage &>(sprite);

		window_.draw(child.sprite_);
	}

	void SFMLWindow::draw(IText &text) noexcept
	{
		auto &child = dynamic_cast<SFMLText &>(text);

		window_.draw(child.text_);
	}
} // namespace arcade
