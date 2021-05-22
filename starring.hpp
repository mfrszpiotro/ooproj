/**
* Author: Marcel Piotrowski
* Description:  Class Starring is a relation class responsible for connecting
*				Actor object with Movie object using pointers. It can be treated as a Role -
*				it can be "empty", only describing salary and role in a Movie.
*/
#ifndef STARRING_HPP
#define STARRING_HPP
#include "actor.hpp"

class Movie;
class Starring{
public:
	Starring();
	Starring(const std::string&, unsigned int);
	Starring(Movie*, const std::string&, unsigned int); // role to be taken by some actor
	Starring(Actor*, Movie*, const std::string&, unsigned int);
	~Starring();
	Starring(const Starring&);
	Starring operator= (const Starring&);
	bool operator==(const Starring&) const;

	Actor* getActor() const;
	Movie* getMovie() const;
	const std::string& getRole() const;
	unsigned int getSalary() const;

	void link(Actor*);
	void link(Movie*);
	void link(Actor*, Movie*);
	void unlinkActor();
	void unlinkMovie();
	void unlink();
	void setMovie(Movie*);
	void setActor(Actor*);
	void setRole(const std::string&);
	void setSalary(const unsigned int);
	void raiseSalary(const unsigned int);

private:
	Actor* _actor;
	Movie* _movie;
	std::string _role;
	unsigned int _salary;
};

std::ostream& operator<<(std::ostream& out, const Starring& starring);

inline bool Starring::operator==(const Starring& x) const {
	return _role == x._role &&
		_salary == x._salary &&
		_actor == x._actor &&
		_movie == x._movie;
}

inline unsigned int Starring::getSalary()const {
	return _salary;
}

inline void Starring::setMovie(Movie* m) {
	_movie = m;
}

inline void Starring::setActor(Actor* a) {
	_actor = a;
}

inline Actor* Starring::getActor()const {
	return _actor;
}

inline Movie* Starring::getMovie() const {
	return _movie;
}

inline const std::string& Starring::getRole() const {
	return _role;
}

inline void Starring::setSalary(const unsigned int s) {
	_salary = s;
}

inline void Starring::raiseSalary(const unsigned int s) {
	_salary += s;
}

inline void Starring::setRole(const std::string& r) {
	_role = r;
}

#endif
