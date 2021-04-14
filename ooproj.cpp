#include "actor.hpp"
#include "starring.hpp"
#include "movie.hpp"
#include <iostream>

using namespace std;

int main() {
	Actor clooners("George", "Clooney");
	clooners.printFullName();
	clooners.printFullData();

	Actor bojack("Bojack", "Horseman", Actor::gender::MALE, Actor::status::professional, 49, 190);
	bojack.printFullName();
	bojack.printFullData();

	Starring bh(&bojack, 10000);
	Starring gc(&clooners, 20000);

	Movie frantic("Frantic");
	frantic.setReleaseDate(releaseDate(10, 4, 2022));
	frantic + bh;
	frantic.printFullData();

	Movie amelie(frantic);
	amelie.setReleaseDate(releaseDate(12, 12, 2025));
	amelie.setTitle("Amelie");
	amelie.printFullData();

	amelie += gc;
	Movie cchristi = amelie;
	cchristi.setReleaseDate(releaseDate(31, 10, 0000));
	cchristi.setTitle("Corpus Christi");
	cchristi.printFullData();

	frantic += gc;
	frantic.printFullData();
	frantic.removeFilmCast();
	frantic.printFullData();
}