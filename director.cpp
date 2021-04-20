#include "director.hpp"
#include "movie.hpp"

Director::Director(string name, string surname) : Actor(name, surname) {};

Movie Director::directMovie() {
	Movie newMovie(this, "");
	addMovie(&newMovie);
	return newMovie;
};
