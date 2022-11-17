/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "NibblerGame.hpp"

namespace arcade {

	std::string getMap()
	{
		std::ifstream file("map/Nibbler/NibMapOne.txt");
		std::string map;
		char c = 0;
		int width = 1;
		int length = 1;
		bool endLine = false;

		if (file.is_open() == false) {
			throw error::GameError("Couldn't open map file map/Nibbler/NibMapOne.txt");
		}
		c = file.get();
		while (file) {
			map += c;
			c = file.get();
			if (c == '\n') {
				length++;
				endLine = true;
			}
			if (endLine == false)
				width++;
		}
		return map;
	}

	// CTOR / DTOR
	NibblerGame::NibblerGame(Player &player, IWindow &window,
							 IGraphicFactory &graphicFactory) noexcept
		: AGame(player, window, graphicFactory)
		, map_(getMap(), window, graphicFactory)
		, snake_(window, graphicFactory)
		, player_(player)
	{
		endScreen_->setPosition(
			FVector {window.getSize().x / 1920 * 365, window.getSize().y / 1920 * 180});
		endScreen_->fitSize(
			FVector {window.getSize().x / 1920 * 1190, window.getSize().y / 1010 * 800});
		endText_->setColor(Color {64, 192, 220, 255});
		pressSpace_->setColor(Color {64, 192, 220, 255});
		name_->setText(std::string(player.name).append(": "));
		name_->setPosition(FVector {window.getSize().x / 4, 0});
		name_->setColor(Color {64, 192, 220, 255});
		score_->setPosition(FVector {name_->getPosition().x + name_->getSize().x, 0});
		score_->setColor(Color {64, 192, 220, 255});
		move_.savePointTime();
	}

	// FUNCTIONS
	bool NibblerGame::handleInput(const Input &input) noexcept
	{
		std::stringstream ss;
		if (state_ == 0) {
			switch (input) {
				case Input::AEVENT_STOP:
					return false;

				case Input::AKEY_Q:
					return false;

				case Input::AKEY_UP:
					if (direction_ != Direction::DOWN && direction_ != Direction::UP) {
						direction_ = Direction::UP;
					}
					break;

				case Input::AKEY_DOWN:
					if (direction_ != Direction::UP && direction_ != Direction::DOWN) {
						direction_ = Direction::DOWN;
					}
					break;

				case Input::AKEY_LEFT:
					if (direction_ != Direction::RIGHT && direction_ != Direction::LEFT) {
						direction_ = Direction::LEFT;
					}
					break;

				case Input::AKEY_RIGHT:
					if (direction_ != Direction::LEFT && direction_ != Direction::RIGHT) {
						direction_ = Direction::RIGHT;
					}
					break;

				default:
					break;
			}
			if (move_.getElapsedTime(speed_)) {
				switch (direction_) {
					case Direction::UP:
						if (map_.isNextCaseFree(snake_.getSnake().front().getPosition(), window,
												'U')) {
							move(direction_);
						} else {
							lose_->play();
							state_ = 2;
						}
						break;

					case Direction::DOWN:
						if (map_.isNextCaseFree(snake_.getSnake().front().getPosition(), window,
												'D')) {
							move(direction_);
						} else {
							lose_->play();
							state_ = 2;
						}
						break;

					case Direction::LEFT:
						if (map_.isNextCaseFree(snake_.getSnake().front().getPosition(), window,
												'L')) {
							move(direction_);
						} else {
							lose_->play();
							state_ = 2;
						}
						break;

					case Direction::RIGHT:
						if (map_.isNextCaseFree(snake_.getSnake().front().getPosition(), window,
												'R')) {
							move(direction_);
						} else {
							lose_->play();
							state_ = 2;
						}
						break;
				}
				move_.savePointTime();
			}
			if (state_ != 2) {
				state_ = checkWin();
			}
		} else if (state_ == 1) {
			endScreen_->setTexture("assets/Nibbler/endWin.jpg");
			endText_->setText("You Win");
			endText_->setPosition(FVector {window.getSize().x / 2 - endText_->getSize().x / 2,
										   window.getSize().y / 4});
			pressSpace_->setText("Press Space To Continue");
			pressSpace_->setPosition(FVector {
				(window.getSize().x / 20 * 7) - endText_->getSize().x / 2, window.getSize().y / 3});
			name_->setPosition(FVector {(window.getSize().x / 2) - (name_->getSize().x),
										window.getSize().y / 4 * 3});
			score_->setPosition(FVector {(window.getSize().x / 2), window.getSize().y / 4 * 3});
			if (input == Input::AKEY_SPACE) {
				state_ = 0;
				return false;
			} else if (input == Input::AEVENT_STOP) {
				state_ = 0;
				return false;
			}
			return true;
		} else {
			endScreen_->setTexture("assets/Nibbler/endLose.jpg");
			endText_->setText("You Lose");
			endText_->setPosition(FVector {window.getSize().x / 2 - endText_->getSize().x / 2,
										   window.getSize().y / 4});
			pressSpace_->setText("Press Space To Continue");
			pressSpace_->setPosition(FVector {
				(window.getSize().x / 20 * 7) - endText_->getSize().x / 2, window.getSize().y / 3});
			name_->setPosition(FVector {(window.getSize().x / 2) - (name_->getSize().x),
										window.getSize().y / 4 * 3});
			score_->setPosition(FVector {(window.getSize().x / 2), window.getSize().y / 4 * 3});
			if (input == Input::AKEY_SPACE) {
				state_ = 0;
				return false;
			} else if (input == Input::AEVENT_STOP) {
				state_ = 0;
				return false;
			}
			return true;
		}
		ss << player.score;
		score_->setText(ss.str());
		return true;
	}

