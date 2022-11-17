/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace error {
	class ArcadeError : public std::exception {
	public:
		explicit ArcadeError(std::string message);
		ArcadeError(ArcadeError const &other) = default;
		ArcadeError(ArcadeError &&other) noexcept = default;
		~ArcadeError() noexcept = default;
		ArcadeError &operator=(ArcadeError &&other) noexcept = delete;
		const char *what() const noexcept;

	protected:
		std::string message_;
	};
} // namespace error

#endif /* !ERROR_HPP_ */
