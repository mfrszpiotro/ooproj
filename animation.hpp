#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <iostream>
#include <vector>
#include "movie.hpp"
#include "artist.hpp"
using namespace std;
class Animation : public Movie
{
public:
	Animation() = default;
	Animation(vector<Artist>);
	void addArtist(Artist);
	void copyArtList(vector<Artist>);
	vector<Artist> getArtList() const;

	void printArtList() const;

private:
	vector<Artist> _artList;
};

#endif