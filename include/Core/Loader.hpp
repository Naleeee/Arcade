/*
** EPITECH PROJECT, 2022
** loader
** File description:
** loader
*/

#ifndef LOADER_HPP
#define LOADER_HPP

#include "ArcadeError.hpp"
#include "IGameFactory.hpp"
#include "IGraphicFactory.hpp"

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <string>

namespace arcade {
	using graphic_setup = std::unique_ptr<IGraphicFactory>();
	using game_setup = std::unique_ptr<IGameFactory>();

	class GraphicLoader {
		enum class Library { NCURSES = 0, SFML = 1, SDL2 = 2 };

	public:
		// CTOR / DTOR
		GraphicLoader() = default;
		GraphicLoader(const char *);
		GraphicLoader(GraphicLoader const &other) = delete;
		GraphicLoader(GraphicLoader &&other) = delete;
		~GraphicLoader() noexcept;
		GraphicLoader &operator=(GraphicLoader const &other) = delete;
		GraphicLoader &operator=(GraphicLoader &&other) = delete;

		// FUNCTIONS
		std::unique_ptr<IGraphicFactory> loadLibrary();

	private:
		void *handler_;
	};

	class GameLoader {
		enum class Library { NCURSES = 0, SFML = 1, SDL2 = 2 };

	public:
		// CTOR / DTOR
		GameLoader() = default;
		GameLoader(GameLoader const &other) = delete;
		GameLoader(GameLoader &&other) = delete;
		~GameLoader() noexcept;
		GameLoader &operator=(GameLoader const &other) = delete;
		GameLoader &operator=(GameLoader &&other) = delete;

		// FUNCTIONS
		void openLibrary(std::string);
		std::unique_ptr<IGameFactory> loadLibrary();
		std::unique_ptr<IGameFactory> switchLibrary(const char *);

	private:
		void *handler_ = nullptr;
	};
} // namespace arcade

#endif /* !LOADER_HPP */
