/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLImage
*/

#ifndef SDLIMAGE_HPP_
#define SDLIMAGE_HPP_

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SDLDeleters.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

namespace arcade {
	class SDLImage : public IImage {
		friend class SDLWindow;

	public:
		// CTOR / DTOR
		SDLImage() = default;
		explicit SDLImage(std::string_view filePath);
		SDLImage(SDLImage const &other) = delete;
		SDLImage(SDLImage &&other) = delete;
		~SDLImage() noexcept = default;
		SDLImage &operator=(SDLImage const &other) = delete;
		SDLImage &operator=(SDLImage &&other) = delete;

		// GETTERS
		FVector getSize() const noexcept final;
		FVector getPosition() const noexcept final;
		float getScale() const noexcept final;
		float getRotation() const noexcept final;

		// SETTERS
		void setPosition(FVector position) noexcept final;
		void setRotation(float rotation) noexcept final;
		void setTexture(std::string_view filePath) final;

		// FUNCTIONS
		void move(FVector vector) noexcept final;
		void scale(float scale) noexcept final;
		void rotate(float rotation) noexcept final;
		void fitSize(FVector size) noexcept final;

	private:
		SDLSurfacePtr surface_;
		SDLTexturePtr texture_;
		FVector position_ {};
		SDL_Rect rect_ {};
		float scale_;
		float rotation_;
	};
} // namespace arcade

#endif /* !SDLIMAGE_HPP_ */
