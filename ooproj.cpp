#include "actor.hpp"
#include "starring.hpp"
#include "movie.hpp"
#include "director.hpp"
#include <iostream>

using namespace std;

int main() {
	Actor clooners("George", "Clooney");
	clooners.printFullData();

	Actor bojack("Bojack", "Horseman", Actor::gender::MALE, Actor::status::professional, 49, 190);
	bojack.printFullData();

	Director scorsese("Martin", "Scorsese");

	Movie frantic(&scorsese, "Frantic");
	Starring bh(&bojack, &frantic, 10000);
	frantic.setReleaseDate(releaseDate(10, 4, 2022));
	frantic.printFullData();

	Movie amelie(frantic);
	Starring gc(&clooners, &amelie, 20000);
	amelie.setReleaseDate(releaseDate(12, 12, 2025));
	amelie.setTitle("Amelie");
	amelie.printFullData();

	Movie cchristi = amelie;
	cchristi.setReleaseDate(releaseDate(31, 10, 0000));
	cchristi.setTitle("Corpus Christi");
	cchristi.printFullData();

	frantic.printFullData();
	frantic.removeFilmCast();
	frantic.printFullData();

	//actor should not have ability to change the movie

	cout << "Printing movie list of director: " << endl;
	scorsese.printMovieList();
}