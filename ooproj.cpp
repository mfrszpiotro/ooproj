#include "actor.hpp"
#include "starring.hpp"
#include "movie.hpp"
#include "director.hpp"
#include <iostream>

using namespace std;

int main() {
	cout << "Object-oriented programming project - tests:" << endl;
	Actor bielenia("Bartosz", "Bielenia", Actor::gender::MALE, Actor::status::professional, 23, 180);
	Actor jakubik("Arkadiusz", "Jakubik", Actor::gender::MALE, Actor::status::professional, 54, 171);
	Actor kulesza("Agata", "Kulesza", Actor::gender::FEMALE, Actor::status::professional, 54, 171);
	Director scorsese;
	scorsese.setPersonalData("Martin", "Scorsese", Actor::gender::MALE, Actor::status::director, 78, 168);
	Starring ace("Ace", 300000);
	Starring tommy("Tommy", 250000);
	Starring janet("Janet", 320000);
	Movie casino(&scorsese, "Casino");
	tm due;
	due.tm_mday = 1;
	due.tm_mon = 12;
	due.tm_year = 1995;
	casino.setReleaseDate(due);

	cout << endl << "Initial set of objects: " << endl;
	bielenia.printFullName(); cout << endl;
	jakubik.printFullName(); cout << endl;
	kulesza.printFullName(); cout << endl;
	scorsese.printFullName(); cout << endl;
	ace.printFullData();
	tommy.printFullData();
	janet.printFullData();
	casino.printFullData();

	cout << endl << "Directing a Movie with all of above objects: " << endl;
	ace.link(&casino);
	tommy.link(&casino);
	janet.link(&casino);
	ace.link(&bielenia);
	tommy.link(&jakubik);
	janet.link(&kulesza);
	ace.printFullData();
	tommy.printFullData();
	janet.printFullData();
	casino.printFullData();

	cout << endl << "Copying this Movie and changing its characteristics: " << endl;
	Movie irishman(casino);
	irishman.setTitle("Irishman");
	due.tm_mday = 31;
	due.tm_mon = 12;
	due.tm_year = 2019;
	irishman.setReleaseDate(due);
	irishman.printFullData();
	bielenia.printMovieList();
	jakubik.printMovieList();
	kulesza.printMovieList(); //testing to be continued
}