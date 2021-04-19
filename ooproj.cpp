#include "actor.hpp"
#include "starring.hpp"
#include "movie.hpp"
#include "animation.hpp"
#include <iostream>

using namespace std;

int main() {
	Actor clooners("George", "Clooney");
	clooners.printFullData();

	Actor bojack("Bojack", "Horseman", Actor::gender::MALE, Actor::status::professional, 49, 190);
	bojack.printFullData();

	Movie frantic("Frantic");
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

	Artist docter(Artist::spec::director);
	docter.setPersonalData("Pete", "Docter", Artist::gender::MALE, Artist::status::professional, 38, 198);

	Animation insideOut;
	insideOut += gc;
	insideOut += bh;
	insideOut.addArtist(docter);
	insideOut.printFullData();
	insideOut.printArtList();
}