/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#include "Menu.hpp"

#include "Player.hpp"

namespace arcade {

	// CTOR / DTOR
	Menu::Menu(IGraphicFactory &FGraphic, IWindow &window, PlayerInfo &infoPlayer)
	{
		BestPlayer_ = FGraphic.createText("assets/Menu/Arcade.ttf");
		BestPlayer_->setPosition(
			FVector {window.getSize().x / 40 * 14, window.getSize().y / 20 * 2});
		BestPlayer_->setColor(Color {64, 192, 220, 255});

		Score_ = FGraphic.createText("assets/Menu/Arcade.ttf");
		Score_->setPosition(FVector {window.getSize().x / 40 * 21, window.getSize().y / 20 * 2});
		Score_->setColor(Color {64, 192, 220, 255});

		Jukebox_ = FGraphic.createText("assets/Menu/Arcade.ttf");
		Jukebox_->setText("JUKEBOX: PRESS J");
		Jukebox_->setPosition(FVector {window.getSize().x / 40 * 8, window.getSize().y / 20 * 15});
		Jukebox_->setColor(Color {64, 192, 220, 255});

		Wall_ = FGraphic.createImage("assets/Menu/Wallpaper.png");
		Wall_->fitSize(FVector {window.getSize().x / 1920 * 1200, window.getSize().y / 1010 * 720});
		Wall_->setPosition(
			FVector {(window.getSize().x - Wall_->getSize().x) / 2,
					 (window.getSize().y - (Wall_->getSize().y + (Wall_->getSize().y / 7))) / 2});
		Selection_ = FGraphic.createImage("assets/Menu/Selection.png");
		Selection_->fitSize(
			FVector {window.getSize().x / 1920 * 400, window.getSize().y / 1010 * 720});
		Selection_->setPosition(FVector {(Wall_->getSize().x - (Selection_->getSize().x / 10)),
										 Wall_->getPosition().y});

		Title_ = FGraphic.createImage("assets/Menu/Title.png");
		Title_->fitSize(FVector {window.getSize().x / 1920 * 270, window.getSize().y / 1010 * 240});
		Title_->setPosition(
			FVector {static_cast<float>(Wall_->getPosition().x * 1.05), (Wall_->getPosition().y)});

		Button_ = FGraphic.createSound("sound/effects/Menu/Button.wav");

		getAllGamesFromPath("./lib/game/", FGraphic, window);
		getAllGraphicsFromPath("./lib/graphic/", FGraphic, window);
		infoPlayer.findScore(Games_[idGame_]->getText());
		Score_->setText(infoPlayer.getScore());
		BestPlayer_->setText(infoPlayer.getPlayer());
	}

	// GETTERS
	void Menu::getAllGamesFromPath(const char *path, IGraphicFactory &FGraphic, IWindow &window)
	{
		DIR *dir = nullptr;
		struct dirent *ent = nullptr;
		float size = 1;
		size_t pos_start = 0;
		size_t pos_end = 0;
		std::string lib = "lib/game/";

		if ((dir = opendir(path)) != nullptr) {
			while ((ent = readdir(dir)) != nullptr) {
				if (!std::string(ent->d_name).find_first_of("arcade")) {
					lib = "lib/game/";
					pos_start = std::string(ent->d_name).find_first_of('_');
					pos_end = std::string(ent->d_name).find_first_of('.');

					Games_.emplace_back(std::move(FGraphic.createText("assets/Menu/Arcade.ttf")));
					Games_.back()->setText(
						std::string(ent->d_name).substr(pos_start + 1, pos_end - pos_start - 1));
					Games_.back()->fitSize(FVector {120, Wall_->getSize().y});
					Games_.back()->setPosition(
						FVector {(Wall_->getSize().x / 25 * 27) - (Selection_->getSize().x / 4),
								 (Selection_->getSize().y / 6) * size});
					if (nbGames_ == 0)
						Games_.back()->setColor(Color {64, 192, 220, 255});
					else
						Games_.back()->setColor(Color {255, 255, 255, 255});

					lib += std::string(ent->d_name);
					tagGames_.emplace_back(lib.data());
					size++;
					nbGames_++;
				}
			}
			closedir(dir);
		} else {
			perror("");
		}
	}

	void Menu::getAllGraphicsFromPath(const char *path, IGraphicFactory &FGraphic, IWindow &window)
	{
		DIR *dir = nullptr;
		struct dirent *ent = nullptr;
		float size = 1;
		size_t pos_start = 0;
		size_t pos_end = 0;
		std::string lib = "lib/graphics/";

		if ((dir = opendir(path)) != nullptr) {
			while ((ent = readdir(dir)) != nullptr) {
				if (!std::string(ent->d_name).find_first_of("arcade")) {
					lib = "lib/graphic/";
					pos_start = std::string(ent->d_name).find_first_of('_');
					pos_end = std::string(ent->d_name).find_first_of('.');

					Graphics_.emplace_back(
						std::move(FGraphic.createText("assets/Menu/Arcade.ttf")));
					Graphics_.back()->setText(
						std::string(ent->d_name).substr(pos_start + 1, pos_end - pos_start - 1));
					Graphics_.back()->fitSize(FVector {120, Wall_->getSize().y});
					Graphics_.back()->setPosition(FVector {
						((Wall_->getSize().x / 25 * 35) - (Selection_->getSize().x / 4 * 3)),
						(Selection_->getSize().y / 6) * size});
					Graphics_.back()->setColor(Color {255, 255, 255, 255});

					lib += std::string(ent->d_name);
					tagGraphics_.emplace_back(lib.data());
					size++;
					nbGraphics_++;
				}
			}
			closedir(dir);
		} else {
			perror("");
		}
	}

