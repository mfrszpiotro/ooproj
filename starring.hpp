/*
* Author: Marcel Piotrowski
* Description:  Class Starring is a relation class responsible for connecting
				Actor object with Movie object using pointers. It can be treated as a Role -
				it can be "empty", only describing salary and role in a Movie.
*/
#ifndef STARRING_HPP
#define STARRING_HPP
#include "actor.hpp"

class Movie;
class Starring{
public:
	Starring();
	Starring(const char*, unsigned int);
	Starring(Movie*, const char*, unsigned int); // role to be taken by some actor
	Starring(Actor*, Movie*, const char*, unsigned int);
	~Starring();
	Starring(const Starring&);
	Starring operator= (const Starring&);
	bool operator==(const Starring&) const;

	Actor* getActor() const;
	Movie* getMovie() const;
	const char* getRole() const;
	unsigned int getSalary() const;

	void link(Actor*);
	void link(Movie*);
	void link(Actor*, Movie*);
	void unlinkActor();
	void unlinkMovie();
	void unlink();
	void setMovie(Movie*);
	void setActor(Actor*);
	void setRole(const char*);
	void setSalary(const unsigned int);
	void raiseSalary(const unsigned int);

private:
	Actor* _actor;
	Movie* _movie;
	const char* _role;
	unsigned int _salary;
};

std::ostream& operator<<(std::ostream& out, const Starring& starring);

#endif
