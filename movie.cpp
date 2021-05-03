#include "movie.hpp"
#include "starring.hpp"

Movie::Movie(Director* dir) : _filmCast(), _director(dir), _title("No title assigned!!!"), _releaseDate(tm()) {}

Movie::Movie(Director* dir, const string& title) : _filmCast(0), _director(dir), _title(title), _releaseDate(tm()) {
	_director->addMovie(this);
	vector<Starring> table;
	_filmCast = table;
}

Movie::~Movie() {
	_director->removeMovie(this);
	removeFilmCast();
}

Movie::Movie(const Movie& src): _director(src._director), _title(src._title), _releaseDate(src._releaseDate) {
	_director->addMovie(this);
	vector<Starring> table;
	_filmCast = table;
	copyFilmCast(src._filmCast);
}

void Movie::removeStarring(const Starring& x){
	int place = findStarring(x);
	if (place != -1) {
		_filmCast[place]; // faulty allocation of memory probably - vector usage
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
	Starring* newStar = new Starring(x.getRole(), x.getSalary());
	cout << "***Printing movie filmcast: " << endl;
	printFilmCast();
	_filmCast.push_back(*newStar);
	_filmCast.back().printFullData();
	if (x.getActor() != nullptr) _filmCast.back().setActor(x.getActor());
	if (x.getMovie() != nullptr) _filmCast.back().setMovie(x.getMovie());
	delete newStar;
}

string Movie::getTitle() const {
	return _title;
}

tm Movie::getReleaseDate() const {
	return _releaseDate;
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

void Movie::setReleaseDate(const tm& x) {
	_releaseDate = x;
}

void Movie::printReleaseDate(){
	if (_releaseDate.tm_mday < 10) cout << "0" << _releaseDate.tm_mday;
	else cout << _releaseDate.tm_mday;
	cout << ".";
	if (_releaseDate.tm_mon < 10) cout << "0" << _releaseDate.tm_mon;
	else cout << _releaseDate.tm_mon;
	cout << ".";
	cout << _releaseDate.tm_year;
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
