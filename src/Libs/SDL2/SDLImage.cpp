/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLImage
*/

#include "SDLImage.hpp"

namespace arcade {
	SDLImage::SDLImage(std::string_view filePath)
	{
		surface_.reset(IMG_Load(filePath.data()));
		if (surface_ == nullptr)
			throw error::GraphicError(IMG_GetError());
		texture_ = nullptr;
		position_ = {0, 0};
		rect_ = {static_cast<int>(position_.x), static_cast<int>(position_.y), surface_->w,
				 surface_->h};
		scale_ = 1;
		rotation_ = 0;
	}

	FVector SDLImage::getSize() const noexcept
	{
		return {static_cast<float>(rect_.w), static_cast<float>(rect_.h)};
	}

	FVector SDLImage::getPosition() const noexcept
	{
		return position_;
	}

	float SDLImage::getScale() const noexcept
	{
		return scale_;
	}

	float SDLImage::getRotation() const noexcept
	{
		return rotation_;
	}

	void SDLImage::setPosition(FVector position) noexcept
	{
		rect_.x = position.x;
		rect_.y = position.y;
		position_ = position;
	}

	void SDLImage::setRotation(float rotation) noexcept
	{
		rotation_ = rotation;
		while (rotation_ > 360)
			rotation_ -= 360;
		while (rotation_ < -360)
			rotation_ += 360;
	}

	void SDLImage::setTexture(std::string_view filePath)
	{
		surface_.reset(IMG_Load(filePath.data()));
		if (surface_ == nullptr)
			throw error::GraphicError(IMG_GetError());
		rect_.w = surface_->w;
		rect_.h = surface_->h;
	}

	void SDLImage::move(FVector vector) noexcept
	{
		rect_.x += vector.x;
		rect_.y += vector.y;
		position_ = vector;
	}

	void SDLImage::scale(float scale) noexcept
	{
		rect_.w *= scale;
		rect_.h *= scale;
		scale_ *= scale;
	}

	void SDLImage::rotate(float rotation) noexcept
	{
		rotation_ += rotation;
		while (rotation_ > 360)
			rotation_ -= 360;
		while (rotation_ < -360)
			rotation_ += 360;
	}

	void SDLImage::fitSize(FVector size) noexcept
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
