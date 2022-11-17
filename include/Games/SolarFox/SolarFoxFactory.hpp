/*
** EPITECH PROJECT, 2022
** factory
** File description:
** factory
*/

#ifndef SOLARFOX_FACTORY_HPP
#define SOLARFOX_FACTORY_HPP

#include "IGameFactory.hpp"
#include "SolarFoxGame.hpp"

namespace arcade {
	class SolarFoxFactory : public IGameFactory {
	public:
		// CTOR / DTOR
		SolarFoxFactory() noexcept;
		SolarFoxFactory(SolarFoxFactory const &other) = delete;
		SolarFoxFactory(SolarFoxFactory &&other) = default;
		virtual ~SolarFoxFactory() noexcept = default;
		SolarFoxFactory &operator=(SolarFoxFactory const &other) = delete;
		SolarFoxFactory &operator=(SolarFoxFactory &&other) = default;

		// FUNCTIONS
		std::unique_ptr<AGame> createGame(Player &, IWindow &, IGraphicFactory &) const override;

	protected:
	private:
	};
} // namespace arcade

#endif /* !SOLARFOX_FACTORY_HPP */
