/*
** EPITECH PROJECT, 2022
** missile
** File description:
** missile
*/

#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "IGraphicFactory.hpp"

#include <iostream>

namespace arcade {
	class Missile {
	public:
		// CTOR / DTOR
		Missile() = default;
		Missile(Missile const &other) = delete;
		Missile(Missile &&other) = default;
		virtual ~Missile() noexcept = default;
		Missile &operator=(Missile const &other) = delete;
		Missile &operator=(Missile &&other) = default;

		// GETTERS
		FVector getEndPosition() const;
		IImage &getTexture() const;
		bool getShoot() const;

		// SETTERS
		void setEndPosition(FVector);
		void setShoot(bool);

		// FUNCTIONS
		void shootFromHere(char, FVector, IWindow &, IGraphicFactory &);
		void moveMissile();
		bool endReached();

	private:
		bool shoot_ = false;
		char direction_;
		FVector endPosition_;
		std::unique_ptr<IImage> texture_ = nullptr;
	};
} // namespace arcade

#endif /* !MISSILE_HPP */
