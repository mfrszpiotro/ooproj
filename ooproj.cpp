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

	cout << endl << "Initial set of objects: " << endl;
	bielenia.printFullName(); cout << endl;
	jakubik.printFullName(); cout << endl;
	kulesza.printFullName(); cout << endl;
	scorsese.printFullName(); cout << endl;

	cout << endl << "Creating a Movie with all of above objects: " << endl;
	Movie casino(&scorsese, "Casino");
	tm due;
	due.tm_mday = 1;
	due.tm_mon = 12;
	due.tm_year = 1995;
	casino.setReleaseDate(due);
	Starring ace(&bielenia, &casino, "Ace", 300000);
	ace.printFullData();
	casino.printFullData();
}