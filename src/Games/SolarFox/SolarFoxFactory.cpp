/*
** EPITECH PROJECT, 2022
** nfactory
** File description:
** factory
*/

#include "SolarFoxFactory.hpp"

namespace arcade {

	// CTOR / DTOR
	SolarFoxFactory::SolarFoxFactory() noexcept = default;

	// FUNCTIONS
	std::unique_ptr<AGame> SolarFoxFactory::createGame(Player &player, IWindow &window,
													   IGraphicFactory &FGraphic) const
	{
		std::unique_ptr<AGame> game = std::make_unique<SolarFoxGame>(player, window, FGraphic);
		return game;
	}

	extern "C" std::unique_ptr<IGameFactory> createGameFactory()
	{
		return std::make_unique<SolarFoxFactory>();
	}
} // namespace arcade