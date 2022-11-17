/*
** EPITECH PROJECT, 2022
** AGame
** File description:
** AGame
*/

#include "IGameFactory.hpp"

namespace arcade {

	// CTOR / DTOR
	AGame::AGame(Player &player, IWindow &window, IGraphicFactory &graphicFactory)
		: player(player)
		, window(window)
		, graphicFactory(graphicFactory)
	{
	}

} // namespace arcade