#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "director.hpp"
#include "starring.hpp"

class Director;
class Starring;
class Movie{
public:
	Movie(Director*);
	Movie(Director*, const string&);
	~Movie();
	Movie(const Movie&);
					
	string getTitle()const;
	tm getReleaseDate()const;
	string getDirectorName()const;
	int getSize()const;

	void setTitle(const string&);
	void setReleaseDate(const tm&);

	void insertElement(Starring*);
	bool removeElement(Starring*);
	Starring* getNthElement(int);
	bool findElement(const Starring*) const;

	void copyActorStarrings(Actor*);
	void removeActorStarrings(Actor*);
	vector<int> findActorStarrings(const Actor*)const;

	void printReleaseDate();
	void printFilmCast();
	void printFullData();
	
private:
	struct element{
		Starring* data = nullptr;
		element* next = nullptr;
	};
	element* _head;
	int _filmCastSize;
	Director* _director;
	string _title;
	tm _releaseDate;

	void copyAllElements(const Movie& src);
	void removeAllElements();

	Movie();					
	Movie& operator=(Movie&);
};

ostream& operator<<(ostream& out, const Movie& x);

#endif

