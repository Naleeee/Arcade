/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#include "Bomb.hpp"

namespace arcade {

	// CTOR / DTOR

	// GETTERS
	FVector Bomb::getEndPosition() const
	{
		return endPosition_;
	}

	IImage &Bomb::getTexture() const
	{
		return *texture_;
	}

	bool Bomb::getShoot() const
	{
		return shoot_;
	}

	// SETTERS
	void Bomb::setEndPosition(FVector position)
	{
		endPosition_.x = position.x;
		endPosition_.y = position.y;
	}

	void Bomb::setShoot(bool shoot)
	{
		shoot_ = shoot;
	}

	// FUNCTIONS
	void Bomb::shootFromHere(char direction, FVector position, IWindow &window,
							 IGraphicFactory &graphicFactory)
	{
		shoot_ = true;
		direction_ = direction;
		endPosition_ = position;

		texture_ = graphicFactory.createImage("assets/SolarFox/Enemy.png");
		switch (direction) {
			case 'T':
				endPosition_.y -= window.getSize().y / 1010 * 660;
				break;
			case 'B':
				endPosition_.y += window.getSize().y / 1010 * 660;
				break;
			case 'R':
				endPosition_.x += window.getSize().x / 1920 * 1140;
				break;
			case 'L':
				endPosition_.x -= window.getSize().x / 1920 * 1140;
				break;
		}
		setEndPosition(endPosition_);
		texture_->setPosition(position);
		texture_->fitSize(FVector {window.getSize().x / 1920 * 60, window.getSize().y / 1010 * 60});
	}

	void Bomb::moveBomb()
	{
		FVector newPos = texture_->getPosition();
		switch (direction_) {
			case 'T':
				newPos.y -= 1;
				break;
			case 'B':
				newPos.y += 1;
				break;
			case 'R':
				newPos.x += 1;
				break;
			case 'L':
				newPos.x -= 1;
				break;
		}
		texture_->setPosition(newPos);
		endReached();
	}

	bool Bomb::endReached()
	{
		FVector position = texture_->getPosition();

		if (static_cast<int>(position.x) == static_cast<int>(endPosition_.x) &&
			static_cast<int>(position.y) == static_cast<int>(endPosition_.y)) {
			shoot_ = false;
			return true;
		}
		return false;
	}
} // namespace arcade