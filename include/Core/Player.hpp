/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Player
*/

#ifndef PLAYERINFO_HPP_
#define PLAYERINFO_HPP_

#include "ArcadeError.hpp"
#include "IGameFactory.hpp"
#include "IGraphicFactory.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace arcade {

	class PlayerInfo {
	public:
		struct Score {
			std::string gameName;
			std::string playerName;
			std::string playerScore;
		};

		// CTOR / DTOR
		PlayerInfo() = default;
		PlayerInfo(IGraphicFactory &FGraphic, IWindow &window);
		PlayerInfo(PlayerInfo const &other) = delete;
		PlayerInfo(PlayerInfo &&other) = delete;
		~PlayerInfo() noexcept;
		PlayerInfo &operator=(PlayerInfo const &other) = delete;
		PlayerInfo &operator=(PlayerInfo &&other) = delete;

		std::vector<std::string> splitString(std::string str, char delim) const;
		void setScoreFile(Player &, std::string);
		std::string getScore();
		std::string getPlayer();
		ISound const &getSound() const;
		void findScore(std::string);
		void setPseudo(char, IWindow &);
		std::string_view getName();
		int tryEvent(IWindow &, bool *);
		void display(IWindow &);
		void stopTheme();

	protected:
	private:
		std::unordered_map<int, Score> ScorePlayer;
		int id_ = 0;
		std::vector<Score> tabGame;
		std::unique_ptr<IText> Message_;
		std::string rawPseudo_;
		std::unique_ptr<IImage> Wall_;
		std::unique_ptr<IImage> Textbox_;
		std::unique_ptr<IText> Pseudo;
		std::unique_ptr<ISound> Key_ = nullptr;
		std::unique_ptr<ISound> Theme_ = nullptr;
	};
} // namespace arcade

#endif /* !PLAYERINFO_HPP_ */
