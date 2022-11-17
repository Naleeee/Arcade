/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** sfml
*/

#ifndef SFML_HPP
#define SFML_HPP

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SFMLImage.hpp"
#include "SFMLSound.hpp"
#include "SFMLText.hpp"
#include "SFMLWindow.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <string_view>

namespace arcade {
	class SFMLFactory : public IGraphicFactory {
	public:
		// CTOR / DTOR
		SFMLFactory() = default;
		SFMLFactory(SFMLFactory const &other) = delete;
		SFMLFactory(SFMLFactory &&other) = default;
		~SFMLFactory() noexcept final = default;
		SFMLFactory &operator=(SFMLFactory const &other) = delete;
		SFMLFactory &operator=(SFMLFactory &&other) = default;

		// FUNCTIONS
		std::unique_ptr<IWindow> createWindow(std::string_view) const override;
		std::unique_ptr<IImage> createImage(std::string_view filePath) const override;
		std::unique_ptr<IText> createText(std::string_view filePath) const override;
		std::unique_ptr<ISound> createSound(std::string_view filePath) const override;

	private:
	};
} // namespace arcade

#endif /* !SFML_HPP */
