/**
* Author: Marcel Piotrowski
* Description:  Class Actor is an object representing real movie actor. It keeps track
*				of its movieList (it have pointers to its movies).
*/
#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <vector>
#include <ctime>
#include <iostream>

class Movie;
class Actor{
public:
	enum class status { director = 'd', professional = 'p', amateur = 'a', student = 's', test = 0 };
	enum class gender { MALE = 'M', FEMALE = 'F', NONBINARY = 'N', TEST = 0 };

	Actor();
	Actor(const char*, const char*);
	Actor(const char*, const char*, gender, status, unsigned int, unsigned int);
	Actor(Actor&);
	~Actor();
	Actor& operator=(Actor&);
	bool operator==(const Actor&) const;
	bool operator!=(const Actor&) const;
	
	std::string getName()const;
	std::string getSurname()const;
	unsigned int getAge()const;
	unsigned int getHeight()const;
	status getStatus()const;
	gender getGender()const;
	std::vector<Movie*> getMovieList()const;
	
	void setName(const char*);
	void setSurname(const char*);
	void setAge(unsigned int);
	void setHeight(unsigned int);
	void setStatus(status);
	void setGender(gender);
	void setPersonalData(const char*, const char*, gender, status, unsigned int, unsigned int);
	void setMovieList(std::vector<Movie*> ml);

	void addMovie(Movie*);
	void removeMovie(Movie*);
	int findMovie(const Movie*) const;

private:
	void connectWithAll(Actor&);
	void disconnectWithAll();

	const char* _name;
	const char* _surname;
	unsigned int _age;
	unsigned int _height;
	status _status;
	gender _gender;
	std::vector<Movie*> _movieList;
};

std::ostream& operator<<(std::ostream& out, const Actor& actor);

#endif
