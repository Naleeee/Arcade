/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesSound
*/

#include "NCursesSound.hpp"

namespace arcade {

	//CONSTRUCTOR & DESTRUCTOR
	NCursesSound::NCursesSound(__attribute__((unused)) std::string_view filepath)
	{
		volume_ = 0;
	}

	//FUNCTIONS
	void NCursesSound::play() noexcept
	{
		return;
	}

	void NCursesSound::pause() noexcept
	{
		return;
	}

	void NCursesSound::stop() noexcept
	{
		return;
	}

	//SETTERS
	void NCursesSound::setVolume(float volume) noexcept
	{
		volume_ = volume;
	}

	void NCursesSound::setLoop(__attribute__((unused)) bool looping) noexcept
	{
		return;
	}

	//GETTERS
	float NCursesSound::getVolume() const noexcept
	{
		return volume_;
	}
} // namespace arcade
