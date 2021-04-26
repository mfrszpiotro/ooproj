#include "movie.hpp"
#include "starring.hpp"

releaseDate::releaseDate() : day(0), month(0), year(0) {};

releaseDate::releaseDate(int d, int m, int y) : day(d), month(m), year(y) {};

Movie::Movie(Director* dir) : _director(dir), _title("No title assigned!!!"), _dueDate(releaseDate()) {}

Movie::Movie(Director* dir, const string& title) : _director(dir), _title(title), _dueDate(releaseDate()) {
	_director->addMovie(this);
}

Movie::~Movie() {
	_director->removeMovie(this);
	removeFilmCast();
}

Movie::Movie(const Movie& src): _director(src._director), _title(src._title), _dueDate(src._dueDate) {
	_director->addMovie(this);
	copyFilmCast(src._filmCast);
}

void Movie::removeStarring(const Starring& x){
	int place = findStarring(x);
	if (place != -1) {
		_filmCast[place] = _filmCast.back();
		_filmCast.pop_back();
	}
}

void Movie::removeActor(const Actor& a) {
	int place = findActor(a);
	if (place != -1) {
		_filmCast[place] = _filmCast.back();
		_filmCast.pop_back();
	}
}

void Movie::removeFilmCast(){
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		_filmCast[i].getActor()->removeMovie(this);
	}
	_filmCast.clear();
}

int Movie::findStarring(const Starring& x) const{
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		if (_filmCast[i] == x) return i;
	}
	return -1;
}

int Movie::findActor(const Actor& a){
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		if (_filmCast[i].getActor()==&a) return i;
	}
	return -1;
}

void Movie::addStarring(const Starring& x){
	Starring* newStarring = new Starring;
	_filmCast.push_back(*newStarring);
}

string Movie::getTitle() const {
	return _title;
}

releaseDate Movie::getReleaseDate() const {
	return _dueDate;
}

vector<Starring> Movie::getFilmCast() const {
	return _filmCast;
}

string Movie::getDirectorName() const {
	return (_director->getName() + " " + _director->getSurname());
}

void Movie::setTitle(const string& x) {
	_title = x;
}

void Movie::setReleaseDate(const releaseDate& x) {
	_dueDate = x;
}

void Movie::printReleaseDate(){
	if (_dueDate.day < 10) cout << "0" << _dueDate.day << ".";
	else cout << _dueDate.day << ".";
	if (_dueDate.month < 10) cout << "0" << _dueDate.month << ".";
	else cout << _dueDate.month << ".";
	cout << _dueDate.year;
}

void Movie::printFilmCast(){
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		cout << "- " << _filmCast[i].getActor() << " as " << _filmCast[i].getRole() << endl;
	}
}

void Movie::printFullData(){
	cout << "Directed by: " << _director->getName() << " " << _director->getSurname() << endl;
	cout << "Title: " << _title << endl;
	cout << "Release date: "; printReleaseDate(); cout << endl;
	cout << "Film cast: " << endl; printFilmCast();
}

void Movie::copyFilmCast(const vector<Starring>& x) {
	for (unsigned int i = 0; i < x.size(); ++i) {
		_filmCast.push_back(x[i]);
		_filmCast[i].getActor()->addMovie(this);
	}
}

ostream& operator<<(ostream& out, const Movie& x){ // only title
	out << x.getTitle();
	return out;
}

Movie& Movie::operator=(Movie& src) {
	return *this;
}
