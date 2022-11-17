/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#ifndef SOLARFOX_GAME_HPP
#define SOLARFOX_GAME_HPP

#include "Bomb.hpp"
#include "Clock.hpp"
#include "GameError.hpp"
#include "IGameFactory.hpp"
#include "SolarFoxMap.hpp"
#include "Spaceship.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace arcade {

	enum class Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

	class SolarFoxGame : public AGame {
	public:
		// CTOR / DTOR
		SolarFoxGame() = delete;
		SolarFoxGame(Player &, IWindow &, IGraphicFactory &) noexcept;
		SolarFoxGame(SolarFoxGame const &other) = delete;
		SolarFoxGame(SolarFoxGame &&other) = delete;
		~SolarFoxGame() noexcept override = default;
		SolarFoxGame &operator=(SolarFoxGame const &other) = delete;
		SolarFoxGame &operator=(SolarFoxGame &&other) = delete;

		// FUNCTIONS
		bool handleInput(const Input &) noexcept override;
		void refresh() noexcept override;
		void move(Direction);
		bool checkWin();
		void fire();
		void shootBomb();
		void checkCollisions();

	protected:
	private:
		int state_ = 0;
		Clock bombTimer_;
		Bomb bomb_;
		Map map_;
		Spaceship spaceship_;
		Player &player_;
		Direction direction_ = Direction::RIGHT;
		std::unique_ptr<IText> name_ = graphicFactory.createText("assets/SolarFox/Score.ttf");
		std::unique_ptr<IText> score_ = graphicFactory.createText("assets/SolarFox/Score.ttf");
		std::unique_ptr<IImage> endScreen_ =
			graphicFactory.createImage("assets/SolarFox/endWin.jpg");
		std::unique_ptr<IText> endText_ = graphicFactory.createText("assets/SolarFox/Score.ttf");
		std::unique_ptr<ISound> coin_ =
			graphicFactory.createSound("sound/effects/SolarFox/Coin.wav");
		std::unique_ptr<ISound> death_ =
			graphicFactory.createSound("sound/effects/SolarFox/Death.wav");
		std::unique_ptr<ISound> fireball_ =
			graphicFactory.createSound("sound/effects/SolarFox/Fireball.wav");
		std::unique_ptr<ISound> goomba_ =
			graphicFactory.createSound("sound/effects/SolarFox/Goomba.wav");
		std::unique_ptr<ISound> win_ = graphicFactory.createSound("sound/effects/SolarFox/Win.wav");
		std::unique_ptr<IText> pressSpace_ = graphicFactory.createText("assets/Nibbler/Score.ttf");
	};
} // namespace arcade

#endif /* !SOLARFOX_GAME_HPP */
