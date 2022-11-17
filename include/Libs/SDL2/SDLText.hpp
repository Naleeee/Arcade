/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLText
*/

#ifndef SDLTEXT_HPP_
#define SDLTEXT_HPP_

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SDLDeleters.hpp"

#include <SDL2/SDL_ttf.h>

#define DEFAULT_FONT_SIZE 40

namespace arcade {
	class SDLText : public IText {
		friend class SDLWindow;

	public:
		// CTOR / DTOR
		SDLText() = default;
		explicit SDLText(std::string_view filePath);
		SDLText(SDLText const &other) = delete;
		SDLText(SDLText &&other) = delete;
		~SDLText() noexcept = default;
		SDLText &operator=(SDLText const &other) = delete;
		SDLText &operator=(SDLText &&other) = delete;

		// GETTERS
		FVector getPosition() const noexcept final;
		float getScale() const noexcept final;
		FVector getSize() const noexcept final;
		float getRotation() const noexcept final;
		std::string getText() const noexcept final;
		Color getColor() const noexcept final;

		// SETTERS
		void setPosition(FVector position) noexcept final;
		void setRotation(float rotation) noexcept final;
		void setText(std::string text) noexcept final;
		void setColor(const Color &color) noexcept final;

		// FUNCTIONS
		void move(FVector vector) noexcept final;
		void scale(float scale) noexcept final;
		void rotate(float rotation) noexcept final;
		void fitSize(FVector size) noexcept final;

	private:
		SDLFontPtr font_;
		Color color_ {};
		std::string text_;
		SDLSurfacePtr surface_;
		SDLTexturePtr texture_;
		SDL_Rect rect_ {};
		FVector position_ {};
		float scale_;
		float rotation_;
	};
} // namespace arcade

#endif /* !SDLTEXT_HPP_ */
