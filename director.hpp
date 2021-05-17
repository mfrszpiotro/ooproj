/*
* Author: Marcel Piotrowski
* Description:  Class Director is a foundation of Movie class. Like an actor, it have movieList,
*				but as a director, the relation with Starring is not used.
*/
#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP
#include "actor.hpp"

class Movie;
class Director : public Actor{
public:
	Director();
	Director(const char*, const char*);
	~Director(); // deletes director, its movies and movies' starrings (last one: modifies movieLists of actors)
	Director(const Director&); // deep copy of director, its movies and movies' starrings (last one: modifies portfolios of existing actors)
	Director& operator=(const Director&); // -||- with deleting director before
};

#endif
