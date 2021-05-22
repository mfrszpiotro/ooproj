#include "actor.hpp"
#include "movie.hpp"
using namespace std;

Actor::Actor(): _name("Test"), _surname("Testing"), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(const string& name, const string& surname):
	_movieList(), _name(name), _surname(surname), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(const string& firstN, const string& lastN, gender g, status s, unsigned int age, unsigned int height):
	_movieList(), _name(firstN), _surname(lastN), _age(age), _height(height), _gender(g), _status(s) {}

Actor::Actor(Actor& x): 
	_name(x._name), _surname(x._surname), _age(x._age), _height(x._height), _gender(x._gender), _status(x._status), _movieList(){
	connectWithAll(x);
}

Actor::~Actor() {
	disconnectWithAll();
}

Actor& Actor::operator=(Actor& x) {
	if (&x == this) {
		return *this;
	}
	disconnectWithAll();
	_name = x._name;
	_surname = x._surname;
	_age = x._age;
	_height=x._height;
	_gender = x._gender;
	_status = x._status;
	connectWithAll(x);
	return *this;
}

void Actor::removeMovie(Movie* x) {
	int place = findMovie(x);
	if (place != -1) {
		_movieList[place] = _movieList.back();
		_movieList.pop_back();
	}
}

int Actor::findMovie(const Movie* x) const {
	for (unsigned int i = 0; i < _movieList.size(); ++i) {
		if (_movieList[i] == x) return i;
	}
	return -1;
}

void Actor::connectWithAll(Actor& a){
	unsigned int size = a.getMovieList().size();
	for (unsigned int i = 0; i < size; ++i) {
		Movie* toConnect = a.getMovieList()[i];
		toConnect->copyActorStarrings(this, &a);
	}
}

void Actor::disconnectWithAll(){
	unsigned int size = _movieList.size();
	for (unsigned int i = 0; i < size; ++i) {
		Movie* toDisconnect = _movieList[i];
	}
	_movieList.clear();
}

std::ostream& operator<<(std::ostream& out, const Actor& actor) {
	out << actor.getName() << " " << actor.getSurname();
	return out;
}
