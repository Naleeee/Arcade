/*
** EPITECH PROJECT, 2022
** jukebox
** File description:
** jukebox
*/

#include "Jukebox.hpp"

namespace arcade {

	// CTOR / DTOR
	Jukebox::Jukebox(IWindow &window, IGraphicFactory &graphicFactory)
	{
		background_ = graphicFactory.createImage("assets/Menu/Jukebox.png");
		background_->fitSize(
			FVector {window.getSize().x / 1920 * 1200, window.getSize().y / 1010 * 720});
		background_->setPosition(FVector {
			(window.getSize().x - background_->getSize().x) / 2,
			(window.getSize().y - (background_->getSize().y + (background_->getSize().y / 7))) /
				2});

		getAllMusicsFromPath("./sound/music/", graphicFactory, window);
	}

	// SETTERS
	void Jukebox::getAllMusicsFromPath(const char *path, IGraphicFactory &graphicFactory,
									   IWindow &window)
	{
		DIR *dir = nullptr;
		struct dirent *ent = nullptr;
		float size = 2;
		size_t pos_start = 0;
		size_t pos_end = 0;
		std::string lib = "sound/music/";

		if ((dir = opendir(path)) != nullptr) {
			while ((ent = readdir(dir)) != nullptr) {
				if (!std::string(ent->d_name).find_first_of("arcade")) {
					lib = "sound/music/";
					pos_start = std::string(ent->d_name).find_first_of('_');
					pos_end = std::string(ent->d_name).find_first_of('.');

					Musics_.emplace_back(
						std::move(graphicFactory.createText("assets/Menu/Arcade.ttf")));
					Musics_.back()->setText(
						std::string(ent->d_name).substr(pos_start + 1, pos_end - pos_start - 1));
					Musics_.back()->fitSize(FVector {240, background_->getSize().y});
					Musics_.back()->setPosition(FVector {window.getSize().x / 30 * 13,
														 (background_->getSize().y / 10) * size});
					if (nbMusics_ == 0)
						Musics_.back()->setColor(Color {0, 0, 139, 255});
					else
						Musics_.back()->setColor(Color {255, 255, 255, 255});

					lib += std::string(ent->d_name);
					tagMusics_.emplace_back(lib.data());
					size++;
					nbMusics_++;
				}
			}
			closedir(dir);
		} else {
			perror("");
		}
	}

	std::string Jukebox::getTagMusic() const
	{
		return tagMusics_[idMusic_];
	}

	// FUNCTIONS
	int Jukebox::handleInput(const Input &input, IGraphicFactory &graphicFactory)
	{
		switch (input) {
			case Input::AEVENT_STOP:
				return 0;
				break;
			case Input::AKEY_ESC:
				return 0;
				break;
			case Input::AKEY_ENTER:
				music_.reset(nullptr);
				music_ = graphicFactory.createSound(getTagMusic());
				music_->setVolume(10);
				music_->play();
				break;
			case Input::AKEY_UP:
				Musics_[idMusic_]->setColor(Color {255, 255, 255, 255});
				if (idMusic_ == 0)
					idMusic_ = nbMusics_ - 1;
				else
					idMusic_--;
				Musics_[idMusic_]->setColor(Color {0, 0, 139, 255});
				break;
			case Input::AKEY_DOWN:
				Musics_[idMusic_]->setColor(Color {255, 255, 255, 255});
				if (idMusic_ == nbMusics_ - 1)
					idMusic_ = 0;
				else
					idMusic_++;
				Musics_[idMusic_]->setColor(Color {0, 0, 139, 255});
				break;
			default:
				break;
		}
		return 2;
	}

	void Jukebox::display(IWindow &window)
	{
		window.draw(*background_);
		for (auto &Music : Musics_) {
			window.draw(*Music);
		}
	}

} // namespace arcade