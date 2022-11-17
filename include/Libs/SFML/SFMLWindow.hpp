/*
** EPITECH PROJECT, 2022
** window
** File description:
** window
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "IGraphicFactory.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <unordered_map>

namespace arcade {

	class SFMLWindow : public IWindow {
	public:
		// CTOR / DTOR
		SFMLWindow() = delete;
		explicit SFMLWindow(std::string_view windowName);
		SFMLWindow(SFMLWindow const &other) = delete;
		SFMLWindow(SFMLWindow &&other) = delete;
		~SFMLWindow() noexcept final;
		SFMLWindow &operator=(SFMLWindow const &other) = delete;
		SFMLWindow &operator=(SFMLWindow &&other) = delete;

		// GETTERS
		FVector getSize() const noexcept override;
		Input getInput() noexcept override;

		// FUNCTIONS
		void clear() noexcept override;
		void refresh() noexcept override;
		void draw(IImage &) noexcept override;
		void draw(IText &) noexcept override;

	private:
		sf::RenderWindow window_;
	};
} // namespace arcade

#endif /* !WINDOW_HPP */
