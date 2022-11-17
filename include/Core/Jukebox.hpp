/*
** EPITECH PROJECT, 2022
** jukebox
** File description:
** jukebox
*/

#ifndef JUKEBOX_HPP
#define JUKEBOX_HPP

#include "IGraphicFactory.hpp"

#include <dirent.h>
#include <iostream>
#include <vector>

namespace arcade {
	class Jukebox {
	public:
		// CTOR / DTOR
		Jukebox() = default;
		Jukebox(IWindow &, IGraphicFactory &);
		Jukebox(Jukebox const &other) = delete;
		Jukebox(Jukebox &&other) = default;
		virtual ~Jukebox() noexcept = default;
		Jukebox &operator=(Jukebox const &other) = delete;
		Jukebox &operator=(Jukebox &&other) = default;

		// GETTERS
		void getAllMusicsFromPath(const char *path, IGraphicFactory &FGraphic, IWindow &window);
		std::string getTagMusic() const;

		// FUNCTIONS
		int handleInput(const Input &, IGraphicFactory &);
		void display(IWindow &);

	private:
		std::unique_ptr<IImage> background_ = nullptr;
		std::unique_ptr<ISound> music_ = nullptr;

		int nbMusics_ = 0;
		int idMusic_ = 0;
		std::vector<std::unique_ptr<IText>> Musics_;
		std::vector<std::string> tagMusics_;
	};
} // namespace arcade

#endif /* !JUKEBOX_HPP */
