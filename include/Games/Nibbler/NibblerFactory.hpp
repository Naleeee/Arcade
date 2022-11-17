/*
** EPITECH PROJECT, 2022
** factory
** File description:
** factory
*/

#ifndef NIBBLER_FACTORY_HPP
#define NIBBLER_FACTORY_HPP

#include "IGameFactory.hpp"
#include "NibblerGame.hpp"

namespace arcade {
	class NibblerFactory : public IGameFactory {
	public:
		// CTOR / DTOR
		NibblerFactory() noexcept;
		NibblerFactory(NibblerFactory const &other) = delete;
		NibblerFactory(NibblerFactory &&other) = default;
		virtual ~NibblerFactory() noexcept = default;
		NibblerFactory &operator=(NibblerFactory const &other) = delete;
		NibblerFactory &operator=(NibblerFactory &&other) = default;

		// FUNCTIONS
		std::unique_ptr<AGame> createGame(Player &, IWindow &, IGraphicFactory &) const override;

	protected:
	private:
	};
} // namespace arcade

#endif /* !NIBBLER_FACTORY_HPP */
