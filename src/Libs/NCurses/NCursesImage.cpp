/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesImage
*/

#include "NCursesImage.hpp"

namespace arcade {
	//CONSTRUCTOR
	NCursesImage::NCursesImage(std::string_view filepath)
	{
		scale_ = 1;
		rotation_ = 0;
		size_.x = 1;
		size_.y = 1;
		posyx_.x = 0;
		posyx_.y = 0;
		int c = 0;

		if (filepath.length() == 0) {
			throw error::GraphicError("Division by zero");
		}
		for (size_t i = 0; i < filepath.length(); i++) {
			c += filepath.data()[i];
		}
		c /= filepath.length();
		id_ = c;
		srand(id_);
		color_.r = rand() % 255 + 1;
		srand(id_ + 1);
		color_.g = rand() % 255 + 1;
		srand(id_ + 2);
		color_.b = rand() % 255 + 1;
		texture_ = (char)c;
		image_.push_back(texture_);
	}

	//FUNCTIONS
	void NCursesImage::move(FVector vector) noexcept
	{
		posyx_.y += vector.y;
		posyx_.x += vector.x;
	}

	void NCursesImage::scale(float scale) noexcept
	{
		scale_ = scale_ * scale;
	}

	void NCursesImage::rotate(__attribute__((unused)) float rotation) noexcept
	{
		return;
	}

	//SETTERS
	void NCursesImage::setPosition(FVector position) noexcept
	{
		posyx_.y = position.y;
		posyx_.x = position.x;
	}

	void NCursesImage::fitSize(FVector size) noexcept
	{
		if (size.x < 0 && size.y < 0) {
			return;
		} else {
			image_.erase();
			if (size.x == -1) {
				size.x = size.y;
				size.x *= 2;
			} else if (size.y == -1) {
				size.y = size.x;
				size.y /= 2;
			}
			size_.x = size.x;
			size_.y = size.y;
			for (int i = 0; i < size_.x; i++) {
				image_.push_back(texture_);
			}
			scale_ = 1;
		}
	}

	void NCursesImage::setRotation(float rotation) noexcept
	{
		rotation_ = rotation;
	}

	void NCursesImage::setTexture(std::string_view filepath)
	{
		int c = 0;
		image_.erase();

		if (filepath.length() == 0) {
			throw error::GraphicError("Division by zero");
		}
		for (size_t i = 0; i < filepath.length(); i++) {
			c += filepath.data()[i];
		}
		c /= filepath.length();
		texture_ = (char)c;
		id_ = c;
		srand(id_);
		color_.r = rand() % 255 + 1;
		srand(id_ + 1);
		color_.g = rand() % 255 + 1;
		srand(id_ + 2);
		color_.b = rand() % 255 + 1;

		for (int x = 0; x < size_.x; x++) {
			image_.push_back(texture_);
		}
	}

	//GETTERS
	FVector NCursesImage::getPosition() const noexcept
	{
		return posyx_;
	}

	FVector NCursesImage::getSize() const noexcept
	{
		return size_;
	}

	float NCursesImage::getScale() const noexcept
	{
		return scale_;
	}

	float NCursesImage::getRotation() const noexcept
	{
		return rotation_;
	}

	std::string_view NCursesImage::getImage() const
	{
		return image_;
	}
} // namespace arcade