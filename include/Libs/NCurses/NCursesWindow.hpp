/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesWindow
*/

#ifndef NCURSESWINDOW_HPP_
#define NCURSESWINDOW_HPP_

#include "IGraphicFactory.hpp"

#include <memory>
#include <ncurses.h>
#include <string_view>

namespace arcade {
	class NCursesWindow : public IWindow {
	public:
		// CTOR / DTOR
		NCursesWindow() = delete;
		explicit NCursesWindow(__attribute__((unused)) std::string_view windowName);
		NCursesWindow(NCursesWindow const &other) = delete;
		NCursesWindow(NCursesWindow &&other) = delete;
		~NCursesWindow() noexcept final;
		NCursesWindow &operator=(NCursesWindow const &other) = delete;
		NCursesWindow &operator=(NCursesWindow &&other) = delete;

		// GETTERS
		FVector getSize() const noexcept override;
		Input getInput() noexcept override;

		// FUNCTIONS
		void clear() noexcept override;
		void refresh() noexcept override;
		void draw(IImage &) noexcept override;
		void draw(IText &) noexcept override;

	private:
		FVector winSize {};
	};
} // namespace arcade

#endif /* !NCURSESWINDOW_HPP_ */
