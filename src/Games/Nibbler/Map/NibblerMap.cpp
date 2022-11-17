/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "NibblerMap.hpp"

namespace arcade {

	// CTOR / DTOR
	Map::Map(std::string txt, IWindow &window, IGraphicFactory &graphicFactory)
	{
		int index = 0;
		FVector position {window.getSize().x / 1920 * 360, window.getSize().y / 1010 * 90};

		for (char &i : txt) {
			if (i == 'R' || i == 'G' || i == 'F') {
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
			if (map_[id].getIsSolid() || map_[id].getIsSnake()) {
				return false;
			}
		}
		return true;
	}

	bool Map::isCaseFruit(FVector headPosition, IWindow &window, char direction,
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
			if (map_[id].getIsFruit()) {
				map_[id].getTexture().setTexture("assets/Nibbler/Map/Grass.png");
				map_[id].setIsFruit(false);
				return true;
			}
		}
		return false;
	}

	void Map::updateSnake(FVector front, FVector back, char direction)
	{
		int frontId = getMemberId(front);
		int backId = getMemberId(back);

		map_[frontId].setIsSnake(true);
		map_[backId].setIsSnake(false);
	}

	void Map::addNewFruit(IWindow &window, IGraphicFactory &graphicFactory)
	{
		int emptyCase = 0;
		for (auto &i : map_) {
			if (!i.getIsSolid() && !i.getIsSnake() && !i.getIsFruit()) {
				emptyCase++;
			}
		}
		int addPosition = 0;
		if (emptyCase > 0)
			addPosition = rand() % emptyCase;
		int index = 0;
		for (int i = 0; i < map_.size(); i++) {
			if (map_[i].getIsSolid() || map_[i].getIsSnake() || map_[i].getIsFruit()) {
				continue;
			}
			if (i >= addPosition) {
				map_[i].setCase('F', map_[i].getPosition(), window, graphicFactory);
				return;
			}
			index++;
		}
	}
} // namespace arcade
