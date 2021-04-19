#ifndef ARTIST_HPP
#define ARTIST_HPP
#include <iostream>
#include <list>
#include "actor.hpp"
using namespace std;
class Artist : public Actor
{
public:
	enum class spec { director, artist2D, artist3D, rigging, VFX, test };
	Artist();
	Artist(spec);
	void setSpec(spec);
	spec getSpec() const;

private:
	spec _specialization;
};

#endif

