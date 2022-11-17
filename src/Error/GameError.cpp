/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** GameError
*/

#include "GameError.hpp"

namespace error {
	GameError::GameError(const std::string &message)
		: ArcadeError(message)
	{
	}
} // namespace error
