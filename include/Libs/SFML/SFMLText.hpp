/*
** EPITECH PROJECT, 2022
** text
** File description:
** text
*/

#ifndef TEXT_HPP
#define TEXT_HPP

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <string_view>

namespace arcade {
	class SFMLText : public IText {
		friend class SFMLWindow;

	public:
		// CTOR / DTOR
		SFMLText() = delete;
		explicit SFMLText(std::string_view filePath);
		SFMLText(SFMLText const &other) = delete;
		SFMLText(SFMLText &&other) = delete;
		~SFMLText() noexcept final = default;
		SFMLText &operator=(SFMLText const &other) = delete;
		SFMLText &operator=(SFMLText &&other) = delete;

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
		void fitSize(FVector) noexcept override;

	private:
		sf::Font font_;
		sf::Text text_;
		float scale_ {};
	};
} // namespace arcade
#endif /* !TEXT_HPP */
