#ifndef STARRING_HPP
#define STARRING_HPP
#include "actor.hpp"

class Movie;
class Starring{
public:
	Starring();
	Starring(string, unsigned int);
	Starring(Movie*, string, unsigned int); // role to be taken by some actor
	Starring(Actor*, Movie*, string, unsigned int);
	~Starring();
	Starring(const Starring&);
	Starring operator= (const Starring&);
	bool operator==(const Starring&) const;

	Actor* getActor() const;
	Movie* getMovie() const;
	string getRole() const;
	unsigned int getSalary() const;

	void link(Actor*);
	void link(Movie*);
	void link(Actor*, Movie*);
	void unlink(Actor*);
	void unlink(Movie*);
	void unlink(Actor*, Movie*);
	void setMovie(Movie*);
	void setActor(Actor*);
	void setSalary(const unsigned int);
	void setRole(const string);

	void printFullData() const;

private:
	void connectWith(Actor*);
	void connectWith(Movie*);
	void connectWith(Actor*, Movie*);
	void disconnectWith(Actor*);
	void disconnectWith(Movie*);
	void disconnectWith(Actor*, Movie*);

	Actor* _actor;
	Movie* _movie;
	string _role;
	unsigned int _salary;
};

ostream& operator<<(ostream& out, const Starring& starring);

#endif
