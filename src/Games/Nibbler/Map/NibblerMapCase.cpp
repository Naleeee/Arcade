/*
** EPITECH PROJECT, 2022
** cas
** File description:
** case
*/

#include "NibblerMapCase.hpp"

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

	bool Case::getIsSnake() const
	{
		return snake_;
	}

	bool Case::getIsFruit() const
	{
		return fruit_;
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

	void Case::setIsSnake(bool state)
	{
		snake_ = state;
	}

	void Case::setIsFruit(bool state)
	{
		fruit_ = state;
	}

	void Case::setCase(char c, FVector position, IWindow &window, IGraphicFactory &graphicFactory)
	{
		if (c == 'G') {
			setSolid(false);
			setIsFruit(false);
			texture_ = graphicFactory.createImage("assets/Nibbler/Map/Grass.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'R') {
			setSolid(true);
			setIsFruit(false);
			texture_ = graphicFactory.createImage("assets/Nibbler/Map/Rock.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		} else if (c == 'F') {
			setSolid(false);
			setIsFruit(true);
			texture_ = graphicFactory.createImage("assets/Nibbler/Map/XxFruit_KiwixX.png");
			texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		}
		setPosition(position);
		setIsSnake(false);
	}
} // namespace arcade
