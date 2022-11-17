/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** GraphicError
*/

#ifndef GRAPHICERROR_HPP_
#define GRAPHICERROR_HPP_

#include "ArcadeError.hpp"

namespace error {
	class GraphicError final : public ArcadeError {
	public:
		explicit GraphicError(std::string const &message);
		GraphicError(GraphicError const &other) = default;
		GraphicError(GraphicError &&other) noexcept = default;
		~GraphicError() noexcept = default;
		GraphicError &operator=(GraphicError const &other) noexcept = delete;
		GraphicError &operator=(GraphicError &&other) noexcept = delete;
	};
} // namespace error

#endif /* !GRAPHICERROR_HPP_ */
