/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLFactory
*/

#ifndef SDLFACTORY_HPP_
#define SDLFACTORY_HPP_

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SDLImage.hpp"
#include "SDLSound.hpp"
#include "SDLText.hpp"
#include "SDLWindow.hpp"

namespace arcade {
	class SDLFactory : public IGraphicFactory {
	public:
		SDLFactory() = default;
		SDLFactory(SDLFactory const &other) = delete;
		SDLFactory(SDLFactory &&other) = default;
		~SDLFactory() noexcept;
		SDLFactory &operator=(SDLFactory const &other) noexcept = delete;
		SDLFactory &operator=(SDLFactory &&other) noexcept = default;

		std::unique_ptr<IWindow> createWindow(std::string_view windowName) const final;
		std::unique_ptr<IImage> createImage(std::string_view filePath) const final;
		std::unique_ptr<IText> createText(std::string_view filePath) const final;
		std::unique_ptr<ISound> createSound(std::string_view filePath) const final;
	};
} // namespace arcade

#endif /* !SDLFACTORY_HPP_ */
