/*
** EPITECH PROJECT, 2022
** ncurses
** File description:
** ncurses
*/

#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "IGraphicFactory.hpp"

#include <iostream>
#include <memory>
#include <ncurses.h>

namespace arcade {
	class NCursesFactory : public IGraphicFactory {
	public:
		// CTOR / DTOR
		NCursesFactory() = default;
		NCursesFactory(NCursesFactory const &other) = delete;
		NCursesFactory(NCursesFactory &&other) = default;
		~NCursesFactory() noexcept final = default;
		NCursesFactory &operator=(NCursesFactory const &other) = delete;
		NCursesFactory &operator=(NCursesFactory &&other) = default;

		std::unique_ptr<IWindow> createWindow(std::string_view) const override;
		std::unique_ptr<IImage> createImage(std::string_view filePath) const override;
		std::unique_ptr<IText> createText(std::string_view filePath) const override;
		std::unique_ptr<ISound> createSound(std::string_view filePath) const override;
	};
} // namespace arcade

#endif /* !NCURSES_HPP */
