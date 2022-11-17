/*
** EPITECH PROJECT, 2022
** Spaceship
** File description:
** Spaceship
*/

#include "Spaceship.hpp"

namespace arcade {
	// CTOR / DTOR
	Spaceship::Spaceship(char c, FVector position, IWindow &window,
						 IGraphicFactory &graphicFactory) noexcept
		: texture_(nullptr)
	{
		setMember(c, position, window, graphicFactory);
	}

	// GETTERS
	FVector Spaceship::getPosition() const
	{
		return texture_->getPosition();
	}

	float Spaceship::getRotation() const
	{
		return texture_->getRotation();
	}

	IImage &Spaceship::getTexture() const
	{
		return *texture_;
	}

	Missile const &Spaceship::getMissile() const
	{
		return missile_;
	}

	// SETTERS
	void Spaceship::setPosition(FVector position)
	{
		texture_->setPosition(position);
		// missile_.moveMissile();
	}

	void Spaceship::setRotation(float rotation)
	{
		texture_->setRotation(rotation);
	}

	void Spaceship::setMember(char c, FVector position, IWindow &window,
							  IGraphicFactory &graphicFactory)
	{
		if (c == 'W') {
			texture_ = graphicFactory.createImage("assets/SolarFox/Mario/Right.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		}
		setPosition(position);
	}

	void Spaceship::setMissile(char direction, IWindow &window, IGraphicFactory &graphicFactory)
	{
		if (!missile_.getShoot()) {
			missile_.shootFromHere(direction, getPosition(), window, graphicFactory);
		}
	}

	void Spaceship::updateMissile()
	{
		if (missile_.getShoot()) {
			missile_.moveMissile();
		}
	}

	void Spaceship::bombCrushed()
	{
		missile_.setShoot(false);
	}
} // namespace arcade
