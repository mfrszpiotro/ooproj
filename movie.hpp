#ifndef MOVIE_HPP
#define MOVIE_HPP
#include <iostream>
#include <list>
#include "starring.hpp"
using namespace std;

struct releaseDate {
	releaseDate() : day(0), month(0), year(0) {};
	releaseDate(int d, int m, int y) : day(d), month(m), year(y) {};

	unsigned int day;
	unsigned int month;
	unsigned int year;
};

struct filmCast {
	filmCast() : next(nullptr) {};
	~filmCast() {
		cout << *actor.getActor() << " is about to be deleted" << endl;
		delete next;
	}

	Starring actor;
	filmCast* next;
};

class Movie{
public:
	Movie(const string&);
	Movie(const Movie&);
	~Movie();

	Movie& operator=(const Movie&);
	Movie& operator+(const Starring& x);
	Movie& operator+=(const Starring& x);

	//getters
	string getTitle()const;
	releaseDate getReleaseDate()const;
	filmCast* getFilmCast()const;
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

	string _title;
	releaseDate _dueDate;
	filmCast* _head;
	//list<Starring> filmCast;
};

#endif

