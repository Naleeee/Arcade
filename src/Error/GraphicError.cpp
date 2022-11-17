/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** GraphicError
*/

#include "GraphicError.hpp"

namespace error {
	GraphicError::GraphicError(const std::string &message)
		: ArcadeError(message)
	{
	}
} // namespace error
