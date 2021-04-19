#ifndef STARRING_HPP
#define STARRING_HPP
#include "actor.hpp"
using namespace std;

class Movie;
class Starring{
public:
	Starring();
	Starring(Actor*, Movie*, unsigned int); // initializes data AND adds starring to filmcast of Movie
	~Starring(); // deletes starring from filmcast

	//getters
	Actor* getActor() const;
	Movie* getMovie() const;
	unsigned int getSalary() const;

	//setters
	void setActor(Actor*);
	void setMovie(Movie*); // sets pointer to movie AND adds starring to filmcast of Movie
	void setSalary(const unsigned int);

	void printFullData() const;

private:
	Actor* _actor;
	Movie* _movie;
	unsigned int _salary;
};

//ostream& operator<<(ostream& out, const Starring& starring);

#endif
