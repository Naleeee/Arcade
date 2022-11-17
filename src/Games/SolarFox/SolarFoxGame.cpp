/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "SolarFoxGame.hpp"

namespace arcade {

	std::string getMap()
	{
		std::ifstream file("map/SolarFox/SolMapOne.txt");
		std::string map;
		char c = 0;
		int width = 1;
		int length = 1;
		bool endLine = false;

		if (file.is_open() == false) {
			throw error::GameError("Couldn't open map file map/SolarFox/SolMapOne.txt");
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
	SolarFoxGame::SolarFoxGame(Player &player, IWindow &window,
							   IGraphicFactory &graphicFactory) noexcept
		: AGame(player, window, graphicFactory)
		, map_(getMap(), window, graphicFactory)
		, spaceship_('W',
					 FVector {window.getSize().x / 1920 * 960, window.getSize().y / 1010 * 510},
					 window, graphicFactory)
		, player_(player)
	{
		endScreen_->setPosition(
			FVector {window.getSize().x / 1920 * 365, window.getSize().y / 1920 * 180});
		endScreen_->fitSize(
			FVector {window.getSize().x / 1920 * 1190, window.getSize().y / 1010 * 800});
		endText_->setColor(Color {64, 192, 220, 255});
		pressSpace_->setColor(Color {64, 192, 220, 255});
		name_->setText(std::string(player_.name).append(": "));
		name_->setPosition(FVector {window.getSize().x / 4, 0});
		score_->setPosition(FVector {name_->getPosition().x + name_->getSize().x, 0});
		name_->setColor(Color {64, 192, 220, 255});
		score_->setColor(Color {64, 192, 220, 255});
		bombTimer_.savePointTime();
	}

	// FUNCTIONS
	bool SolarFoxGame::handleInput(const Input &input) noexcept
	{
		std::stringstream ss;
		if (state_ == 0) {
			switch (input) {
				case Input::AEVENT_STOP:
					return false;

				case Input::AKEY_Q:
					return false;

				case Input::AKEY_UP:
					direction_ = Direction::UP;
					if (map_.isNextCaseFree(spaceship_.getPosition(), window, 'U')) {
						spaceship_.getTexture().setTexture("assets/SolarFox/Mario/MarioBack.png");
						move(direction_);
					}
					break;

				case Input::AKEY_DOWN:
					direction_ = Direction::DOWN;
					if (map_.isNextCaseFree(spaceship_.getPosition(), window, 'D')) {
						spaceship_.getTexture().setTexture("assets/SolarFox/Mario/Down.png");
						move(direction_);
					}
					break;

				case Input::AKEY_LEFT:
					direction_ = Direction::LEFT;
					if (map_.isNextCaseFree(spaceship_.getPosition(), window, 'L')) {
						spaceship_.getTexture().setTexture("assets/SolarFox/Mario/Left.png");
						move(direction_);
					}
					break;

				case Input::AKEY_RIGHT:
					direction_ = Direction::RIGHT;
					if (map_.isNextCaseFree(spaceship_.getPosition(), window, 'R')) {
						spaceship_.getTexture().setTexture("assets/SolarFox/Mario/Right.png");
						move(direction_);
					}
					break;

				case Input::AKEY_SPACE:
					fireball_->play();
					fire();
					break;

				default:
					break;
			}
			spaceship_.updateMissile();
			if (bombTimer_.getElapsedTime(1000)) {
				if (bomb_.getShoot()) {
					bomb_.moveBomb();
				} else {
					bombTimer_.savePointTime();
					shootBomb();
				}
			}
			checkCollisions();
			if (state_ != 2) {
				state_ = checkWin();
			}
		} else if (state_ == 1) {
			endText_->setText("You Win");
			endScreen_->setTexture("assets/SolarFox/endWin.jpg");
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
			endText_->setText("You Lose");
			endScreen_->setTexture("assets/SolarFox/endLose.jpg");
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
		ss << player_.score;
		score_->setText(ss.str());
		return true;
	}

	void SolarFoxGame::refresh() noexcept
	{
		if (state_ == 0) {
			auto const &map = map_.getMap();

			for (const auto &i : map) {
				window.draw(i.getTexture());
			}
			if (bomb_.getShoot()) {
				window.draw(bomb_.getTexture());
			}
			if (spaceship_.getMissile().getShoot()) {
				window.draw(spaceship_.getMissile().getTexture());
			}
			window.draw(spaceship_.getTexture());
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

	void SolarFoxGame::move(Direction direction)
	{
		FVector newPos = spaceship_.getPosition();

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

		spaceship_.setPosition(newPos);

		switch (direction) {
			case Direction::UP:
				if (map_.isCaseCoin(spaceship_.getPosition(), window, 'U', graphicFactory)) {
					coin_->play();
					player_.score += 500;
				}
				break;
			case Direction::DOWN:
				if (map_.isCaseCoin(spaceship_.getPosition(), window, 'D', graphicFactory)) {
					coin_->play();
					player_.score += 500;
				}
				break;
			case Direction::LEFT:
				if (map_.isCaseCoin(spaceship_.getPosition(), window, 'L', graphicFactory)) {
					coin_->play();
					player_.score += 500;
				}
				break;
			case Direction::RIGHT:
				if (map_.isCaseCoin(spaceship_.getPosition(), window, 'R', graphicFactory)) {
					coin_->play();
					player_.score += 500;
				}
				break;
			default:
				break;
		}
	}

	bool SolarFoxGame::checkWin()
	{
		auto const &map = map_.getMap();
		int emptyCase = 0;

		for (const auto &i : map_.getMap()) {
			if (i.getIsCoin()) {
				return false;
			}
		}
		win_->play();
		return true;
	}

	void SolarFoxGame::fire()
	{
		switch (direction_) {
			case Direction::UP:
				spaceship_.setMissile('T', window, graphicFactory);
				break;
			case Direction::DOWN:
				spaceship_.setMissile('B', window, graphicFactory);
				break;
			case Direction::RIGHT:
				spaceship_.setMissile('R', window, graphicFactory);
				break;
			case Direction::LEFT:
				spaceship_.setMissile('L', window, graphicFactory);
				break;
		}
	}

	void SolarFoxGame::shootBomb()
	{
		int nbShooter = 0;
		int index = 0;
		FVector position {0, 0};

		for (const auto &i : map_.getMap()) {
			if (i.getDirection() == 'N')
				continue;
			nbShooter++;
		}

		int shooterPosition = 0;
		if (nbShooter > 0)
			shooterPosition = rand() % nbShooter;
		char direction = 'N';

		for (const auto &i : map_.getMap()) {
			if (i.getDirection() == 'N')
				continue;
			if (index != shooterPosition) {
				index++;
				continue;
			}
			position = i.getPosition();
			direction = i.getDirection();
			index++;
		}

		switch (direction) {
			case 'T':
				bomb_.shootFromHere('B', position, window, graphicFactory);
				break;
			case 'B':
				bomb_.shootFromHere('T', position, window, graphicFactory);
				break;
			case 'R':
				bomb_.shootFromHere('L', position, window, graphicFactory);
				break;
			case 'L':
				bomb_.shootFromHere('R', position, window, graphicFactory);
				break;
			default:
				break;
		}
	}

	void SolarFoxGame::checkCollisions()
	{
		if (!bomb_.getShoot()) {
			return;
		}
		if (spaceship_.getMissile().getShoot()) {
			if ((static_cast<int>(bomb_.getTexture().getPosition().x) >=
					 static_cast<int>(spaceship_.getMissile().getTexture().getPosition().x) &&
				 static_cast<int>(bomb_.getTexture().getPosition().x) <
					 static_cast<int>(spaceship_.getMissile().getTexture().getPosition().x) +
						 window.getSize().x / 1920 * 60) &&
				(static_cast<int>(bomb_.getTexture().getPosition().y) ==
					 static_cast<int>(spaceship_.getMissile().getTexture().getPosition().y) &&
				 static_cast<int>(bomb_.getTexture().getPosition().y) <
					 static_cast<int>(spaceship_.getMissile().getTexture().getPosition().y) +
						 window.getSize().x / 1010 * 60)) {
				goomba_->play();
				player_.score += 1000;
				bomb_.setShoot(false);
				spaceship_.bombCrushed();
			}
		}
		if ((static_cast<int>(bomb_.getTexture().getPosition().x) >=
				 static_cast<int>(spaceship_.getTexture().getPosition().x) &&
			 static_cast<int>(bomb_.getTexture().getPosition().x) <
				 static_cast<int>(spaceship_.getTexture().getPosition().x) +
					 window.getSize().x / 1920 * 60) &&
			(static_cast<int>(bomb_.getTexture().getPosition().y) ==
				 static_cast<int>(spaceship_.getTexture().getPosition().y) &&
			 static_cast<int>(bomb_.getTexture().getPosition().y) <
				 static_cast<int>(spaceship_.getTexture().getPosition().y) +
					 window.getSize().x / 1010 * 60)) {
			death_->play();
			bomb_.setShoot(false);
			state_ = 2;
		}
	}
} // namespace arcade
