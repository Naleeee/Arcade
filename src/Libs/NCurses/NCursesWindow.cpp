/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"

#include "NCursesImage.hpp"
#include "NCursesSound.hpp"
#include "NCursesText.hpp"

#include <iostream>
#include <unistd.h>
#include <unordered_map>

namespace arcade {
	//CONSTRUCTOR & DESTRUCTOR
	NCursesWindow::NCursesWindow(__attribute__((unused)) std::string_view windowName)
	{
		initscr();
		curs_set(false);
		keypad(stdscr, TRUE);
		noecho();
		start_color();
		nodelay(stdscr, TRUE);
		// NOLINTNEXTLINE
		winSize = getSize();
	}

	// NOLINTNEXTLINE
	NCursesWindow::~NCursesWindow()
	{
		endwin();
	}

	//FUNCTIONS
	void NCursesWindow::clear() noexcept
	{
		wclear(stdscr);
	}

	void NCursesWindow::refresh() noexcept
	{
		wrefresh(stdscr);
	}

	void NCursesWindow::draw(IImage &object) noexcept
	{
		auto &child = dynamic_cast<NCursesImage &>(object);
		init_color(child.id_, (child.color_.r * 1000) / 255, (child.color_.g * 1000) / 255,
				   (child.color_.b * 1000) / 255);
		init_pair(child.id_, child.id_, child.id_);
		attron(COLOR_PAIR(child.id_));
		for (int y = 0; y < child.size_.y; y++) {
			mvprintw(child.posyx_.y + y, child.posyx_.x, "%s", child.image_.c_str());
		}
		attroff(COLOR_PAIR(child.id_));
	}

	void NCursesWindow::draw(IText &object) noexcept
	{
		auto &child = dynamic_cast<NCursesText &>(object);
		init_color(child.id_, (child.color_.r * 1000) / 255, (child.color_.g * 1000) / 255,
				   (child.color_.b * 1000) / 255);
		init_pair(child.id_, child.id_, 0);
		attron(A_UNDERLINE);
		attron(A_BOLD);
		attron(COLOR_PAIR(child.id_));
		mvprintw(child.posyx_.y, child.posyx_.x, "%s", child.text_.c_str());
		attroff(COLOR_PAIR(child.id_));
		attroff(A_BOLD);
		attroff(A_UNDERLINE);
	}

	//GETTERS
	FVector NCursesWindow::getSize() const noexcept
	{
		FVector sizeWindow {};

		getmaxyx(stdscr, sizeWindow.y, sizeWindow.x);
		return sizeWindow;
	}

	Input NCursesWindow::getInput() noexcept
	{
		int ch = 0;
		static std::unordered_map<int, Input> NCursesKey({
			{0, Input::AKEY_NULL},		  {-1, Input::AKEY_NULL},
			{'a', Input::AKEY_A},		  {'b', Input::AKEY_B},
			{'c', Input::AKEY_C},		  {'d', Input::AKEY_D},
			{'e', Input::AKEY_E},		  {'f', Input::AKEY_F},
			{'g', Input::AKEY_G},		  {'h', Input::AKEY_H},
			{'i', Input::AKEY_I},		  {'j', Input::AKEY_J},
			{'k', Input::AKEY_K},		  {'l', Input::AKEY_L},
			{'m', Input::AKEY_M},		  {'n', Input::AKEY_N},
			{'o', Input::AKEY_O},		  {'p', Input::AKEY_P},
			{'q', Input::AKEY_Q},		  {'r', Input::AKEY_R},
			{'s', Input::AKEY_S},		  {'t', Input::AKEY_T},
			{'u', Input::AKEY_U},		  {'v', Input::AKEY_V},
			{'w', Input::AKEY_W},		  {'x', Input::AKEY_X},
			{'y', Input::AKEY_Y},		  {'z', Input::AKEY_Z},
			{'[', Input::AKEY_LBRACKET},  {']', Input::AKEY_RBRACKET},
			{';', Input::AKEY_SEMICOLON}, {',', Input::AKEY_COMMA},
			{'.', Input::AKEY_DOT},		  {'\"', Input::AKEY_QUOTE},
			{'/', Input::AKEY_SLASH},	  {'\\', Input::AKEY_BACKSLASH},
			{'~', Input::AKEY_TILDE},	  {'=', Input::AKEY_EQUAL},
			{'-', Input::AKEY_MINUS},	  {'+', Input::AKEY_PLUS},
			{'0', Input::AKEY_NUM0},	  {'1', Input::AKEY_NUM1},
			{'2', Input::AKEY_NUM2},	  {'3', Input::AKEY_NUM3},
			{'4', Input::AKEY_NUM4},	  {'5', Input::AKEY_NUM5},
			{'6', Input::AKEY_NUM6},	  {'7', Input::AKEY_NUM7},
			{'8', Input::AKEY_NUM8},	  {'9', Input::AKEY_NUM9},
			{27, Input::AKEY_ESC},		  {10, Input::AKEY_ENTER},
			{' ', Input::AKEY_SPACE},	  {127, Input::AKEY_BACKSPACE},
			{9, Input::AKEY_TAB},		  {126, Input::AKEY_INSERT},
			{126, Input::AKEY_DELETE},	  {KEY_UP, Input::AKEY_UP},
			{KEY_DOWN, Input::AKEY_DOWN}, {KEY_RIGHT, Input::AKEY_RIGHT},
			{KEY_LEFT, Input::AKEY_LEFT}, {-1, Input::AEVENT_STOP},
		});

		ch = getch();
		if (NCursesKey[ch] == Input::AKEY_ESC) {
			return Input::AEVENT_STOP;
		}
		return NCursesKey[ch];
	}
} // namespace arcade
