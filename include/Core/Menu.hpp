/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "IGraphicFactory.hpp"
#include "Player.hpp"

#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <vector>

namespace arcade {

	class Menu {
	public:
		// CTOR / DTOR
		Menu() = default;
		Menu(IGraphicFactory &, IWindow &, PlayerInfo &);
		Menu(Menu const &other) = delete;
		Menu(Menu &&other) = delete;
		~Menu() noexcept = default;
		Menu &operator=(Menu const &other) = delete;
		Menu &operator=(Menu &&other) = delete;

		// GETTERS
		void getAllGamesFromPath(const char *, IGraphicFactory &, IWindow &);
		void getAllGraphicsFromPath(const char *, IGraphicFactory &, IWindow &);
		std::string getTagGame() const;
		std::string getTagGraphic() const;

		// FUNCTIONS
		int tryEvent(IWindow &, bool *, PlayerInfo &);
		void display(IWindow &);

	private:
		std::unique_ptr<IImage> Wall_;
		std::unique_ptr<IImage> Selection_;
		std::unique_ptr<IImage> Title_;
		std::unique_ptr<IText> BestPlayer_;
		std::unique_ptr<IText> Score_;
		std::unique_ptr<IText> Jukebox_;
		std::unique_ptr<ISound> Button_ = nullptr;
		bool focusGame_ = true;

		int nbGames_ = 0;
		int idGame_ = 0;
		std::vector<std::unique_ptr<IText>> Games_;
		std::vector<std::string> tagGames_;

		int nbGraphics_ = 0;
		int idGraphic_ = 0;
		std::vector<std::unique_ptr<IText>> Graphics_;
		std::vector<std::string> tagGraphics_;
	};
} // namespace arcade

#endif /* !MENU_HPP */
