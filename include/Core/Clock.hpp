/*
** EPITECH PROJECT, 2022
** clock
** File description:
** clock
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "ArcadeError.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/time.h>

class Clock {
public:
	// CTOR / DTOR
	Clock() = default;
	Clock(Clock const &other) = delete;
	Clock(Clock &&other) = delete;
	virtual ~Clock() noexcept = default;
	Clock &operator=(Clock const &other) = delete;
	Clock &operator=(Clock &&other) = delete;

	void savePointTime();
	bool getElapsedTime(int timeMilli);

private:
	time_t clockTime_;
};

#endif /* !CLOCK_HPP */
