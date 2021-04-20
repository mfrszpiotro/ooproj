#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "starring.hpp"

struct releaseDate {
	releaseDate();
	releaseDate(int, int, int);

	unsigned int day;
	unsigned int month;
	unsigned int year;
};

struct filmCast {
	filmCast();
	~filmCast();

	Starring actor;
	filmCast* next;
};

class Director;
class Starring;
class Movie{
public:
	Movie(Director*);
	Movie(Director*, const string&);
	Movie(Movie&); // It is possible for director to direct exactly the same film, why not? He can do anything!
	~Movie();

	Movie& operator=(Movie&); // Movie cannot be assigned to some other film with different director
	Movie& operator+(const Starring& x);
	Movie& operator+=(const Starring& x);
	//Movie& operator-(const Starring& x);
	//Movie& operator-=(const Starring& x);

	//getters
	string getTitle()const;
	releaseDate getReleaseDate()const;
	filmCast* getFilmCast()const;
	Director* getDirector()const;
	//modifiers
	void setTitle(const string&);
	void setReleaseDate(const releaseDate&);
	void insertStarring(const Starring& x);
	void removeFilmCast();

	void printReleaseDate();
	void printFilmCast();
	void printFullData();
	
private:
	void copyFilmCast(const Movie&);

	Movie(); // Movie without director doesn't exist! The c-tor is set private and cannot be called
	Director* _director;
	string _title;
	releaseDate _dueDate;
	filmCast* _head;
};

ostream& operator<<(ostream& out, const Movie& x);

#endif

