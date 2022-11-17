/*
** EPITECH PROJECT, 2022
** ncurses
** File description:
** ncurses
*/

#include "NCursesFactory.hpp"

#include "NCursesImage.hpp"
#include "NCursesSound.hpp"
#include "NCursesText.hpp"
#include "NCursesWindow.hpp"

namespace arcade {
	std::unique_ptr<IWindow> NCursesFactory::createWindow(std::string_view windowName) const
	{
		std::unique_ptr<IWindow> window = std::make_unique<NCursesWindow>(windowName);
		return window;
	}

	std::unique_ptr<IImage> NCursesFactory::createImage(std::string_view filePath) const
	{
		std::unique_ptr<IImage> image = std::make_unique<NCursesImage>(filePath);
		return image;
	}

	std::unique_ptr<IText> NCursesFactory::createText(std::string_view filePath) const
	{
		std::unique_ptr<IText> text = std::make_unique<NCursesText>(filePath);
		return text;
	}

	std::unique_ptr<ISound> NCursesFactory::createSound(std::string_view filePath) const
	{
		std::unique_ptr<ISound> sound = std::make_unique<NCursesSound>(filePath);
		return sound;
	}

	extern "C" std::unique_ptr<IGraphicFactory> createGraphicFactory()
	{
		return std::make_unique<NCursesFactory>();
	}
} // namespace arcade
