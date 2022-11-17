/*
** EPITECH PROJECT, 2022
** member
** File description:
** member
*/

#ifndef MEMBER_HPP
#define MEMBER_HPP

#include "IGameFactory.hpp"
#include "IGraphicFactory.hpp"

#include <iostream>

namespace arcade {
	class Member {
	public:
		// CTOR / DTOR
		Member() noexcept = default;
		Member(char, FVector, IWindow &, IGraphicFactory &) noexcept;
		Member(Member const &other) = delete;
		Member(Member &&other) = default;
		virtual ~Member() noexcept = default;
		Member &operator=(Member const &other) = delete;
		Member &operator=(Member &&other) = default;

		// GETTERS
		FVector getPosition() const;
		float getRotation() const;
		IImage &getTexture() const;

		// SETTERS
		void setPosition(FVector);
		void setRotation(float);
		void setMember(char, FVector, IWindow &, IGraphicFactory &);

	private:
		std::unique_ptr<IImage> texture_;
	};
} // namespace arcade

#endif /* !MEMBER_HPP */
