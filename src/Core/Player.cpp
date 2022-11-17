/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Player
*/

#include "Player.hpp"

#include "Clock.hpp"

namespace arcade {
	PlayerInfo::PlayerInfo(IGraphicFactory &FGraphic, IWindow &window)
	{
		std::ifstream file("./Scores/Scoreboard.txt");
		std::string str;
		std::string line;
		std::vector<std::string> vec;
		char c = 0;
		int id = 0;
		Score tabScore;

		if (file.is_open() == false) {
			throw error::ArcadeError("Couldn't open file ./Scores/Scoreboard.txt");
		}
		while (getline(file, line)) {
			if (line.empty())
				continue;
			vec = splitString(line, ':');
			if (vec.size() != 3) {
				throw error::ArcadeError("Incorrect scoreboard file format");
			}
			tabScore.gameName = vec[0];
			tabScore.playerName = vec[1];
			tabScore.playerScore = vec[2];
			ScorePlayer[id] = tabScore;
			id++;
		}
		file.close();

		Message_ = FGraphic.createText("assets/Menu/Arcade.ttf");
		Message_->setText("Enter Pseudo");
		Message_->setPosition(
			{(window.getSize().x - Message_->getSize().x) / 2, window.getSize().y / 10 * 4});
		Message_->setColor(Color {255, 255, 255, 255});
		Wall_ = FGraphic.createImage("assets/Player/wallpaper.png");
		Wall_->fitSize(FVector {window.getSize().x / 1920 * 1200, window.getSize().y / 1010 * 720});
		Wall_->setPosition(
			FVector {(window.getSize().x - Wall_->getSize().x) / 2,
					 (window.getSize().y - (Wall_->getSize().y + (Wall_->getSize().y / 7))) / 2});
		Textbox_ = FGraphic.createImage("assets/Player/name.png");
		Textbox_->fitSize(
			FVector {window.getSize().x / 1920 * 400, window.getSize().y / 1010 * 200});
		Textbox_->setPosition(FVector {(window.getSize().x - Textbox_->getSize().x) / 2,
									   (window.getSize().y / 60 * 31)});
		Pseudo = FGraphic.createText("assets/Menu/Arcade.ttf");
		Pseudo->setText("");
		Pseudo->setPosition({window.getSize().x / 2, window.getSize().y / 10 * 8});
		Pseudo->setColor(Color {64, 192, 220, 255});
		Key_ = FGraphic.createSound("sound/effects/Menu/Click.wav");
		Theme_ = FGraphic.createSound("sound/effects/Menu/Theme.wav");
		Theme_->play();
		Theme_->setLoop(true);
	}

	PlayerInfo::~PlayerInfo() noexcept 
	{
		std::stringstream str;
		std::ofstream file;

		// NOLINTNEXTLINE
		for (int i = 0; i != ScorePlayer.size(); i++) {
			str << ScorePlayer[i].gameName << ":" << ScorePlayer[i].playerName << ":"
				<< ScorePlayer[i].playerScore << std::endl;
		}
		file.open("./Scores/Scoreboard.txt");
		if (file.is_open()) {
			file << str.rdbuf();
		}
	}

	std::vector<std::string> PlayerInfo::splitString(std::string str, char delim) const
	{
		std::vector<std::string> vector;
		std::string word = "";

		for (int i = 0; str[i]; i++) {
			if (str[i] != delim) {
				word += str[i];
			} else if (word.empty() == false) {
				vector.emplace_back(word);
				word = "";
			}
		}
		if (word.empty() == false)
			vector.emplace_back(word);
		return vector;
	}

	void PlayerInfo::setPseudo(char letter, IWindow &window)
	{
		if (rawPseudo_.length() < 10) {
			Message_->setColor(Color {255, 255, 255, 255});
			rawPseudo_.push_back(letter);
			Pseudo->setText(rawPseudo_);
			Key_->play();
		}
	}

