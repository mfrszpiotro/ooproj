#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "director.hpp"
#include <iostream>
using namespace std;

struct releaseDate { // to be changed with the chrono library C++20 features
	releaseDate();
	releaseDate(int, int, int);

	unsigned int day;
	unsigned int month;
	unsigned int year;
};

class Director;
class Starring;
class Movie{
public:
	Movie(Director*);
	Movie(Director*, const string&);
	~Movie(); // delete filmcast and remove Starrings from existing actors
	Movie(const Movie&); // copy filmcast and add Starrings to existing actors
					
	string getTitle()const;
	releaseDate getReleaseDate()const;
	vector<Starring> getFilmCast()const;
	string getDirectorName()const;

	void setTitle(const string&);
	void setReleaseDate(const releaseDate&);
	void addStarring(const Starring&);
	void removeStarring(const Starring&);
	int findStarring(const Starring&) const;
	void copyFilmCast(const vector<Starring>&);
	void removeFilmCast();
	int findActor(const Actor&);
	void removeActor(const Actor&);

	void printReleaseDate();
	void printFilmCast();
	void printFullData();
	
private:
	Director* _director;
	string _title;
	releaseDate _dueDate;
	vector<Starring> _filmCast;
								// Some important rules explaining impl. of a class Movie -
	Movie();					// 1. no c-tor:   Movie without director doesn't exist! The default c-tor is set private and cannot be called
	Movie& operator=(Movie&);	// 2. no =op-tor: Movie cannot be assigned to some other film with different director
};

ostream& operator<<(ostream& out, const Movie& x);

#endif

