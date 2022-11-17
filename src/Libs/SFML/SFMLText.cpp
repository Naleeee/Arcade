/*
** EPITECH PROJECT, 2022
** text
** File description:
** text
*/

#include "SFMLText.hpp"

namespace arcade {

	// CTOR / DTOR
	SFMLText::SFMLText(std::string_view filepath)
	{
		if (!font_.loadFromFile(std::string {filepath}))
			throw error::GraphicError("Couldn't load text: " + std::string {filepath});
		text_.setFont(font_);
		text_.setCharacterSize(40);
	}

	// GETTERS
	FVector SFMLText::getPosition() const noexcept
	{
		return FVector {text_.getPosition().x, text_.getPosition().y};
	}

	FVector SFMLText::getSize() const noexcept
	{
		auto rect = text_.getGlobalBounds();

		return {rect.width, rect.height};
	}

	float SFMLText::getScale() const noexcept
	{
		return scale_;
	}

	float SFMLText::getRotation() const noexcept
	{
		return text_.getRotation();
	}

	std::string SFMLText::getText() const noexcept
	{
		return std::string {text_.getString().toAnsiString()};
	}

	Color SFMLText::getColor() const noexcept
	{
		sf::Color oldColor;

		oldColor = text_.getFillColor();
		return Color {oldColor.r, oldColor.g, oldColor.b, oldColor.a};
	}

	// SETTERS
	void SFMLText::setPosition(FVector position) noexcept
	{
		text_.setPosition(sf::Vector2f {position.x, position.y});
	}

	void SFMLText::setRotation(float rotation) noexcept
	{
		sf::Rect pastRect = text_.getGlobalBounds();
		sf::Vector2f pastCenter = {pastRect.left + (pastRect.width / 2),
								   pastRect.top + (pastRect.height / 2)};

		text_.setRotation(rotation);
		sf::Rect newRect = text_.getGlobalBounds();
		sf::Vector2f newCenter = {newRect.left + (newRect.width / 2),
								  newRect.top + (newRect.height / 2)};

		text_.move(pastCenter - newCenter);
	}

	void SFMLText::setText(std::string text) noexcept
	{
		text_.setString(text);
	}

	void SFMLText::setColor(const Color &color) noexcept
	{
		text_.setFillColor(sf::Color {sf::Uint8 {color.r}, sf::Uint8 {color.g}, sf::Uint8 {color.b},
									  sf::Uint8 {color.a}});
	}

	// FUNCTIONS
	void SFMLText::move(FVector vector) noexcept
	{
		text_.move(sf::Vector2f {vector.x, vector.y});
	}

	void SFMLText::scale(float scale) noexcept
	{
		text_.scale(sf::Vector2f {scale, scale});
		scale_ *= scale;
	}

	void SFMLText::rotate(float rotation) noexcept
	{
		sf::Rect pastRect = text_.getGlobalBounds();
		sf::Vector2f pastCenter = {pastRect.left + (pastRect.width / 2),
								   pastRect.top + (pastRect.height / 2)};

		text_.rotate(rotation);
		sf::Rect newRect = text_.getGlobalBounds();
		sf::Vector2f newCenter = {newRect.left + (newRect.width / 2),
								  newRect.top + (newRect.height / 2)};

		text_.move(pastCenter - newCenter);
	}

	void SFMLText::fitSize(arcade::FVector size) noexcept
	{
		if (size.x == -1 and size.y == -1) {
			return;
		}
		float scale = 1;
		sf::FloatRect rect = text_.getGlobalBounds();

		if (size.x != -1 and (size.y == -1 or size.x / rect.width < size.y / rect.height)) {
			scale = size.x / rect.width;
		} else {
			scale = size.y / rect.height;
		}

		text_.scale({scale, scale});
		scale_ = 1;
	}
} // namespace arcade
