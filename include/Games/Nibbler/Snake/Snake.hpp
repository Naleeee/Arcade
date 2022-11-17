/*
** EPITECH PROJECT, 2022
** snake
** File description:
** snake
*/

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "SnakeMember.hpp"

#include <iostream>
#include <vector>

namespace arcade {
	class Snake {
	public:
		// CTOR / DTOR
		Snake() noexcept = delete;
		Snake(IWindow &, IGraphicFactory &);
		Snake(Snake const &other) = delete;
		Snake(Snake &&other) = default;
		virtual ~Snake() noexcept = default;
		Snake &operator=(Snake const &other) = delete;
		Snake &operator=(Snake &&other) = default;

		// GETTERS
		int getLength() const;
		std::vector<Member> const &getSnake() const;

		// FUNCTIONS
		void moveSnake(FVector);
		void addMember(IWindow &, IGraphicFactory &);

	private:
		bool alive_ = true;
		int length_ = 4;
		int pos_x {};
		int pos_y {};
		std::vector<Member> snake_;
	};
} // namespace arcade

#endif /* !SNAKE_HPP */
