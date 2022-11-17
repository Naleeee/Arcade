/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesImage
*/

#ifndef NCURSESIMAGE_HPP_
#define NCURSESIMAGE_HPP_

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "NCursesWindow.hpp"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <ncurses.h>
#include <string_view>

namespace arcade {
	class NCursesImage : public IImage {
		friend class NCursesWindow;

	public:
		// CTOR / DTOR
		NCursesImage() = delete;
		explicit NCursesImage(std::string_view filepath);
		NCursesImage(NCursesImage const &other) = delete;
		NCursesImage(NCursesImage &&other) = delete;
		~NCursesImage() noexcept final = default;
		NCursesImage &operator=(NCursesImage const &other) = delete;
		NCursesImage &operator=(NCursesImage &&other) = delete;

		// GETTERS
		FVector getPosition() const noexcept override;
		FVector getSize() const noexcept override;
		float getScale() const noexcept override;
		float getRotation() const noexcept override;
		std::string_view getImage() const;

		// SETTERS
		void setPosition(FVector position) noexcept override;
		void setRotation(float rotation) noexcept override;
		void setTexture(std::string_view filepath) override;

		// FUNCTIONS
		void move(FVector vector) noexcept override;
		void scale(float scale) noexcept override;
		void rotate(__attribute__((unused)) float rotation) noexcept override;
		void fitSize(FVector size) noexcept override;

	private:
		int id_;
		Color color_ {};
		std::string image_;
		char texture_;
		FVector posyx_ {};
		FVector size_ {};
		float rotation_;
		float scale_;
	};
} // namespace arcade

#endif /* !NCURSESIMAGE_HPP_ */
