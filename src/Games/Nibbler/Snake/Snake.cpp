/*
** EPITECH PROJECT, 2022
** snake
** File description:
** snake
*/

#include "Snake.hpp"

namespace arcade {
	// CTOR / DTOR
	Snake::Snake(IWindow &window, IGraphicFactory &graphicFactory)
	{
		length_ = 0;
		FVector position {window.getSize().x / 1920 * 960, window.getSize().y / 1010 * 510};

		snake_.emplace_back('H', position, window, graphicFactory);
		for (size_t i = 0; i < 3; i++) {
			length_++;
			position.x -= window.getSize().x / 1920 * 60;
			snake_.emplace_back('B', position, window, graphicFactory);
		}
	}

	// GETTERS
	int Snake::getLength() const
	{
		return length_;
	}

	std::vector<Member> const &Snake::getSnake() const
	{
		return snake_;
	}

	// FUNCTIONS
	void Snake::moveSnake(FVector position)
	{
		FVector save = snake_.front().getPosition();
		FVector temp {0, 0};
		snake_.front().setPosition(position);

		for (int i = 1; i < snake_.size() - 1; i++) {
			temp = snake_[i].getPosition();
			snake_[i].setPosition(save);
			save = temp;
		}
		snake_.back().setPosition(save);
	}

	void Snake::addMember(IWindow &window, IGraphicFactory &graphicFactory)
	{
		snake_.emplace_back('B', snake_.back().getPosition(), window, graphicFactory);
	}
} // namespace arcade
