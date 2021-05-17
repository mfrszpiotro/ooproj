#include "actor.hpp"
#include "movie.hpp"
using namespace std;

Actor::Actor(): _name("Test"), _surname("Testing"), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(const char* name, const char* surname):
	_movieList(), _name(name), _surname(surname), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(const char* firstN, const char* lastN, gender g, status s, unsigned int age, unsigned int height):
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
	return	_name == x._name &&
			_surname == x._surname &&
			_age == x._age &&
			_height == x._height &&
			_status == x._status &&
			_gender == x._gender &&
			_movieList == x._movieList;
}

bool Actor::operator!=(const Actor& x) const {
	return !(*this == x);
}

std::string Actor::getName()const {
	return _name;
}

std::string Actor::getSurname()const {
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

void Actor::setName(const char* name) {
	_name = name;
}

void Actor::setSurname(const char* surname) {
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

void Actor::setPersonalData(const char* name, const char* surname, gender gender, status status,
	unsigned int age, unsigned int height) {
	_name = name;
	_surname = surname;
	_age = age;
	_height = height;
	_status = status;
	_gender = gender;
}

std::vector<Movie*> Actor::getMovieList() const {
	return _movieList;
}

void Actor::setMovieList(std::vector<Movie*> ml) {
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
		std::cerr << "Actor::removeMovie error" << std::endl;
	}
}

int Actor::findMovie(const Movie* x) const {
	for (unsigned int i = 0; i < _movieList.size(); ++i) {
		if (_movieList[i] == x) return i;
	}
	return -1;
}

void Actor::connectWithAll(std::vector<Movie*>& ml){
	for (unsigned int i = 0; i < ml.size(); ++i) {
		addMovie(ml[i]);
	}
}

void Actor::disconnectWithAll(std::vector<Movie*>& ml){
	for (unsigned int i = 0; i < ml.size(); ++i) {
		removeMovie(ml[i]);
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

std::ostream& operator<<(std::ostream& out, const Actor& actor) {
	out << actor.getName() << " " << actor.getSurname();
	return out;
}
