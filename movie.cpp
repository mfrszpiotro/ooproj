#include "movie.hpp"
#include "director.hpp"
#include <iostream>
using namespace std;

releaseDate::releaseDate() : day(0), month(0), year(0) {};

releaseDate::releaseDate(int d, int m, int y) : day(d), month(m), year(y) {};

filmCast::filmCast() : next(nullptr) {};

filmCast::~filmCast() {
	cout << *actor.getActor() << " is about to be deleted" << endl;
	delete next;
}

Movie::Movie(Director* dir) : _director(dir), _title("No title assigned!!!"), _dueDate(releaseDate()), _head(nullptr) {}

Movie::Movie(Director* dir, const string& title) : _director(dir), _title(title), _dueDate(releaseDate()), _head(nullptr) {
	_director->addMovie(this);
}

Movie::Movie(Movie& src) : _director(src._director), _title(src._title), _dueDate(src._dueDate), _head(nullptr) {
	copyFilmCast(src);
	_director->addMovie(&src);
}

Movie::~Movie() {
	_director->removeMovie(this);
	removeFilmCast();
}

Movie& Movie::operator=(Movie& src){
	if (this == &src) {
		return *this;
	}
	else if (_director == src._director || _director == nullptr) {
		if(_director == src._director) removeFilmCast();
		copyFilmCast(src);
		_director->addMovie(&src);
		return *this;
	}
	else {
		cerr << "Movie::operator= error: you cannot assign a movie to different director. Returning LHS not modified" << endl;
		return *this;
	}
}

Movie& Movie::operator+(const Starring& x){
	insertStarring(x);
	return *this;
}

Movie& Movie::operator+=(const Starring& x){
	return(*this = *this + x);
}

void Movie::removeFilmCast(){
	delete _head;
	_head = nullptr;
}

void Movie::copyFilmCast(const Movie& src){
	filmCast* str = src._head;
	while (str) {
		insertStarring(str->actor);
		str = str->next;
	}
}

void Movie::insertStarring(const Starring& x){
	filmCast* ntr = new filmCast;
	ntr->actor = x;
	ntr->next = _head;
	_head = ntr;
}

void Movie::printReleaseDate(){
	if (_dueDate.day < 10) cout << "0" << _dueDate.day << ".";
	else cout << _dueDate.day << ".";
	if (_dueDate.month < 10) cout << "0" << _dueDate.month << ".";
	else cout << _dueDate.month << ".";
	cout << _dueDate.year;
}

void Movie::printFilmCast(){
	filmCast* etr = _head;
	while (etr) {
		Actor tmp = *etr->actor.getActor();
		cout << "- " << tmp << endl;
		etr = etr->next;
	}
}

void Movie::printFullData(){
	cout << "Directed by: " << _director->getName() << " " << _director->getSurname() << endl;
	cout << "Title: " << _title << endl;
	cout << "Release date: "; printReleaseDate(); cout << endl;
	cout << "Film cast: " << endl; printFilmCast();
	cout << "Address: " << this << endl;
}

string Movie::getTitle() const{
	return _title;
}

releaseDate Movie::getReleaseDate() const{
	return _dueDate;
}

filmCast* Movie::getFilmCast() const{
	return _head;
}

Director* Movie::getDirector() const{
	return _director;
}

void Movie::setTitle(const string& x){
	_title = x;
}

void Movie::setReleaseDate(const releaseDate& x){
	_dueDate = x;
}

ostream& operator<<(ostream& out, const Movie& x){ // only title
	out << x.getTitle();
	return out;
}
