/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesText
*/

#include "NCursesText.hpp"

namespace arcade {
	//CONSTRUCTOR & DESTRUCTOR
	NCursesText::NCursesText(std::string_view filepath)
	{
		static int id = 0;
		id = id + 1;
		id_ = id;
		scale_ = 1;
		rotation_ = 0;
		size_.x = 1;
		size_.y = 1;
		posyx_.x = 0;
		posyx_.y = 0;
		color_.r = 0;
		color_.g = 0;
		color_.b = 0;
		color_.a = 0;
		font_ = filepath;
	}

	//FUNCTIONS
	void NCursesText::move(FVector vector) noexcept
	{
		posyx_.y += vector.y;
		posyx_.x += vector.x;
	}

	void NCursesText::scale(float scale) noexcept
	{
		scale_ = scale_ * scale;
	}

	void NCursesText::rotate(float rotation) noexcept
	{
		rotation_ = rotation;
	}

	//SETTERS
	void NCursesText::setPosition(FVector position) noexcept
	{
		posyx_.y = position.y;
		posyx_.x = position.x;
	}

	void NCursesText::setRotation(float rotation) noexcept
	{
		rotation_ = rotation;
	}

	void NCursesText::setText(std::string text) noexcept
	{
		size_.x = text.length();
		text_ = text;
	}

	void NCursesText::setColor(const Color &color) noexcept
	{
		color_.r = color.r;
		color_.g = color.g;
		color_.b = color.b;
		color_.a = color.a;
	}

	//GETTERS
	FVector NCursesText::getPosition() const noexcept
	{
		return posyx_;
	}

	FVector NCursesText::getSize() const noexcept
	{
		return size_;
	}

	float NCursesText::getScale() const noexcept
	{
		return scale_;
	}

	float NCursesText::getRotation() const noexcept
	{
		return rotation_;
	}

	std::string NCursesText::getText() const noexcept
	{
		return std::string(text_);
	}

	Color NCursesText::getColor() const noexcept
	{
		return color_;
	}

	void NCursesText::fitSize(FVector size) noexcept
	{
		size_.y = 1;
		size_.x = text_.length();
	}
} // namespace arcade
