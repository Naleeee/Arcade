/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLSound
*/

#ifndef SDLSOUND_HPP_
#define SDLSOUND_HPP_

#include "GraphicError.hpp"
#include "IGraphicFactory.hpp"
#include "SDLDeleters.hpp"

#include <SDL2/SDL_mixer.h>

#define MAX_VOLUME 100

namespace arcade {
	class SDLSound : public ISound {
		friend class SDLWindow;

	public:
		// CTOR / DTOR
		SDLSound() = delete;
		SDLSound(std::string_view filePath);
		SDLSound(SDLSound const &other) = delete;
		SDLSound(SDLSound &&other) = delete;
		~SDLSound() noexcept = default;
		SDLSound &operator=(SDLSound const &other) = delete;
		SDLSound &operator=(SDLSound &&other) = delete;

		// GETTERS
		float getVolume() const noexcept final;

		// SETTERS
		void setVolume(float volume) noexcept final;
		void setLoop(bool looping) noexcept final;

		// FUNCTIONS
		void play() noexcept final;
		void pause() noexcept final;
		void stop() noexcept final;

	private:
		SDLSoundPtr sound_;
		int channel_;
		bool isStarted_;
		bool isPlaying_;
		bool looping_;
		float volume_;
	};
} // namespace arcade

#endif /* !SDLSOUND_HPP_ */
