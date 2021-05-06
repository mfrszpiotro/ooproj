#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <iostream>
#include <vector>
using namespace std;

class Movie;
class Actor{
public:
	enum class status { director = 'd', professional = 'p', amateur = 'a', student = 's', test = 0 };
	enum class gender { MALE = 'M', FEMALE = 'F', NONBINARY = 'N', TEST = 0 };

	Actor();
	Actor(string, string);
	Actor(string, string, gender, status, unsigned int, unsigned int);
	Actor(Actor&);
	~Actor();
	Actor& operator=(Actor&);
	bool operator==(const Actor&) const;
	bool operator!=(const Actor&) const;
	
	string getName()const;
	string getSurname()const;
	unsigned int getAge()const;
	unsigned int getHeight()const;
	status getStatus()const;
	gender getGender()const;
	vector<Movie*> getMovieList()const;
	
	void setName(string);
	void setSurname(string);
	void setAge(unsigned int);
	void setHeight(unsigned int);
	void setStatus(status);
	void setGender(gender);
	void setPersonalData(string, string, gender, status, unsigned int, unsigned int);
	void setMovieList(vector<Movie*> ml);

	void addMovie(Movie*);
	void removeMovie(Movie*);
	int findMovie(const Movie*) const;
	
	void printMovieList()const;
	void printFullName()const;
	void printFullData()const;

private:
	void connectWithAll(vector<Movie*>);
	void disconnectWithAll(vector<Movie*>);
	void connectWith(Movie*);
	void disconnectWith(Movie*);

	string _name;
	string _surname;
	unsigned int _age;
	unsigned int _height;
	status _status;
	gender _gender;
	vector<Movie*> _movieList;
};

ostream& operator<<(ostream& out, const Actor& actor);

#endif