	int PlayerInfo::tryEvent(IWindow &window, bool *End)
	{
		int val = -1;
		Input input = window.getInput();

		switch (input) {
			case Input::AEVENT_STOP:
				*End = true;
				break;
			case Input::AKEY_ESC:
				Key_->play();
				*End = true;
				break;
			case Input::AKEY_ENTER:
				Key_->play();
				if (rawPseudo_.length() == 0) {
					Message_->setColor(Color {255, 0, 0, 255});
				} else {
					Theme_->stop();
					val = 0;
				}
				break;
			case Input::AKEY_BACKSPACE:
				Key_->play();
				if (rawPseudo_.compare("Enter Pseudo") == 0) {
					rawPseudo_.erase();
					Pseudo->setText(rawPseudo_);
				}
				if (rawPseudo_.length() > 0) {
					rawPseudo_.pop_back();
					Pseudo->setText(rawPseudo_);
				}
				break;
			case Input::AKEY_SPACE:
				setPseudo('_', window);
				break;
			case Input::AKEY_A:
				setPseudo('A', window);
				break;
			case Input::AKEY_B:
				setPseudo('B', window);
				break;
			case Input::AKEY_C:
				setPseudo('C', window);
				break;
			case Input::AKEY_D:
				setPseudo('D', window);
				break;
			case Input::AKEY_E:
				setPseudo('E', window);
				break;
			case Input::AKEY_F:
				setPseudo('F', window);
				break;
			case Input::AKEY_G:
				setPseudo('G', window);
				break;
			case Input::AKEY_H:
				setPseudo('H', window);
				break;
			case Input::AKEY_I:
				setPseudo('I', window);
				break;
			case Input::AKEY_J:
				setPseudo('J', window);
				break;
			case Input::AKEY_K:
				setPseudo('K', window);
				break;
			case Input::AKEY_L:
				setPseudo('L', window);
				break;
			case Input::AKEY_M:
				setPseudo('M', window);
				break;
			case Input::AKEY_N:
				setPseudo('N', window);
				break;
			case Input::AKEY_O:
				setPseudo('O', window);
				break;
			case Input::AKEY_P:
				setPseudo('P', window);
				break;
			case Input::AKEY_Q:
				setPseudo('Q', window);
				break;
			case Input::AKEY_R:
				setPseudo('R', window);
				break;
			case Input::AKEY_S:
				setPseudo('S', window);
				break;
			case Input::AKEY_T:
				setPseudo('T', window);
				break;
			case Input::AKEY_U:
				setPseudo('U', window);
				break;
			case Input::AKEY_V:
				setPseudo('V', window);
				break;
			case Input::AKEY_W:
				setPseudo('W', window);
				break;
			case Input::AKEY_X:
				setPseudo('X', window);
				break;
			case Input::AKEY_Y:
				setPseudo('Y', window);
				break;
			case Input::AKEY_Z:
				setPseudo('Z', window);
				break;
			default:
				break;
		}
		Pseudo->setPosition(
			{(window.getSize().x / 2) - (Pseudo->getSize().x / 2), window.getSize().y / 40 * 21});
		return val;
	}

	std::string_view PlayerInfo::getName()
	{
		std::string_view name {rawPseudo_};
		return name;
	}

	void PlayerInfo::display(IWindow &window)
	{
		window.draw(*Wall_);
		window.draw(*Textbox_);
		window.draw(*Message_);
		window.draw(*Pseudo);
	}

	void PlayerInfo::findScore(std::string str)
	{
		int check = 0;

		// NOLINTNEXTLINE
		for (int i = 0; i != ScorePlayer.size(); i++) {
			if (ScorePlayer[i].gameName == str) {
				id_ = i;
				check = 1;
			}
		}
		if (check == 0)
			id_ = -1;
	}

	std::string PlayerInfo::getScore()
	{
		if (id_ == -1)
			return "???";
		return ScorePlayer[id_].playerScore;
	}

	std::string PlayerInfo::getPlayer()
	{
		if (id_ == -1)
			return "???";
		return ScorePlayer[id_].playerName;
	}

	void PlayerInfo::setScoreFile(Player &player, std::string gameName)
	{
		int nb = 0;
		int val = 0;
		int check = 0;
		std::stringstream num;
		Score tabScore;

		// NOLINTNEXTLINE
		for (int i = 0; i != ScorePlayer.size(); i++) {
			num << ScorePlayer[i].playerScore;
			num >> nb;
			if (ScorePlayer[i].gameName == gameName) {
				if (nb < player.score) {
					ScorePlayer[i].playerName = player.name;
					ScorePlayer[i].playerScore = std::to_string(player.score);
				}
				check = 1;
			}
		}
		if (check == 0) {
			tabScore.gameName = gameName;
			tabScore.playerName = player.name;
			tabScore.playerScore = std::to_string(player.score);
			ScorePlayer[ScorePlayer.size()] = tabScore;
		}
	}

	void PlayerInfo::stopTheme()
	{
		Theme_->stop();
	}
} // namespace arcade
