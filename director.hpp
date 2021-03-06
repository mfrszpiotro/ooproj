/**
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

	Director(const std::string&, const std::string&);

 //Deletes director, its movies and movies' starrings (last one: modifies movieLists of actors)
	~Director();

/**
 * Deep copy of director, its movies and movies' starrings (last one: modifies portfolios of existing actors)
 *
 * @param Director reference
 *
 * @return Copy-constructed object
 */
	Director(Director&);

/**
 * Deep copy of director, its movies and movies' starrings (last one: modifies portfolios of existing actors),
 * deletes director before.
 *
 * @param Director reference
 *
 * @return Reference to object after assinging
 */
	Director& operator=(Director&);

private:
	void copyAll(Director&);
	void deleteAll();
};

#endif
