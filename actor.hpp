#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <iostream>
#include <vector>
using namespace std;

class Movie;
class Actor{
public:
	enum class status { professional = 'p', amateur = 'a', student = 's', test = 0 };
	enum class gender { MALE = 'M', FEMALE = 'F', NONBINARY = 'N', TEST = 0 };

	Actor();
	Actor(string, string);
	Actor(string, string, gender, status, unsigned int, unsigned int);
	
	//getters
	string getName()const;
	string getSurname()const;
	unsigned int getAge()const;
	unsigned int getHeight()const;
	status getStatus()const;
	gender getGender()const;
	
	//setters
	void setName(string);
	void setSurname(string);
	void setAge(unsigned int);
	void setHeight(unsigned int);
	void setStatus(status);
	void setGender(gender);
	void setPersonalData(string, string, gender, status,
		unsigned int, unsigned int);

	//printing
	void printFullName()const;
	void printFullData()const;

private:
	string _name;
	string _surname;
	unsigned int _age;
	unsigned int _height;
	status _status;
	gender _gender;
	//vector<Movie> movieList;
};

ostream& operator<<(ostream& out, const Actor& actor);

#endif
