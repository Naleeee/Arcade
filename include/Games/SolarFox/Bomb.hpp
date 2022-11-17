/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#ifndef BOMB_HPP
#define BOMB_HPP

#include "IGraphicFactory.hpp"

#include <iostream>

namespace arcade {
	class Bomb {
	public:
		// CTOR / DTOR
		Bomb() = default;
		Bomb(Bomb const &other) = delete;
		Bomb(Bomb &&other) = default;
		virtual ~Bomb() noexcept = default;
		Bomb &operator=(Bomb const &other) = delete;
		Bomb &operator=(Bomb &&other) = default;

		// GETTERS
		FVector getEndPosition() const;
		IImage &getTexture() const;
		bool getShoot() const;

		// SETTERS
		void setEndPosition(FVector);
		void setShoot(bool);

		// FUNCTIONS
		void shootFromHere(char, FVector, IWindow &, IGraphicFactory &);
		void moveBomb();
		bool endReached();

	private:
		bool shoot_ = false;
		char direction_;
		FVector endPosition_;
		std::unique_ptr<IImage> texture_ = nullptr;
	};
} // namespace arcade

#endif /* !BOMB_HPP */
