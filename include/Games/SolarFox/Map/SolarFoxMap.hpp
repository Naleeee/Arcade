/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#ifndef MAP_HPP
#define MAP_HPP

#include "SolarFoxMapCase.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

namespace arcade {
	class Map {
	public:
		// CTOR / DTOR
		Map() noexcept = delete;
		Map(std::string, IWindow &, IGraphicFactory &);
		Map(Map const &other) = delete;
		Map(Map &&other) = default;
		virtual ~Map() noexcept = default;
		Map &operator=(Map const &other) = delete;
		Map &operator=(Map &&other) = default;

		// GETTERS
		std::vector<Case> const &getMap() const;
		int getMemberId(FVector);

		// FUNCTIONS
		bool isNextCaseFree(FVector, IWindow &, char);
		bool isCaseCoin(FVector, IWindow &, char, IGraphicFactory &);

	private:
		std::vector<Case> map_;
	};
} // namespace arcade

#endif /* !MAP_HPP */
