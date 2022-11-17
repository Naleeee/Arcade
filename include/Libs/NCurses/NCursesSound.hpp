/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NCursesSound
*/

#ifndef NCURSESSOUND_HPP_
#define NCURSESSOUND_HPP_

#include "IGraphicFactory.hpp"

#include <memory>
#include <ncurses.h>
#include <string_view>

namespace arcade {
	class NCursesSound : public ISound {
		friend class NCursesWindow;

	public:
		// CTOR / DTOR
		NCursesSound() = delete;
		explicit NCursesSound(__attribute__((unused)) std::string_view filePath);
		NCursesSound(NCursesSound const &other) = delete;
		NCursesSound(NCursesSound &&other) = delete;
		~NCursesSound() noexcept final = default;
		NCursesSound &operator=(NCursesSound const &other) = delete;
		NCursesSound &operator=(NCursesSound &&other) = delete;

		// GETTERS
		float getVolume() const noexcept override;

		// SETTERS
		void setVolume(float volume) noexcept override;
		void setLoop(__attribute__((unused)) bool looping) noexcept;

		// FUNCTIONS
		void play() noexcept override;
		void pause() noexcept override;
		void stop() noexcept override;

	private:
		float volume_;
	};
} // namespace arcade

#endif /* !NCURSESSOUND_HPP_ */
