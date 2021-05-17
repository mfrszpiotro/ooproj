/*
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
	Movie(Director*, const char*);
	~Movie();
	Movie(const Movie&);
					
	std::string getTitle()const;
	tm getReleaseDate()const;
	std::string getDirectorName()const;
	int getSize()const;

	void setTitle(const char*);
	void setReleaseDate(const tm&);

	void insertElement(Starring*);
	bool removeElement(Starring*);
	Starring getNthElement(int);
	bool findElement(const Starring*) const;

	void copyActorStarrings(Actor* _this, Actor* a);
	void removeActorStarrings(Actor*);
	std::vector<Starring*> findActorStarrings(const Actor*)const;

	void printFilmCast();
	
private:
	struct element{
		Starring* data = nullptr;
		element* next = nullptr;
	};
	element* _head;
	int _filmCastSize;
	Director* _director;
	const char* _title;
	tm _releaseDate;

	void copyAllElements(const Movie& src);
	void removeAllElements();

	Movie();					
	Movie& operator=(Movie&);
};

std::ostream& operator<<(std::ostream& out, const Movie& x);

#endif

