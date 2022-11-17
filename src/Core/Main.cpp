/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "Core.hpp"

namespace arcade {
	int launch_arcade(int ac, char **av)
	{
		if (ac != 2) {
			std::cerr << "Invalid Usage." << std::endl
					  << "Usage: ./arcade [Graphic Library]" << std::endl;
			return 84;
		}

		std::unique_ptr<GraphicLoader> LGraphic = nullptr;
		std::unique_ptr<IGraphicFactory> FGraphic = nullptr;
		try {
			LGraphic = std::make_unique<GraphicLoader>(av[1]);
			FGraphic = LGraphic->loadLibrary();
		} catch (error::ArcadeError const &e) {
			std::cerr << "GraphicError: " << e.what() << std::endl;
			return 84;
		}

		try {
			bool End = false;
			int isGame = -1;
			int print = 0;
			size_t pos_start = 0;
			size_t pos_end = 0;
			std::string nameGame;

			std::unique_ptr<IWindow> window = FGraphic->createWindow("Arcade");
			std::unique_ptr<IImage> screen = FGraphic->createImage("assets/screen.png");
			std::unique_ptr<PlayerInfo> infoPlayer =
				std::make_unique<PlayerInfo>(*FGraphic, *window);
			std::unique_ptr<Menu> menu = std::make_unique<Menu>(*FGraphic, *window, *infoPlayer);
			std::unique_ptr<Jukebox> jukebox = std::make_unique<Jukebox>(*window, *FGraphic);
			std::unique_ptr<ISound> theme = FGraphic->createSound("sound/effects/Menu/Menu.wav");

			GameLoader LGame;
			std::unique_ptr<IGameFactory> FGame = nullptr;
			std::unique_ptr<AGame> game = nullptr;

			Clock clockRefresh;
			Clock clockClear;
			clockRefresh.savePointTime();
			clockClear.savePointTime();

			std::unique_ptr<Player> player = std::make_unique<Player>();

			screen->fitSize(FVector {window->getSize().x, window->getSize().y});
			while (End == false) {
				if (clockClear.getElapsedTime(80)) {
					window->clear();
					window->draw(*screen);
					clockClear.savePointTime();
				}
				if (isGame == -1) {
					isGame = infoPlayer->tryEvent(*window, &End);
					if (isGame == 0) {
						theme->play();
						theme->setLoop(true);
					}
					infoPlayer->display(*window);
					player->name = infoPlayer->getName();
				}

				if (isGame == 0) {
					int switchLib = 0;
					switchLib = menu->tryEvent(*window, &End, *infoPlayer);
					if (switchLib == 1) {
						std::string newPath = menu->getTagGraphic();
						theme.reset(nullptr);
						FGame.reset(nullptr);
						game.reset(nullptr);
						infoPlayer.reset(nullptr);
						jukebox.reset(nullptr);
						screen.reset(nullptr);
						menu.reset(nullptr);
						window.reset(nullptr);
						FGraphic.reset(nullptr);
						LGraphic.reset(nullptr);
						LGraphic = std::make_unique<GraphicLoader>(newPath.c_str());
						FGraphic = LGraphic->loadLibrary();
						window = FGraphic->createWindow("Arcade");
						screen = FGraphic->createImage("assets/screen.png");
						infoPlayer = std::make_unique<PlayerInfo>(*FGraphic, *window);
						infoPlayer->stopTheme();
						menu = std::make_unique<Menu>(*FGraphic, *window, *infoPlayer);
						screen->fitSize(FVector {window->getSize().x, window->getSize().y});
						jukebox = std::make_unique<Jukebox>(*window, *FGraphic);
						theme = FGraphic->createSound("sound/effects/Menu/Menu.wav");
						theme->play();
						theme->setLoop(true);
					}
					if (switchLib == 2) {
						isGame = 1;
						LGame.openLibrary(std::string(menu->getTagGame()));
						FGame = LGame.loadLibrary();
						game = FGame->createGame(*player, *window, *FGraphic);
					}
					if (switchLib == 3) {
						isGame = 2;
					}
					menu->display(*window);
				}
				if (isGame == 1) {
					isGame = game->handleInput(window->getInput());
					if (isGame == false) { }
					game->refresh();
					print = 1;
				} else if (print == 1) {
					pos_start = menu->getTagGame().find_first_of('_');
					pos_end = menu->getTagGame().find_first_of('.');
					nameGame = menu->getTagGame().substr(pos_start + 1, pos_end - pos_start - 1);
					infoPlayer->setScoreFile(*player, nameGame);
					player->score = 0;
					print = 0;
				}
				if (isGame == 2) {
					isGame = jukebox->handleInput(window->getInput(), *FGraphic);
					if (isGame == 0) {
						theme->stop();
					}
					jukebox->display(*window);
				}
				if (clockRefresh.getElapsedTime(5)) {
					window->refresh();
					clockRefresh.savePointTime();
				}
			}
		} catch (error::GraphicError const &e) {
			std::cerr << "GraphicError: " << e.what() << std::endl;
			return 84;
		} catch (error::GameError const &e) {
			std::cerr << "GameError: " << e.what() << std::endl;
			return 84;
		} catch (error::ArcadeError const &e) {
			std::cerr << "ArcadeError: " << e.what() << std::endl;
			return 84;
		}
		return 0;
	}
} // namespace arcade

int main(int ac, char **av)
{
	return arcade::launch_arcade(ac, av);
}