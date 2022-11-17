/*
** EPITECH PROJECT, 2022
** sound
** File description:
** sound
*/

#include "SFMLSound.hpp"

namespace arcade {

	// CTOR / DTOR
	SFMLSound::SFMLSound(std::string_view filepath)
	{
		if (!buffer_.loadFromFile(std::string {filepath}))
			throw error::GraphicError("Couldn't load sound: " + std::string {filepath});
		sound_.setBuffer(buffer_);
	}

	// GETTERS
	float SFMLSound::getVolume() const noexcept
	{
		return sound_.getVolume();
	}

	// SETTERS
	void SFMLSound::setVolume(float volume) noexcept
	{
		sound_.setVolume(volume);
	}

	void SFMLSound::setLoop(bool looping) noexcept
	{
		sound_.setLoop(looping);
	}

	// FUNCTIONS
	void SFMLSound::play() noexcept
	{
		sound_.play();
	}

	void SFMLSound::pause() noexcept
	{
		sound_.pause();
	}

	void SFMLSound::stop() noexcept
	{
		sound_.stop();
	}
} // namespace arcade
