#include "movie.hpp"

Movie::Movie() : _title("No title assigned!!!"), _dueDate(releaseDate()), _head(nullptr) {}

Movie::Movie(const string& title) : _title(title), _dueDate(releaseDate()), _head(nullptr) {}

Movie::Movie(const Movie& src) : _title(src._title), _dueDate(src._dueDate), _head(nullptr) {
	copyFilmCast(src);
}

Movie::~Movie() {
	removeFilmCast();
}

Movie& Movie::operator=(const Movie& src){
	if (this == &src) {
		return *this;
	}
	removeFilmCast();
	copyFilmCast(src);
	return *this;
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
	cout << "Title: " << _title << endl;
	cout << "Release date: "; printReleaseDate(); cout << endl;
	cout << "Film cast: " << endl; printFilmCast();
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

void Movie::setTitle(const string& x){
	_title = x;
}

void Movie::setReleaseDate(const releaseDate& x){
	_dueDate = x;
}