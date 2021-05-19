/**
* Author: Marcel Piotrowski
* Description:  Class Movie represents the real movie with its director and actors pointers in it.
*				It cannot exist without its Director and we cannot change the Director of existing
*				Movie (in that case, we should create a new movie). Movies keep all actors starring
*				in this object using pointers to Starring objects.
*/
#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "director.hpp"
#include "starring.hpp"

class Director;
class Starring;
class Movie{
public:
	Movie(Director*);
	Movie(Director*, std::string);
	~Movie();
	Movie(const Movie&);
					
	std::string getTitle()const;
	tm getReleaseDate()const;
	std::string getDirectorName()const;
	unsigned int getSize()const;
	std::vector<Starring*> getFilmCast()const;

	void setTitle(const char*);
	void setReleaseDate(const tm&);

	void insertElement(Starring*);
	bool removeElement(Starring*);
	Starring getNthElement(int);
	bool findElement(const Starring*) const;

	void copyActorStarrings(Actor* _this, Actor* a);
	void removeActorStarrings(Actor*);
	std::vector<Starring*> findActorStarrings(const Actor*)const;

	void copyAllElements(const Movie& src);
	void removeAllElements();
private:
	Director* _director;
	std::string _title;
	tm _releaseDate;
	std::vector<Starring*> _filmCast;

	Movie();					
	Movie& operator=(Movie&);
};

std::ostream& operator<<(std::ostream& out, const Movie& x);

#endif

