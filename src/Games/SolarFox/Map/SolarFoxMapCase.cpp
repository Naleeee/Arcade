/*
** EPITECH PROJECT, 2022
** cas
** File description:
** case
*/

#include "SolarFoxMapCase.hpp"

namespace arcade {

	// CTOR / DTOR
	Case::Case(char c, FVector position, IWindow &window, IGraphicFactory &graphicFactory) noexcept
		: texture_(nullptr)
	{
		setCase(c, position, window, graphicFactory);
	}

	// GETTERS
	FVector Case::getPosition() const
	{
		return texture_->getPosition();
	}

	bool Case::getIsSolid() const
	{
		return solid_;
	}

	bool Case::getIsCoin() const
	{
		return coin_;
	}

	char Case::getDirection() const
	{
		return direction_;
	}

	IImage &Case::getTexture() const
	{
		return *texture_;
	}

	// SETTERS
	void Case::setPosition(FVector position)
	{
		texture_->setPosition(position);
	}

	void Case::setSolid(bool solidity)
	{
		solid_ = solidity;
	}

	void Case::setIsCoin(bool state)
	{
		coin_ = state;
	}

	void Case::setCase(char c, FVector position, IWindow &window, IGraphicFactory &graphicFactory)
	{
		if (c == 'T') {
			setSolid(true);
			setIsCoin(false);
			direction_ = 'T';
			texture_ = graphicFactory.createImage("assets/SolarFox/Map/Bricksss.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'B') {
			setSolid(true);
			setIsCoin(false);
			direction_ = 'B';
			texture_ = graphicFactory.createImage("assets/SolarFox/Map/Bricksss.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'L') {
			setSolid(true);
			setIsCoin(false);
			direction_ = 'L';
			texture_ = graphicFactory.createImage("assets/SolarFox/Map/Bricksss.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'R') {
			setSolid(true);
			setIsCoin(false);
			direction_ = 'R';
			texture_ = graphicFactory.createImage("assets/SolarFox/Map/Bricksss.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'S') {
			setSolid(false);
			setIsCoin(false);
			texture_ = graphicFactory.createImage("assets/SolarFox/Map/Grass.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'C') {
			setSolid(false);
			setIsCoin(true);
			texture_ = graphicFactory.createImage("assets/SolarFox/Map/OneXxCoiin.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		}
		setPosition(position);
	}
} // namespace arcade
