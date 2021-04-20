#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP
#include "actor.hpp"

class Director : public Actor{
public:
	Director(string, string);
	Movie directMovie(); // Movie can be created from the point of view of director too
};

#endif
