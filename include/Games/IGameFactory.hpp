/*
** EPITECH PROJECT, 2022
** game
** File description:
** interface
*/

#ifndef AGAME_HPP
#define AGAME_HPP

#include "IGraphicFactory.hpp"

#include <iostream>

namespace arcade {
	struct Player {
		std::string name;
		std::size_t score;
	};

	class AGame {
	public:
		// CTOR / DTOR
		AGame() = delete;
		AGame(Player &, IWindow &, IGraphicFactory &);
		AGame(AGame const &other) = delete;
		AGame(AGame &&other) = delete;
		virtual ~AGame() noexcept = default;
		AGame &operator=(AGame const &other) = delete;
		AGame &operator=(AGame &&other) = delete;

		// FUNCTIONS
		virtual bool handleInput(const Input &) noexcept = 0;
		virtual void refresh() noexcept = 0;

	protected:
		Player &player;
		IWindow &window;
		IGraphicFactory &graphicFactory;
	};

	class IGameFactory {
	public:
		// CTOR / DTOR
		IGameFactory() = default;
		IGameFactory(IGameFactory const &other) = delete;
		IGameFactory(IGameFactory &&other) = default;
		virtual ~IGameFactory() = default;
		IGameFactory &operator=(IGameFactory const &other) = delete;
		IGameFactory &operator=(IGameFactory &&other) = default;

		// FUNCTIONS
		virtual std::unique_ptr<AGame> createGame(Player &, IWindow &, IGraphicFactory &) const = 0;
	};

} // namespace arcade

#endif /* !AGAME_HPP */
