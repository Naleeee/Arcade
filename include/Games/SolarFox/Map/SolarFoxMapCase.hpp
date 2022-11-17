/*
** EPITECH PROJECT, 2022
** case
** File description:
** case
*/

#ifndef CASE_HPP
#define CASE_HPP

#include "IGameFactory.hpp"
#include "IGraphicFactory.hpp"

#include <iostream>

namespace arcade {
	class Case {
	public:
		// CTOR / DTOR
		Case() = default;
		Case(char, FVector, IWindow &, IGraphicFactory &) noexcept;
		Case(Case const &other) = delete;
		Case(Case &&other) = default;
		virtual ~Case() noexcept = default;
		Case &operator=(Case const &other) = delete;
		Case &operator=(Case &&other) = default;

		// GETTERS
		FVector getPosition() const;
		bool getIsSolid() const;
		bool getIsCoin() const;
		char getDirection() const;
		IImage &getTexture() const;

		// SETTERS
		void setPosition(FVector);
		void setSolid(bool);
		void setIsCoin(bool);
		void setCase(char, FVector, IWindow &, IGraphicFactory &);

	private:
		FVector position_ {};
		bool solid_ = true;
		bool coin_ = false;
		char direction_ = 'N';
		std::unique_ptr<IImage> texture_;
	};
} // namespace arcade

#endif /* !CASE_HPP */
