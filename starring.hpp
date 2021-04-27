#ifndef STARRING_HPP
#define STARRING_HPP
#include "actor.hpp"
#include "movie.hpp"
using namespace std;

class Movie;
class Starring{
public:
	Starring();
	Starring(string, unsigned int);
	Starring(Movie*, string, unsigned int); // role to be taken by some actor
	Starring(Actor*, Movie*, string, unsigned int);
	~Starring();
	Starring(const Starring&);
	Starring operator= (Starring&);
	bool operator==(const Starring&) const;

	Actor* getActor() const;
	Movie* getMovie() const;
	string getRole() const;
	unsigned int getSalary() const;

	void setActor(Actor*);
	void setMovie(Movie*);
	void setSalary(const unsigned int);
	void setRole(const string);

	void printFullData() const;

private:
	Actor* _actor;
	Movie* _movie;
	string _role;
	unsigned int _salary;
};

ostream& operator<<(ostream& out, const Starring& starring);

#endif
