#include "actor.hpp"
#include "movie.hpp"

Actor::Actor(): _name("Test"), _surname("Testing"), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(string name, string surname):
	_movieList(), _name(name), _surname(surname), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(string firstN, string lastN, gender g, status s, unsigned int age, unsigned int height):
	_movieList(), _name(firstN), _surname(lastN), _age(age), _height(height), _gender(g), _status(s) {}

Actor::Actor(Actor& x): 
	_name(x._name), _surname(x._surname), _age(x._age), _height(x._height), _gender(x._gender), _status(x._status), _movieList(x._movieList){
	connectWithAll(x._movieList);
}

Actor::~Actor() {
	disconnectWithAll(_movieList);
}

Actor& Actor::operator=(Actor& x) {
	if (&x == this) {
		return *this;
	}
	disconnectWithAll(_movieList);
	_name = x._name;
	_surname = x._surname;
	_age = x._age;
	_height=x._height;
	_gender = x._gender;
	_status = x._status;
	connectWithAll(x._movieList);
	return *this;
}

bool Actor::operator==(const Actor& x) const {
	if (_name == x._name &&
		_surname == x._surname &&
		_age == x._age &&
		_height == x._height &&
		_status == x._status &&
		_gender == x._gender &&
		_movieList == x._movieList) return true;
	return false;
}

bool Actor::operator!=(const Actor& x) const {
	if (*this == x) return false;
	return true;
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
	connectWith(x);
	_movieList.push_back(x);
}

void Actor::removeMovie(Movie* x) {
	int place = findMovie(x);
	if (place != -1) {
		_movieList[place] = _movieList.back();
		disconnectWith(x);
		_movieList.pop_back();
	}
	else {
		cerr << "Actor::removeMovie error" << endl;
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
		cout << "- " << *_movieList[i] << endl;
	}
}

void Actor::connectWithAll(vector<Movie*> x){
	for (unsigned int i = 0; i < x.size(); ++i) {
		addMovie(x[i]);
	}
}

void Actor::disconnectWithAll(vector<Movie*> x){
	for (unsigned int i = 0; i < x.size(); ++i) {
		removeMovie(x[i]);
	}
}

void Actor::connectWith(Movie* m){
	//find actor and copy its starrings (that means: find all actors)
	//if there is none like this actor in movie m, print message that there is no role for this actor
	m->copyActorStarrings(this);
}

void Actor::disconnectWith(Movie* m){
	//find actor and remove it from its roles (that means: find all actors)
	m->removeActorStarrings(this);
}

void Actor::printFullName() const {
	cout << *this;
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

ostream& operator<<(ostream& out, const Actor& actor) { // only for full name
	out << actor.getName() << " " << actor.getSurname();
	return out;
}
