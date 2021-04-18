#ifndef STARRING_HPP
#define STARRING_HPP
#include "actor.hpp"
using namespace std;

class Starring{
public:
	Starring() : _actor(nullptr), _salary(0) {};
	Starring(Actor* a, unsigned int salary) : _actor(a), _salary(salary) {};

	//getters
	Actor* getActor()const;
	unsigned int getSalary()const;

	//setters
	void setActor(Actor*);
	void setSalary(const unsigned int);

private:
	Actor* _actor;
	//string movieTitle?????
	unsigned int _salary;
};

#endif
