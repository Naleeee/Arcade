/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesText
*/

#ifndef NCURSESTEXT_HPP_
#define NCURSESTEXT_HPP_

#include "IGraphicFactory.hpp"

#include <iostream>
#include <memory>
#include <ncurses.h>
#include <string_view>

namespace arcade {
	class NCursesText : public IText {
		friend class NCursesWindow;

	public:
		// CTOR / DTOR
		NCursesText() = delete;
		explicit NCursesText(std::string_view filePath);
		NCursesText(NCursesText const &other) = delete;
		NCursesText(NCursesText &&other) = delete;
		~NCursesText() noexcept final = default;
		NCursesText &operator=(NCursesText const &other) = delete;
		NCursesText &operator=(NCursesText &&other) = delete;

		// GETTERS
		FVector getPosition() const noexcept override;
		FVector getSize() const noexcept override;
		float getScale() const noexcept override;
		float getRotation() const noexcept override;
		std::string getText() const noexcept override;
		Color getColor() const noexcept override;

		// SETTERS
		void setPosition(FVector position) noexcept override;
		void setRotation(float rotation) noexcept override;
		void setText(std::string text) noexcept override;
		void setColor(const Color &color) noexcept override;

		// FUNCTIONS
		void move(FVector vector) noexcept override;
		void scale(float scale) noexcept override;
		void rotate(float rotation) noexcept override;
		void fitSize(FVector size) noexcept override;

	private:
		int id_;
		std::string text_;
		std::string font_;
		Color color_ {};
		FVector posyx_ {};
		FVector size_ {};
		float rotation_;
		float scale_;
	};
} // namespace arcade

#endif /* !NCURSESTEXT_HPP_ */
