/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#ifndef NIBBLER_GAME_HPP
#define NIBBLER_GAME_HPP

#include "Clock.hpp"
#include "GameError.hpp"
#include "IGameFactory.hpp"
#include "NibblerMap.hpp"
#include "Snake.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace arcade {

	enum class Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

	class NibblerGame : public AGame {
	public:
		// CTOR / DTOR
		NibblerGame() = delete;
		NibblerGame(Player &, IWindow &, IGraphicFactory &) noexcept;
		NibblerGame(NibblerGame const &other) = delete;
		NibblerGame(NibblerGame &&other) = delete;
		~NibblerGame() noexcept override = default;
		NibblerGame &operator=(NibblerGame const &other) = delete;
		NibblerGame &operator=(NibblerGame &&other) = delete;

		// FUNCTIONS
		bool handleInput(const Input &) noexcept override;
		void refresh() noexcept override;
		void move(Direction);
		bool checkWin();

	protected:
	private:
		int state_ = 0;
		Map map_;
		Snake snake_;
		Player &player_;
		Direction direction_ = Direction::RIGHT;
		Clock move_;
		int speed_ = 1000;
		std::unique_ptr<IText> name_ = graphicFactory.createText("assets/Nibbler/Score.ttf");
		std::unique_ptr<IText> score_ = graphicFactory.createText("assets/Nibbler/Score.ttf");
		std::unique_ptr<ISound> eat_ = graphicFactory.createSound("sound/effects/Nibbler/Eat.wav");
		std::unique_ptr<ISound> lose_ =
			graphicFactory.createSound("sound/effects/Nibbler/Lose.wav");
		std::unique_ptr<ISound> win_ = graphicFactory.createSound("sound/effects/Nibbler/Win.wav");
		std::unique_ptr<IImage> endScreen_ =
			graphicFactory.createImage("assets/Nibbler/endWin.jpg");
		std::unique_ptr<IText> endText_ = graphicFactory.createText("assets/Nibbler/Score.ttf");
		std::unique_ptr<IText> pressSpace_ = graphicFactory.createText("assets/Nibbler/Score.ttf");
	};
} // namespace arcade

#endif /* !NIBBLER_GAME_HPP */
