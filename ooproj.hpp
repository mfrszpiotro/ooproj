/*
* Author: Marcel Piotrowski
* Description:  Driver for testing my project
*/
#ifndef OOPROJ_HPP
#define OOPROJ_HPP
#include "movie.hpp";
#include "actor.hpp";

class Movie;

void printReleaseDate(tm&);
void printMovieList(vector<Movie*>);
//void printFilmCast(vector<Starring*>);

#endif