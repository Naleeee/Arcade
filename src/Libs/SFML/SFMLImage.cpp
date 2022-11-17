/*
** EPITECH PROJECT, 2022
** image
** File description:
** image
*/

#include "SFMLImage.hpp"

namespace arcade {

	// CTOR / DTOR
	SFMLImage::SFMLImage(std::string_view filepath)
	{
		if (!texture_.loadFromFile(std::string {filepath}))
			throw error::GraphicError("Couldn't load image " + std::string {filepath});

		texture_.setSmooth(true);
		sprite_.setTexture(texture_, true);
	}

	// GETTERS
	FVector SFMLImage::getPosition() const noexcept
	{
		return FVector {sprite_.getPosition().x, sprite_.getPosition().y};
	}

	FVector SFMLImage::getSize() const noexcept
	{
		return FVector {sprite_.getGlobalBounds().width, sprite_.getGlobalBounds().height};
	}

	float SFMLImage::getScale() const noexcept
	{
		return scale_;
	}

	float SFMLImage::getRotation() const noexcept
	{
		return sprite_.getRotation();
	}

	// SETTERS
	void SFMLImage::setPosition(FVector position) noexcept
	{
		sprite_.setPosition(sf::Vector2f {position.x, position.y});
	}

	void SFMLImage::setRotation(float rotation) noexcept
	{
		sf::Rect pastRect = sprite_.getGlobalBounds();
		sf::Vector2f pastCenter = {pastRect.left + (pastRect.width / 2),
								   pastRect.top + (pastRect.height / 2)};

		sprite_.setRotation(rotation);
		sf::Rect newRect = sprite_.getGlobalBounds();
		sf::Vector2f newCenter = {newRect.left + (newRect.width / 2),
								  newRect.top + (newRect.height / 2)};

		sprite_.move(pastCenter - newCenter);
	}

	void SFMLImage::setTexture(std::string_view filepath)
	{
		sf::Texture new_texture;

		if (!new_texture.loadFromFile(std::string {filepath})) {
			throw error::GraphicError("Couldn't load new image " + std::string {filepath});
		}
		texture_ = new_texture;
		sprite_.setTexture(texture_, true);
	}

	// FUNCTIONS
	void SFMLImage::move(FVector vector) noexcept
	{
		sprite_.move(sf::Vector2f {vector.x, vector.y});
	}

	void SFMLImage::scale(float scale) noexcept
	{
		sprite_.scale(sf::Vector2f {scale, scale});
		scale_ *= scale;
	}

	void SFMLImage::rotate(float rotation) noexcept
	{
		sf::Rect pastRect = sprite_.getGlobalBounds();
		sf::Vector2f pastCenter = {pastRect.left + (pastRect.width / 2),
								   pastRect.top + (pastRect.height / 2)};

		sprite_.rotate(rotation);
		sf::Rect newRect = sprite_.getGlobalBounds();
		sf::Vector2f newCenter = {newRect.left + (newRect.width / 2),
								  newRect.top + (newRect.height / 2)};

		sprite_.move(pastCenter - newCenter);
	}

	void SFMLImage::fitSize(arcade::FVector size) noexcept
	{
		if (size.x == -1 and size.y == -1) {
			return;
		}
		float scale = 1;
		sf::FloatRect rect = sprite_.getGlobalBounds();

		if (size.x != -1 and (size.y == -1 or size.x / rect.width < size.y / rect.height)) {
			scale = size.x / rect.width;
		} else {
			scale = size.y / rect.height;
		}
		sprite_.scale({scale, scale});
		scale_ = 1;
	}
} // namespace arcade
