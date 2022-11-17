/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "SolarFoxMap.hpp"

namespace arcade {

	// CTOR / DTOR
	Map::Map(std::string txt, IWindow &window, IGraphicFactory &graphicFactory)
	{
		int index = 0;
		FVector position {window.getSize().x / 1920 * 360, window.getSize().y / 1010 * 90};

		for (char &i : txt) {
			if (i == 'T' || i == 'B' || i == 'L' || i == 'R' || i == 'S' || i == 'C') {
				if (position.x > window.getSize().x / 1920 * 1500) {
					position.x = window.getSize().x / 1920 * 360;
					position.y += window.getSize().y / 1010 * 60;
				}
				map_.emplace_back(i, position, window, graphicFactory);
				index++;
				position.x += window.getSize().x / 1920 * 60;
			}
		}
	}

	// GETTERS
	std::vector<Case> const &Map::getMap() const
	{
		return map_;
	}

	int Map::getMemberId(FVector check)
	{
		for (int i = 0; i < map_.size(); i++) {
			if (static_cast<int>(map_[i].getPosition().x) == static_cast<int>(check.x) &&
				static_cast<int>(map_[i].getPosition().y) == static_cast<int>(check.y)) {
				return i;
			}
		}
		return -1;
	}

	// FUNCTIONS
	bool Map::isNextCaseFree(FVector headPosition, IWindow &window, char direction)
	{
		FVector check = headPosition;

		switch (direction) {
			case 'U':
				check.y -= window.getSize().y / 1010 * 60;
				break;
			case 'D':
				check.y += window.getSize().y / 1010 * 60;
				break;
			case 'L':
				check.x -= window.getSize().x / 1920 * 60;
				break;
			case 'R':
				check.x += window.getSize().x / 1920 * 60;
				break;
			default:
				break;
		}
		int id = getMemberId(check);
		if (id >= 0) {
			if (map_[id].getIsSolid()) {
				return false;
			}
		}
		return true;
	}

	bool Map::isCaseCoin(FVector headPosition, IWindow &window, char direction,
						 IGraphicFactory &graphicFactory)
	{
		FVector check = headPosition;
		switch (direction) {
			case 'U':
				check.y -= window.getSize().y / 1010 * 60;
				break;
			case 'D':
				check.y += window.getSize().y / 1010 * 60;
				break;
			case 'L':
				check.x -= window.getSize().x / 1920 * 60;
				break;
			case 'R':
				check.x += window.getSize().x / 1920 * 60;
				break;
			default:
				break;
		}
		int id = getMemberId(headPosition);
		if (id >= 0) {
			if (map_[id].getIsCoin()) {
				map_[id].getTexture().setTexture("assets/SolarFox/Map/Grass.png");
				map_[id].setIsCoin(false);
				return true;
			}
		}
		return false;
	}
} // namespace arcade