	void NibblerGame::refresh() noexcept
	{
		if (state_ == 0) {
			auto const &map = map_.getMap();
			auto const &snake = snake_.getSnake();

			for (const auto &i : map) {
				window.draw(i.getTexture());
			}
			for (const auto &i : snake) {
				window.draw(i.getTexture());
			}
			window.draw(*name_);
			window.draw(*score_);
		} else {
			window.draw(*endScreen_);
			window.draw(*endText_);
			window.draw(*pressSpace_);
			window.draw(*name_);
			window.draw(*score_);
		}
	}

	void NibblerGame::move(Direction direction)
	{
		FVector newPos = snake_.getSnake().front().getPosition();
		FVector oldBackPosition = snake_.getSnake().back().getPosition();

		switch (direction) {
			case Direction::UP:
				newPos.y -= window.getSize().y / 1010 * 60;
				break;
			case Direction::DOWN:
				newPos.y += window.getSize().y / 1010 * 60;
				break;
			case Direction::LEFT:
				newPos.x -= window.getSize().x / 1920 * 60;
				break;
			case Direction::RIGHT:
				newPos.x += window.getSize().x / 1920 * 60;
				break;
			default:
				break;
		}

		snake_.moveSnake(newPos);

		switch (direction) {
			case Direction::UP:
				map_.updateSnake(snake_.getSnake().front().getPosition(), oldBackPosition, 'U');
				if (map_.isCaseFruit(snake_.getSnake().front().getPosition(), window, 'U',
									 graphicFactory)) {
					eat_->play();
					if (speed_ >= 250)
						speed_ -= 100;
					player.score += 500;
					snake_.addMember(window, graphicFactory);
					map_.addNewFruit(window, graphicFactory);
				}
				break;
			case Direction::DOWN:
				map_.updateSnake(snake_.getSnake().front().getPosition(), oldBackPosition, 'D');
				if (map_.isCaseFruit(snake_.getSnake().front().getPosition(), window, 'D',
									 graphicFactory)) {
					eat_->play();
					if (speed_ >= 250)
						speed_ -= 100;
					player.score += 500;
					snake_.addMember(window, graphicFactory);
					map_.addNewFruit(window, graphicFactory);
				}
				break;
			case Direction::LEFT:
				map_.updateSnake(snake_.getSnake().front().getPosition(), oldBackPosition, 'L');
				if (map_.isCaseFruit(snake_.getSnake().front().getPosition(), window, 'L',
									 graphicFactory)) {
					eat_->play();
					if (speed_ >= 250)
						speed_ -= 100;
					player.score += 500;
					snake_.addMember(window, graphicFactory);
					map_.addNewFruit(window, graphicFactory);
				}
				break;
			case Direction::RIGHT:
				map_.updateSnake(snake_.getSnake().front().getPosition(), oldBackPosition, 'R');
				if (map_.isCaseFruit(snake_.getSnake().front().getPosition(), window, 'R',
									 graphicFactory)) {
					eat_->play();
					if (speed_ >= 250)
						speed_ -= 100;
					player.score += 500;
					snake_.addMember(window, graphicFactory);
					map_.addNewFruit(window, graphicFactory);
				}
				break;
			default:
				break;
		}
	}

	bool NibblerGame::checkWin()
	{
		auto const &map = map_.getMap();
		int emptyCase = 0;

		for (const auto &i : map_.getMap()) {
			if (!i.getIsSolid() && !i.getIsSnake() && !i.getIsFruit()) {
				emptyCase++;
			}
		}
		if (emptyCase == 0) {
			win_->play();
			return true;
		}
		return false;
	}
} // namespace arcade
