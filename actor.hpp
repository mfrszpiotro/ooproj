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
	Actor(const std::string&, const std::string&);
	Actor(const std::string&, const std::string&, gender, status, unsigned int, unsigned int);
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
	
	void setName(const std::string&);
	void setSurname(const std::string&);
	void setAge(unsigned int);
	void setHeight(unsigned int);
	void setStatus(status);
	void setGender(gender);
	void setPersonalData(const std::string&, const std::string&, gender, status, unsigned int, unsigned int);
	void setMovieList(std::vector<Movie*> ml);

	void addMovie(Movie*);
	void removeMovie(Movie*);
	int findMovie(const Movie*) const;

private:
	void connectWithAll(Actor&);
	void disconnectWithAll();

	std::string _name;
	std::string _surname;
	unsigned int _age;
	unsigned int _height;
	status _status;
	gender _gender;
	std::vector<Movie*> _movieList;
};

std::ostream& operator<<(std::ostream& out, const Actor& actor);

inline bool Actor::operator==(const Actor& x) const {
	return	_name == x._name &&
		_surname == x._surname &&
		_age == x._age &&
		_height == x._height &&
		_status == x._status &&
		_gender == x._gender &&
		_movieList == x._movieList;
}

inline bool Actor::operator!=(const Actor& x) const {
	return !(*this == x);
}

inline void Actor::setPersonalData(const std::string& name, const std::string& surname, gender gender, status status,
	unsigned int age, unsigned int height) {
	_name = name;
	_surname = surname;
	_age = age;
	_height = height;
	_status = status;
	_gender = gender;
}

inline std::vector<Movie*> Actor::getMovieList() const {
	return _movieList;
}

inline void Actor::setMovieList(std::vector<Movie*> ml) {
	_movieList = ml;
}

inline void Actor::addMovie(Movie* x) {
	_movieList.push_back(x);
}

inline std::string Actor::getName()const {
	return _name;
}

inline std::string Actor::getSurname()const {
	return _surname;
}

inline unsigned int Actor::getAge() const {
	return _age;
}

inline unsigned int Actor::getHeight()const {
	return _height;
}

inline Actor::status Actor::getStatus()const {
	return _status;
}

inline Actor::gender Actor::getGender()const {
	return _gender;
}

inline void Actor::setName(const std::string& name) {
	_name = name;
}

inline void Actor::setSurname(const std::string& surname) {
	_surname = surname;
}

inline void Actor::setAge(unsigned int age) {
	_age = age;
}

inline void Actor::setHeight(unsigned int height) {
	_height = height;
}

inline void Actor::setStatus(status status) {
	_status = status;
}

inline void Actor::setGender(gender gender) {
	_gender = gender;
}

#endif
