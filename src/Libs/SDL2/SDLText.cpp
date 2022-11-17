/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLText
*/

#include "SDLText.hpp"

#include <iostream>

namespace arcade {
	SDLText::SDLText(std::string_view filePath)
	{
		font_.reset(TTF_OpenFont(filePath.data(), DEFAULT_FONT_SIZE));
		if (font_ == nullptr)
			throw error::GraphicError(TTF_GetError());
		color_ = {0, 0, 0, 255};
		text_ = "";
		surface_ = nullptr;
		texture_ = nullptr;
		rect_ = {0, 0, 0, 0};
		position_ = {0, 0};
		scale_ = 1;
		rotation_ = 0;
	}

	FVector SDLText::getPosition() const noexcept
	{
		return position_;
	}

	float SDLText::getScale() const noexcept
	{
		return scale_;
	}

	FVector SDLText::getSize() const noexcept
	{
		return {static_cast<float>(rect_.w), static_cast<float>(rect_.h)};
	}

	float SDLText::getRotation() const noexcept
	{
		return rotation_;
	}

	std::string SDLText::getText() const noexcept
	{
		return text_;
	}

	Color SDLText::getColor() const noexcept
	{
		return color_;
	}

	void SDLText::setPosition(FVector position) noexcept
	{
		rect_.x = position.x;
		rect_.y = position.y;
		position_ = position;
	}

	void SDLText::setRotation(float rotation) noexcept
	{
		rotation_ = rotation;
		while (rotation_ > 360)
			rotation_ -= 360;
		while (rotation_ < -360)
			rotation_ += 360;
	}

	void SDLText::setText(std::string text) noexcept
	{
		if (text.length() == 0) {
			surface_ = nullptr;
			return;
		}
		surface_.reset(TTF_RenderText_Solid(font_.get(), text.data(),
											{color_.r, color_.g, color_.b, color_.a}));
		if (surface_ == nullptr)
			return;
		rect_.w = surface_->w;
		rect_.h = surface_->h;
		text_ = text;
	}

	void SDLText::setColor(const Color &color) noexcept
	{
		color_ = color;
		surface_.reset(TTF_RenderText_Solid(font_.get(), text_.data(),
											{color_.r, color_.g, color_.b, color_.a}));
		if (surface_ == nullptr)
			return;
	}

	void SDLText::move(FVector vector) noexcept
	{
		rect_.x += vector.x;
		rect_.y += vector.y;
		position_ = vector;
	}

	void SDLText::scale(float scale) noexcept
	{
		rect_.w *= scale;
		rect_.h *= scale;
		scale_ = scale;
	}

	void SDLText::rotate(float rotation) noexcept
	{
		rotation_ += rotation;
		while (rotation_ > 360)
			rotation_ -= 360;
		while (rotation_ < -360)
			rotation_ += 360;
	}

	void SDLText::fitSize(FVector size) noexcept
	{
		if (size.x == -1 && size.y == -1) {
			return;
		}

		if (size.x != -1 && (size.y == -1 or size.x / rect_.w < size.y / rect_.h)) {
			this->scale(size.x / rect_.w);
		} else {
			this->scale(size.y / rect_.h);
		}
	}
} // namespace arcade
