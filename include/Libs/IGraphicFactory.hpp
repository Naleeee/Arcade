/*
** EPITECH PROJECT, 2022
** IWindow
** File description:
** GraphicFactory
*/

#ifndef IGRAPHICFACTORY_HPP
#define IGRAPHICFACTORY_HPP

#include "Input.hpp"

#include <memory>
#include <string_view>

namespace arcade {
	struct FVector {
		float x;
		float y;
	};

	struct Color {
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};

	class IImage {
	public:
		// CTOR / DTOR
		IImage() = default;
		IImage(IImage const &other) = delete;
		IImage(IImage &&other) = delete;
		virtual ~IImage() = default;
		IImage &operator=(IImage const &other) = delete;
		IImage &operator=(IImage &&other) = delete;

		// GETTERS
		virtual FVector getPosition() const noexcept = 0;
		virtual FVector getSize() const noexcept = 0;
		virtual float getScale() const noexcept = 0;
		virtual float getRotation() const noexcept = 0;

		// SETTERS
		virtual void setPosition(FVector position) noexcept = 0;
		virtual void setRotation(float rotation) noexcept = 0;
		virtual void setTexture(std::string_view filePath) = 0;

		// FUNCTIONS
		virtual void move(FVector vector) noexcept = 0;
		virtual void scale(float scale) noexcept = 0;
		virtual void rotate(float rotation) noexcept = 0;
		virtual void fitSize(FVector size) noexcept = 0;
	};

	class IText {
	public:
		// CTOR / DTOR
		IText() = default;
		IText(IText const &other) = delete;
		IText(IText &&other) = delete;
		virtual ~IText() = default;
		IText &operator=(IText const &other) = delete;
		IText &operator=(IText &&other) = delete;

		// GETTERS
		virtual FVector getPosition() const noexcept = 0;
		virtual float getScale() const noexcept = 0;
		virtual FVector getSize() const noexcept = 0;
		virtual float getRotation() const noexcept = 0;
		virtual std::string getText() const noexcept = 0;
		virtual Color getColor() const noexcept = 0;

		// SETTERS
		virtual void setPosition(FVector position) noexcept = 0;
		virtual void setRotation(float rotation) noexcept = 0;
		virtual void setText(std::string text) noexcept = 0;
		virtual void setColor(const Color &color) noexcept = 0;

		// FUNCTIONS
		virtual void move(FVector vector) noexcept = 0;
		virtual void scale(float scale) noexcept = 0;
		virtual void rotate(float rotation) noexcept = 0;
		virtual void fitSize(FVector size) noexcept = 0;
	};

	class ISound {
	public:
		// CTOR / DTOR
		ISound() = default;
		ISound(ISound const &other) = delete;
		ISound(ISound &&other) = delete;
		virtual ~ISound() = default;
		ISound &operator=(ISound const &other) = delete;
		ISound &operator=(ISound &&other) = delete;

		// GETTERS
		virtual float getVolume() const noexcept = 0;

		// SETTERS
		virtual void setVolume(float volume) noexcept = 0;
		virtual void setLoop(bool looping) noexcept = 0;

		// FUNCTIONS
		virtual void play() noexcept = 0;
		virtual void pause() noexcept = 0;
		virtual void stop() noexcept = 0;
	};

	class IWindow {
	public:
		// CTOR / DTOR
		IWindow() = default;
		IWindow(IWindow const &other) = delete;
		IWindow(IWindow &&other) = delete;
		virtual ~IWindow() = default;
		IWindow &operator=(IWindow const &other) = delete;
		IWindow &operator=(IWindow &&other) = delete;

		// GETTERS
		virtual FVector getSize() const noexcept = 0;
		virtual Input getInput() noexcept = 0;

		// FUNCTIONS
		virtual void clear() noexcept = 0;
		virtual void refresh() noexcept = 0;
		virtual void draw(IImage &) noexcept = 0;
		virtual void draw(IText &) noexcept = 0;
	};

	class IGraphicFactory {
	public:
		// CTOR / DTOR
		IGraphicFactory() = default;
		IGraphicFactory(IGraphicFactory const &other) = delete;
		IGraphicFactory(IGraphicFactory &&other) = default;
		virtual ~IGraphicFactory() = default;
		IGraphicFactory &operator=(IGraphicFactory const &other) = delete;
		IGraphicFactory &operator=(IGraphicFactory &&other) = default;

		// FUNCTIONS
		virtual std::unique_ptr<IWindow> createWindow(std::string_view) const = 0;
		virtual std::unique_ptr<IImage> createImage(std::string_view filePath) const = 0;
		virtual std::unique_ptr<IText> createText(std::string_view filePath) const = 0;
		virtual std::unique_ptr<ISound> createSound(std::string_view filePath) const = 0;
	};
} // namespace arcade

#endif /* !IGRAPHICFACTORY_HPP */
