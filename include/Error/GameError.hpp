/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** GameError
*/

#ifndef GAMEERROR_HPP_
#define GAMEERROR_HPP_

#include "ArcadeError.hpp"

namespace error {
	class GameError final : public ArcadeError {
	public:
		explicit GameError(std::string const &message);
		GameError(GameError const &other) = default;
		GameError(GameError &&other) noexcept = default;
		~GameError() noexcept = default;
		GameError &operator=(GameError const &other) noexcept = delete;
		GameError &operator=(GameError &&other) noexcept = delete;
	};
} // namespace error

#endif /* !GAMEERROR_HPP_ */
