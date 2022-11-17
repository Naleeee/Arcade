/*
** EPITECH PROJECT, 2022
** Image
** File description:
** Image
*/

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SFMLWindow.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <string_view>

namespace arcade {

	class SFMLImage : public IImage {
		friend class SFMLWindow;

	public:
		// CTOR / DTOR
		SFMLImage() = delete;
		explicit SFMLImage(std::string_view filePath);
		SFMLImage(SFMLImage const &other) = delete;
		SFMLImage(SFMLImage &&other) = delete;
		~SFMLImage() noexcept final = default;
		SFMLImage &operator=(SFMLImage const &other) = delete;
		SFMLImage &operator=(SFMLImage &&other) = delete;

		// GETTERS
		FVector getPosition() const noexcept override;
		FVector getSize() const noexcept override;
		float getScale() const noexcept override;
		float getRotation() const noexcept override;

		// SETTERS
		void setPosition(FVector position) noexcept override;
		void setRotation(float rotation) noexcept override;
		void setTexture(std::string_view filePath) override;

		// FUNCTIONS
		void move(FVector vector) noexcept override;
		void scale(float scale) noexcept override;
		void rotate(float rotation) noexcept override;
		void fitSize(FVector) noexcept override;

	private:
		sf::Texture texture_;
		sf::Sprite sprite_;
		float scale_ {};
	};
} // namespace arcade

#endif /* !IMAGE_HPP */
