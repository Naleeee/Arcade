/*
** EPITECH PROJECT, 2022
** member
** File description:
** member
*/

#include "SnakeMember.hpp"

namespace arcade {
	// CTOR / DTOR
	Member::Member(char c, FVector position, IWindow &window,
				   IGraphicFactory &graphicFactory) noexcept
		: texture_(nullptr)
	{
		setMember(c, position, window, graphicFactory);
	}

	// GETTERS
	FVector Member::getPosition() const
	{
		return texture_->getPosition();
	}

	float Member::getRotation() const
	{
		return texture_->getRotation();
	}

	IImage &Member::getTexture() const
	{
		return *texture_;
	}

	// SETTERS
	void Member::setPosition(FVector position)
	{
		texture_->setPosition(position);
	}

	void Member::setRotation(float rotation)
	{
		texture_->setRotation(rotation);
	}

	void Member::setMember(char c, FVector position, IWindow &window,
						   IGraphicFactory &graphicFactory)
	{
		if (c == 'B') {
			texture_ = graphicFactory.createImage("assets/Nibbler/Body.png");
		} else if (c == 'H') {
			texture_ = graphicFactory.createImage("assets/Nibbler/head_paper.png");
		}
		texture_->fitSize(FVector {window.getSize().x / 1920 * 60, -1});
		setPosition(position);
	}
} // namespace arcade
