/*
** EPITECH PROJECT, 2022
** missile
** File description:
** missile
*/

#include "Missile.hpp"

namespace arcade {

	// GETTERS
	FVector Missile::getEndPosition() const
	{
		return endPosition_;
	}

	IImage &Missile::getTexture() const
	{
		return *texture_;
	}

	bool Missile::getShoot() const
	{
		return shoot_;
	}

	// SETTERS
	void Missile::setEndPosition(FVector position)
	{
		endPosition_.x = position.x;
		endPosition_.y = position.y;
	}

	void Missile::setShoot(bool shoot)
	{
		shoot_ = shoot;
	}

	// FUNCTIONS
	void Missile::shootFromHere(char direction, FVector position, IWindow &window,
								IGraphicFactory &graphicFactory)
	{
		shoot_ = true;
		direction_ = direction;
		endPosition_ = position;

		switch (direction) {
			case 'T':
				texture_ = graphicFactory.createImage("assets/SolarFox/Fire/Top.png");
				endPosition_.y -= window.getSize().y / 1010 * 120;
				setEndPosition(endPosition_);
				break;
			case 'B':
				texture_ = graphicFactory.createImage("assets/SolarFox/Fire/Bottom.png");
				endPosition_.y += window.getSize().y / 1010 * 120;
				setEndPosition(endPosition_);
				break;
			case 'R':
				texture_ = graphicFactory.createImage("assets/SolarFox/Fire/Right.png");
				endPosition_.x += window.getSize().x / 1920 * 120;
				setEndPosition(endPosition_);
				break;
			case 'L':
				texture_ = graphicFactory.createImage("assets/SolarFox/Fire/Left.png");
				endPosition_.x -= window.getSize().x / 1920 * 120;
				setEndPosition(endPosition_);
				break;
		}
		texture_->setPosition(position);
		texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
	}

	void Missile::moveMissile()
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

	bool Missile::endReached()
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