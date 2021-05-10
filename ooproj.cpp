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
	Movie godmother(&scorsese, "The Godmother");
	tm due;
	due.tm_mday = 1;
	due.tm_mon = 12;
	due.tm_year = 1995;
	godmother.setReleaseDate(due);

	cout << endl << "Initial set of objects: " << endl;
	cout << endl << "Actors and director: " << endl;
	bielenia.printFullName(); cout << endl;
	jakubik.printFullName(); cout << endl;
	kulesza.printFullName(); cout << endl;
	scorsese.printFullName(); cout << endl;
	cout << endl << "Starrings: " << endl;
	ace.printFullData();
	tommy.printFullData();
	janet.printFullData();
	cout << endl << "Movie: " << endl;
	godmother.printFullData();

	cout << endl << "Directing a Movie with all of above objects: " << endl;
	ace.link(&godmother);
	tommy.link(&godmother);
	janet.link(&godmother);
	ace.link(&bielenia);
	tommy.link(&jakubik);
	janet.link(&kulesza);
	cout << endl << "Linked starrings: " << endl;
	ace.printFullData();
	tommy.printFullData();
	janet.printFullData();
	cout << endl << "Movie with filmcast: " << endl;
	godmother.printFullData();

	cout << endl << "Copying this Movie and changing its characteristics: " << endl;
	Movie irishman(godmother);
	irishman.setTitle("Irishman: The Godmother Part II");
	due.tm_mday = 31;
	due.tm_mon = 12;
	due.tm_year = 2019;
	irishman.setReleaseDate(due);
	irishman.printFullData();

	cout << endl << "State of Godmother Movie at the moment: " << endl;
	godmother.printFullData();
	cout << endl << "Error if Starrings created at the beginning can be found in Irishman" << endl;
	if (irishman.findElement(&ace) ||
		irishman.findElement(&tommy) ||
		irishman.findElement(&janet))
		cout << "Error" << endl;
	else cout << "Good" << endl;
	cout << endl << "Error if Actors created at the beginning cannot be found in Irishman" << endl;
	if (irishman.findActorStarrings(&bielenia).empty() ||
		irishman.findActorStarrings(&jakubik).empty() ||
		irishman.findActorStarrings(&kulesza).empty())
		cout << "Error" << endl;
	else cout << "Good" << endl;

	cout << endl << "Accessing Starrings in copied Movie by MovieList (raising salary of one actor): ";
	vector<int> pBielenia = irishman.findActorStarrings(&bielenia);
	for (unsigned int i = 0; i < pBielenia.size(); ++i) {
		irishman.getNthElement(pBielenia[i])->raiseSalary(50000);
	}
	cout << endl << "State of Irishman Movie at the moment: " << endl;
	irishman.printFullData();

	cout << endl << "Copy c-tors and assignment operators examples on Godmother Movie:" << endl;
	godmother.printFullData();
	/*Actor zietek(bielenia);
	zietek.setName("Tomasz");
	zietek.setSurname("Zietek");
	zietek.setAge(31);
	zietek.printFullData();
	zietek.printMovieList();
	godmother.printFullData();*/

	Actor stenka("Danuta", "Stenka", Actor::gender::FEMALE, Actor::status::professional, 54, 171);
	Starring elle(janet);
	elle.setRole("Elle");
	elle.unlinkActor();
	elle.link(&stenka);
	elle.printFullData();
	janet.printFullData();
	godmother.printFullData();

	Starring julie("Role", 0);
	julie = janet;
	julie.setRole("Julie");
	julie.setSalary(400000);
	julie.unlinkActor();
	godmother.printFullData();
}