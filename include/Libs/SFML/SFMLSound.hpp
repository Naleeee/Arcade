/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <string_view>

namespace arcade {

	class SFMLSound : public ISound {
		friend class SFMLWindow;

	public:
		// CTOR / DTOR
		SFMLSound() = delete;
		explicit SFMLSound(std::string_view filePath);
		SFMLSound(SFMLSound const &other) = delete;
		SFMLSound(SFMLSound &&other) = delete;
		~SFMLSound() noexcept final = default;
		SFMLSound &operator=(SFMLSound const &other) = delete;
		SFMLSound &operator=(SFMLSound &&other) = delete;

		// GETTERS
		float getVolume() const noexcept override;

		// SETTERS
		void setVolume(float volume) noexcept override;
		void setLoop(bool looping) noexcept;

		// FUNCTIONS
		void play() noexcept override;
		void pause() noexcept override;
		void stop() noexcept override;

	private:
		sf::SoundBuffer buffer_;
		sf::Sound sound_;
	};
} // namespace arcade

#endif /* !SOUND_HPP */
