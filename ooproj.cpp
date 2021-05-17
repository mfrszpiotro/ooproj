#include "actor.hpp"
#include "starring.hpp"
#include "director.hpp"
#include "movie.hpp"
#include <iostream>
using namespace std;

int main() {
	cout << "Object-oriented programming project - tests:" << endl;
	Actor bielenia("Bartosz", "Bielenia", Actor::gender::MALE, Actor::status::professional, 29, 175);
	Actor jakubik("Arkadiusz", "Jakubik", Actor::gender::MALE, Actor::status::professional, 52, 178);
	Actor kulesza("Agata", "Kulesza", Actor::gender::FEMALE, Actor::status::professional, 49, 164);
	Director scorsese;
	scorsese.setPersonalData("Martin", "Scorsese", Actor::gender::MALE, Actor::status::director, 78, 163);
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
	cout << bielenia << endl;
	cout << jakubik << endl;
	cout << kulesza << endl;
	cout << scorsese << endl;
	cout << endl << "Starrings: " << endl;
	cout << ace << endl;
	cout << tommy << endl;
	cout << janet << endl;
	cout << endl << "Movie: " << endl;
	cout << godmother << endl;

	cout << endl << "Directing a Movie with all of above objects: " << endl;
	ace.link(&godmother);
	tommy.link(&godmother);
	janet.link(&godmother);
	ace.link(&bielenia);
	tommy.link(&jakubik);
	janet.link(&kulesza);
	cout << endl << "Linked starrings: " << endl;
	cout << ace << endl;
	cout << tommy << endl;
	cout << janet << endl;
	cout << endl << "Movie with filmcast: " << endl;
	cout << godmother << endl;
	godmother.printFilmCast();

	cout << endl << "Copying this Movie and changing its characteristics: " << endl;
	Movie irishman(godmother);
	irishman.setTitle("Irishman: The Godmother Part II");
	due.tm_mday = 31;
	due.tm_mon = 12;
	due.tm_year = 2019;
	irishman.setReleaseDate(due);
	cout << irishman << endl;
	irishman.printFilmCast();

	cout << endl << "State of Godmother Movie at the moment: " << endl;
	cout << godmother << endl;
	godmother.printFilmCast();
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
	cout << irishman << endl;
	irishman.printFilmCast();

	cout << endl << "Copy c-tors and assignment operators examples on Godmother Movie:" << endl;
	cout << godmother << endl;
	godmother.printFilmCast();
	/*Actor zietek(bielenia);
	zietek.setName("Tomasz");
	zietek.setSurname("Zietek");
	zietek.setAge(31);
	zietek.printFullData();
	zietek.printMovieList();
	godmother.printFullData();*/

	Actor stenka("Danuta", "Stenka", Actor::gender::FEMALE, Actor::status::professional, 54, 171);
	// ^to be changed after testing Actor class
	Starring elle(janet);
	elle.setRole("Elle");
	elle.unlinkActor();
	elle.link(&stenka);
	cout << endl << elle << endl;
	cout << janet << endl;
	cout << godmother << endl;
	godmother.printFilmCast();

	Starring julie("Role", 0);
	julie = janet;
	julie.setRole("Julie");
	julie.setSalary(400000);
	julie.unlinkActor();
	cout << endl << godmother << endl;
	godmother.printFilmCast();
}

void printReleaseDate(tm& date) {
	if (date.tm_mday < 10) std::cout << "0" << date.tm_mday;
	else std::cout << date.tm_mday;
	std::cout << ".";
	if (date.tm_mon < 10) std::cout << "0" << date.tm_mon;
	else std::cout << date.tm_mon;
	std::cout << ".";
	std::cout << date.tm_year;
}

void printMovieList(vector<Movie*> list) {
	for (unsigned int i = 0; i < list.size(); ++i) {
		std::cout << "- " << *list[i] << std::endl;
	}
}