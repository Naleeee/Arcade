/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SDLSound
*/

#include "SDLSound.hpp"

namespace arcade {
	SDLSound::SDLSound(std::string_view filePath)
	{
		sound_.reset(Mix_LoadWAV(filePath.data()));
		if (sound_ == nullptr)
			throw error::GraphicError(Mix_GetError());
		channel_ = -1;
		isStarted_ = false;
		isPlaying_ = false;
		looping_ = false;
		volume_ = MIX_MAX_VOLUME / 2;
	}

	float SDLSound::getVolume() const noexcept
	{
		return MAX_VOLUME * volume_ / MIX_MAX_VOLUME;
	}

	void SDLSound::setVolume(float volume) noexcept
	{
		if (volume > MAX_VOLUME) {
			volume_ = MIX_MAX_VOLUME;
		} else if (volume < 0) {
			volume_ = 0;
		} else {
			volume_ = volume * MIX_MAX_VOLUME / MAX_VOLUME;
		}
		Mix_VolumeChunk(sound_.get(), volume_);
	}

	void SDLSound::setLoop(bool looping) noexcept
	{
		looping_ = looping;
	}

	void SDLSound::play() noexcept
	{
		if (!isStarted_ || isPlaying_) {
			channel_ = Mix_PlayChannel(-1, sound_.get(), -(looping_));
			isStarted_ = true;
		} else {
			Mix_Resume(channel_);
		}
		isPlaying_ = true;
	}

	void SDLSound::pause() noexcept
	{
		if (isPlaying_) {
			Mix_Pause(channel_);
			isPlaying_ = false;
		}
	}

	void SDLSound::stop() noexcept
	{
		Mix_ExpireChannel(channel_, 1);
	}
} // namespace arcade
