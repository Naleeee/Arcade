/*
** EPITECH PROJECT, 2022
** core
** File description:
** core
*/

#include "Clock.hpp"

void Clock::savePointTime()
{
	struct timeval now_ {
	};

	if (gettimeofday(&now_, nullptr) == -1) {
		throw error::ArcadeError("ArcadeError: Division by zero");
	}
	clockTime_ = (now_.tv_sec * 1000) + (now_.tv_usec / 1000);
}

bool Clock::getElapsedTime(int timeMilli)
{
	struct timeval now_ {
	};
	time_t timeNow_ = 0;

	if (gettimeofday(&now_, nullptr) == -1) {
		throw error::ArcadeError("ArcadeError: Division by zero");
	}
	timeNow_ = (now_.tv_sec * 1000) + (now_.tv_usec / 1000);
	if (clockTime_ + timeMilli <= timeNow_)
		return true;
	return false;
}
