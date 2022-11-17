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
		Case() noexcept = default;
		Case(char, FVector, IWindow &, IGraphicFactory &) noexcept;
		Case(Case const &other) = delete;
		Case(Case &&other) = default;
		virtual ~Case() noexcept = default;
		Case &operator=(Case const &other) = delete;
		Case &operator=(Case &&other) = default;

		// GETTERS
		FVector getPosition() const;
		bool getIsSolid() const;
		bool getIsSnake() const;
		bool getIsFruit() const;
		IImage &getTexture() const;

		// SETTERS
		void setPosition(FVector);
		void setSolid(bool);
		void setIsSnake(bool);
		void setIsFruit(bool);
		void setCase(char, FVector, IWindow &, IGraphicFactory &);

	private:
		FVector position_ {};
		bool solid_ = true;
		bool snake_ = false;
		bool fruit_ = false;
		std::unique_ptr<IImage> texture_;
	};
} // namespace arcade

#endif /* !CASE_HPP */