	std::string Menu::getTagGame() const
	{
		return tagGames_[idGame_];
	}

	std::string Menu::getTagGraphic() const
	{
		return tagGraphics_[idGraphic_];
	}

	// FUNCTIONS
	int Menu::tryEvent(IWindow &window, bool *End, PlayerInfo &infoPlayer)
	{
		Input input = window.getInput();

		switch (input) {
			case Input::AEVENT_STOP:
				Button_->play();
				*End = true;
				break;
			case Input::AKEY_ESC:
				Button_->play();
				*End = true;
				break;
			case Input::AKEY_ENTER:
				Button_->play();
				if (focusGame_) {
					return 2;
				} else if (!focusGame_) {
					return 1;
				}
				break;
			case Input::AKEY_J:
				Button_->play();
				return 3;
				break;
			case Input::AKEY_UP:
				Button_->play();
				if (focusGame_ && nbGames_ > 1) {
					Games_[idGame_]->setColor(Color {255, 255, 255, 255});
					if (idGame_ == 0)
						idGame_ = nbGames_ - 1;
					else
						idGame_--;
					Games_[idGame_]->setColor(Color {64, 192, 220, 255});
					infoPlayer.findScore(Games_[idGame_]->getText());
					Score_->setText(infoPlayer.getScore());
					BestPlayer_->setText(infoPlayer.getPlayer());
				} else if (!focusGame_ && nbGraphics_ > 1) {
					Graphics_[idGraphic_]->setColor(Color {255, 255, 255, 255});
					if (idGraphic_ == 0)
						idGraphic_ = nbGraphics_ - 1;
					else
						idGraphic_--;
					Graphics_[idGraphic_]->setColor(Color {64, 192, 220, 255});
				}
				break;
			case Input::AKEY_DOWN:
				Button_->play();
				if (focusGame_ && nbGames_ > 1) {
					Games_[idGame_]->setColor(Color {255, 255, 255, 255});
					if (idGame_ == nbGames_ - 1)
						idGame_ = 0;
					else
						idGame_++;
					Games_[idGame_]->setColor(Color {64, 192, 220, 255});
					infoPlayer.findScore(Games_[idGame_]->getText());
					Score_->setText(infoPlayer.getScore());
					BestPlayer_->setText(infoPlayer.getPlayer());
				} else if (!focusGame_ && nbGraphics_ > 1) {
					Graphics_[idGraphic_]->setColor(Color {255, 255, 255, 255});
					if (idGraphic_ == nbGraphics_ - 1)
						idGraphic_ = 0;
					else
						idGraphic_++;
					Graphics_[idGraphic_]->setColor(Color {64, 192, 220, 255});
				}
				break;
			case Input::AKEY_LEFT:
				Button_->play();
				if (focusGame_ && nbGraphics_ > 1) {
					Games_[idGame_]->setColor(Color {255, 255, 255, 255});
					focusGame_ = false;
					Graphics_[idGraphic_]->setColor(Color {64, 192, 220, 255});
				} else if (!focusGame_ && nbGames_ > 1) {
					Graphics_[idGraphic_]->setColor(Color {255, 255, 255, 255});
					focusGame_ = true;
					Games_[idGame_]->setColor(Color {64, 192, 220, 255});
				}
				break;

			case Input::AKEY_RIGHT:
				Button_->play();
				if (focusGame_ && nbGraphics_ > 1) {
					Games_[idGame_]->setColor(Color {255, 255, 255, 255});
					focusGame_ = false;
					Graphics_[idGraphic_]->setColor(Color {64, 192, 220, 255});
				} else if (!focusGame_ && nbGames_ > 1) {
					Graphics_[idGraphic_]->setColor(Color {255, 255, 255, 255});
					focusGame_ = true;
					Games_[idGame_]->setColor(Color {64, 192, 220, 255});
				}
				break;
			default:
				break;
		}
		return 0;
	}

	void Menu::display(IWindow &window)
	{
		window.draw(*Wall_);
		window.draw(*Selection_);
		window.draw(*Title_);
		for (auto &Game : Games_) {
			window.draw(*Game);
		}
		for (auto &Graphic : Graphics_) {
			window.draw(*Graphic);
		}
		window.draw(*BestPlayer_);
		window.draw(*Score_);
		window.draw(*Jukebox_);
	}
} // namespace arcade
