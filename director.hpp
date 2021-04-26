#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP
#include "actor.hpp"

class Movie;
class Director : public Actor{
public:
	Director();
	Director(string, string);
	~Director(); // deletes director, its movies and movies' starrings (last one: modifies movieLists of actors)
	Director(const Director&); // deep copy of director, its movies and movies' starrings (last one: modifies portfolios of existing actors)
	Director& operator=(const Director&); // -||- with deleting director before
};

#endif
