/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeError
*/

#include "ArcadeError.hpp"

#include <utility>

namespace error {
	ArcadeError::ArcadeError(std::string message)
		: message_(std::move(message))
	{
	}

	const char *ArcadeError::what() const noexcept
	{
		return message_.c_str();
	}
} // namespace error
