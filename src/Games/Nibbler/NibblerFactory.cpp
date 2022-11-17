/*
** EPITECH PROJECT, 2022
** nfactory
** File description:
** factory
*/

#include "NibblerFactory.hpp"

namespace arcade {

	// CTOR / DTOR
	NibblerFactory::NibblerFactory() noexcept = default;

	// FUNCTIONS
	std::unique_ptr<AGame> NibblerFactory::createGame(Player &player, IWindow &window,
													  IGraphicFactory &FGraphic) const
	{
		std::unique_ptr<AGame> game = std::make_unique<NibblerGame>(player, window, FGraphic);
		return game;
	}

	extern "C" std::unique_ptr<IGameFactory> createGameFactory()
	{
		return std::make_unique<NibblerFactory>();
	}
} // namespace arcade