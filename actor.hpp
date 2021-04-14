#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <iostream>
using namespace std;

class Actor{
public:
	enum class status { professional = 'p', amateur = 'a', student = 's', test = 0 };
	enum class gender { MALE = 'M', FEMALE = 'F', NONBINARY = 'N', TEST = 0 };

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
	void updateName(string);
	void updateSurname(string);
	void updateAge(unsigned int);
	void updateHeight(unsigned int);
	void updateStatus(status);
	void updateGender(gender);

	//printing
	void printFullName()const;
	void printFullData()const;

private:
	string _name;
	string _surname;
	unsigned int _age;
	unsigned int _height;
	status _statusAct;
	gender _genderAct;
};

ostream& operator<<(ostream& out, const Actor& actor);

#endif
