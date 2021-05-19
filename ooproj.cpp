#include "actor.hpp"
#include "starring.hpp"
#include "director.hpp"
#include "movie.hpp"
#include <iostream>
using namespace std;

void printReleaseDate(tm&);
void printMovieList(vector<Movie*>);

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
	cout << endl << "State of Actors at the moment: " << endl;
	cout << bielenia << endl;
	printMovieList(bielenia.getMovieList());
	cout << jakubik << endl;
	printMovieList(jakubik.getMovieList());
	cout << kulesza << endl;
	printMovieList(kulesza.getMovieList());

	cout << endl << "Accessing Starrings in copied Movie by MovieList (raising salary of one actor): ";
	vector<Starring*> pBielenia = irishman.findActorStarrings(&bielenia);
	for (unsigned int i = 0; i < pBielenia.size(); ++i) {
		pBielenia[i]->raiseSalary(50000);
	}
	cout << endl << "State of Irishman Movie at the moment: " << endl;
	cout << irishman << endl;
	irishman.printFilmCast();

	cout << endl << "Copy c-tors and assignment operators examples on Godmother Movie:" << endl;
	cout << godmother << endl;
	godmother.printFilmCast();
	Actor zietek(bielenia);
	zietek.setName("Tomasz");
	zietek.setSurname("Zietek");
	zietek.setAge(31);
	vector<Starring*> pZietek = godmother.findActorStarrings(&zietek);
	for (unsigned int i = 0; i < pZietek.size(); ++i) {
		pZietek[i]->setRole("Pablo");
	}
	pZietek = irishman.findActorStarrings(&zietek);
	for (unsigned int i = 0; i < pZietek.size(); ++i) {
		pZietek[i]->setRole("Pablo");
	}
	cout << zietek << endl;
	printMovieList(zietek.getMovieList());

	Actor stenka("Danuta", "Stenka", Actor::gender::FEMALE, Actor::status::professional, 54, 171);
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

	cout << endl << "State of Movies at the moment: " << endl;
	cout << endl << godmother << endl;
	godmother.printFilmCast();
	cout << endl << irishman << endl;
	irishman.printFilmCast();

	cout << endl << "State of Actors at the moment: " << endl;
	cout << endl << bielenia << endl;
	printMovieList(bielenia.getMovieList());
	cout << jakubik << endl;
	printMovieList(jakubik.getMovieList());
	cout << kulesza << endl;
	printMovieList(kulesza.getMovieList());
	cout << zietek << endl;
	printMovieList(zietek.getMovieList());
	cout << stenka << endl;
	printMovieList(stenka.getMovieList());
	
	cout << endl << "Changing name of director: " << endl;
	printMovieList(scorsese.getMovieList());
	scorsese.setPersonalData("Pawel", "Pawlikowski", Actor::gender::MALE, Actor::status::director, 54, 191);
	cout << irishman << endl;
	cout << godmother << endl;

	cout << endl << "Copy c-tor of director: " << endl;
	Director palma(scorsese);
	palma.setPersonalData("Brian", "De Palma", Actor::gender::MALE, Actor::status::director, 76, 180);
	cout << palma << endl;
	printMovieList(palma.getMovieList());

	cout << endl << "It is very convenient to change movie from the Director perspective: " << endl;
	palma.getMovieList()[0]->setTitle("Casino Royale");
	palma.getMovieList()[1]->setTitle("The Room");
	printMovieList(palma.getMovieList());

	cout << endl << "Filmcast of both of the Brian's Palma movies: " << endl;
	cout << *palma.getMovieList()[0] << endl;
	palma.getMovieList()[0]->printFilmCast();
	cout << *palma.getMovieList()[1] << endl;
	palma.getMovieList()[1]->printFilmCast();

	cout << endl << "State of Actors at the moment: " << endl;
	cout << endl << bielenia << endl;
	printMovieList(bielenia.getMovieList());
	cout << jakubik << endl;
	printMovieList(jakubik.getMovieList());
	cout << kulesza << endl;
	printMovieList(kulesza.getMovieList());
	cout << zietek << endl;
	printMovieList(zietek.getMovieList());
	cout << stenka << endl;
	printMovieList(stenka.getMovieList());

	cout << endl << "Assignment operator of director: " << endl;
	Director komasa;
	komasa = palma;
	komasa.setPersonalData("Jan", "Komasa", Actor::gender::MALE, Actor::status::director, 39, 180);
	cout << komasa << endl;
	printMovieList(komasa.getMovieList());

	cout << endl << "One of Actors state at the moment: " << endl;
	cout << stenka << endl;
	printMovieList(stenka.getMovieList());
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