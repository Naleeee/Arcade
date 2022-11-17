/*
** EPITECH PROJECT, 2022
** loader
** File description:
** loader
*/

#include "Loader.hpp"

namespace arcade {
	// GRAPHIC

	// CTOR / DTOR
	GraphicLoader::GraphicLoader(const char *path)
	{
		std::string str(path);

		handler_ = dlopen(path, RTLD_LAZY);
		if (!handler_) {
			throw error::ArcadeError(dlerror());
		}
	}

	GraphicLoader::~GraphicLoader() noexcept
	{
		dlclose(handler_);
	}

	// FUNCTIONS
	std::unique_ptr<IGraphicFactory> GraphicLoader::loadLibrary()
	{
		auto *load =
			// NOLINTNEXTLINE
			reinterpret_cast<graphic_setup *>(dlsym(handler_, "createGraphicFactory"));

		if (!load) {
			throw error::ArcadeError("Couldn't load symbol: \"" + std::string(dlerror()) + "\"");
		}
		return load();
	}

	// GAME

	// CTOR / DTOR
	GameLoader::~GameLoader() noexcept
	{
		if (handler_ != nullptr) {
			dlclose(handler_);
		}
	}

	// FUNCTIONS
	void GameLoader::openLibrary(std::string path)
	{
		std::string str(path);

		handler_ = dlopen(path.data(), RTLD_LAZY);
		if (!handler_) {
			throw error::ArcadeError("Cannot load library: " + path + ": " + dlerror());
		}
	}

	std::unique_ptr<IGameFactory> GameLoader::loadLibrary()
	{
		// NOLINTNEXTLINE
		game_setup *load = reinterpret_cast<game_setup *>(dlsym(handler_, "createGameFactory"));

		if (!load) {
			throw error::ArcadeError("Cannot load symbol 'createGameFactory' ");
		}
		return load();
	}

	std::unique_ptr<IGameFactory> GameLoader::switchLibrary(const char *path)
	{
		void *new_handler = dlopen(path, RTLD_LAZY);

		if (!new_handler) {
			throw error::ArcadeError("Cannot load library: " + std::string(path) + ": " +
									 dlerror());
		}
		if (dlclose(handler_) != 0) {
			throw error::ArcadeError(dlerror());
		}
		return loadLibrary();
	}
} // namespace arcade
