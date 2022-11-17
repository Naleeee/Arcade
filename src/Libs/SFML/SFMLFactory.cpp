/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** sfml
*/

#include "SFMLFactory.hpp"

namespace arcade {

	// FUNCTIONS
	std::unique_ptr<IWindow> SFMLFactory::createWindow(std::string_view windowName) const
	{
		std::unique_ptr<IWindow> window = std::make_unique<SFMLWindow>(windowName);
		return window;
	}

	std::unique_ptr<IImage> SFMLFactory::createImage(std::string_view filePath) const
	{
		std::unique_ptr<IImage> image = std::make_unique<SFMLImage>(filePath);
		return image;
	}

	std::unique_ptr<IText> SFMLFactory::createText(std::string_view filePath) const
	{
		std::unique_ptr<IText> text = std::make_unique<SFMLText>(filePath);
		return text;
	}

	std::unique_ptr<ISound> SFMLFactory::createSound(std::string_view filePath) const
	{
		std::unique_ptr<ISound> sound = std::make_unique<SFMLSound>(filePath);
		return sound;
	}

	// EXTERN
	extern "C" std::unique_ptr<IGraphicFactory> createGraphicFactory()
	{
		if (!getenv("DISPLAY")) {
			throw error::GraphicError("DISPLAY variable not in environment.");
		}
		return std::make_unique<SFMLFactory>();
	}
} // namespace arcade
