/*
** EPITECH PROJECT, 2022
** Spaceship
** File description:
** Spaceship
*/

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "Missile.hpp"

#include <iostream>

namespace arcade {
	class Spaceship {
	public:
		// CTOR / DTOR
		Spaceship() noexcept = default;
		Spaceship(char, FVector, IWindow &, IGraphicFactory &) noexcept;
		Spaceship(Spaceship const &other) = delete;
		Spaceship(Spaceship &&other) = default;
		virtual ~Spaceship() noexcept = default;
		Spaceship &operator=(Spaceship const &other) = delete;
		Spaceship &operator=(Spaceship &&other) = default;

		// GETTERS
		FVector getPosition() const;
		float getRotation() const;
		IImage &getTexture() const;
		Missile const &getMissile() const;

		// SETTERS
		void setPosition(FVector);
		void setRotation(float);
		void setMember(char, FVector, IWindow &, IGraphicFactory &);
		void setMissile(char, IWindow &, IGraphicFactory &);
		void updateMissile();
		void bombCrushed();

	private:
		Missile missile_;
		std::unique_ptr<IImage> texture_;
	};
} // namespace arcade

#endif /* !SPACESHIP_HPP */
