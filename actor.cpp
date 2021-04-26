#include "actor.hpp"
#include "movie.hpp"
#include "starring.hpp"

Actor::Actor(): _name("Test"), _surname("Testing"), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(string name, string surname):
	_name(name), _surname(surname), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(string firstN, string lastN, gender g, status s, unsigned int age, unsigned int height):
	_name(firstN), _surname(lastN), _age(age), _height(height), _gender(g), _status(s) {}

Actor::Actor(Actor& x): 
	_name(x._name), _surname(x._surname), _age(x._age), _height(x._height), _gender(x._gender), _status(x._status), _movieList(x._movieList){
	//addToStarrings(x);
}

Actor::~Actor() {
	removeFromStarrings();
	_movieList.clear();
}

Actor& Actor::operator=(Actor& x) {
	if (&x == this) {
		return *this;
	}
	removeFromStarrings();
	_movieList.clear();
	_name = x._name;
	_surname = x._surname;
	_age = x._age;
	_height=x._height;
	_gender = x._gender;
	_status = x._status;
	_movieList = x._movieList;
	//addToStarrings(x);
	return *this;
}

string Actor::getName()const {
	return _name;
}

string Actor::getSurname()const {
	return _surname;
}

unsigned int Actor::getAge() const {
	return _age;
}

unsigned int Actor::getHeight()const {
	return _height;
}

Actor::status Actor::getStatus()const {
	return _status;
}

Actor::gender Actor::getGender()const {
	return _gender;
}

void Actor::setName(string name) {
	_name = name;
}

void Actor::setSurname(string surname) {
	_surname = surname;
}

void Actor::setAge(unsigned int age) {
	_age = age;
}

void Actor::setHeight(unsigned int height) {
	_height = height;
}

void Actor::setStatus(status status) {
	_status = status;
}

void Actor::setGender(gender gender) {
	_gender = gender;
}

void Actor::setPersonalData(string name, string surname, gender gender, status status,
	unsigned int age, unsigned int height) {
	_name = name;
	_surname = surname;
	_age = age;
	_height = height;
	_status = status;
	_gender = gender;
}

vector<Movie*> Actor::getMovieList() const {
	return _movieList;
}

void Actor::setMovieList(vector<Movie*> ml) {
	_movieList = ml;
}

void Actor::addMovie(Movie* x) {
	_movieList.push_back(x);
}

void Actor::removeMovie(Movie* x) {
	int place = findMovie(x);
	if (place != -1) {
		_movieList[place] = _movieList.back();
		_movieList.pop_back();
	}
	else {
		cerr << "Actor::removeMovie error: Movie (" << x->getTitle() << " vs " << *_movieList.front() << " does not exist on the list (" << this->getSurname() << ")" << endl;
	}
}

int Actor::findMovie(const Movie* x) const {
	for (unsigned int i = 0; i < _movieList.size(); ++i) {
		if (_movieList[i] == x) return i;
	}
	return -1;
}

void Actor::printMovieList() const {
	for (unsigned int i = 0; i < _movieList.size(); ++i) {
		cout << "- " << *_movieList[i] << endl;//" and its address: " << _movieList[i] << endl;
		//cout << " *** Full data of this^ movie: " << endl; _movieList[i]->printFullData();
	}
}

void Actor::printFullName() const {
	cout << *this << endl;
}

void Actor::printFullData() const {
	cout << *this << endl;
	cout << _age << endl;
	cout << _height << endl;
	switch (_status) {
	case status::amateur:
		cout << "amateur" << endl;
		break;
	case status::student:
		cout << "student" << endl;
		break;
	case status::professional:
		cout << "professional" << endl;
		break;
	case status::director:
		cout << "director" << endl;
		break;
	default: cout << "test" << endl;
	}
	switch (_gender) {
	case gender::FEMALE:
		cout << "FEMALE" << endl;
		break;
	case gender::MALE:
		cout << "MALE" << endl;
		break;
	case gender::NONBINARY:
		cout << "NONBINARY" << endl;
		break;
	default: cout << "TEST" << endl;
	}
}

void Actor::addToStarrings(Actor& x){
}

void Actor::removeFromStarrings(){
	for (unsigned int i = 0; i < _movieList.size(); ++i) {
		while (_movieList[i]->findActor(*this) != -1) {
			_movieList[i]->removeActor(*this);
		}
	}
}

ostream& operator<<(ostream& out, const Actor& actor) { // only for full name
	out << actor.getName() << " " << actor.getSurname();
	return out;
}
