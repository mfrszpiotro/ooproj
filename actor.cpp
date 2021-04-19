#include "actor.hpp"

Actor::Actor(): _name("Test"), _surname("Testing"), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(string name, string surname):
	_name(name), _surname(surname), _age(0), _height(0), _gender(gender::TEST), _status(status::test) {}

Actor::Actor(string firstN, string lastN, gender g, status s, unsigned int age, unsigned int height):
	_name(firstN), _surname(lastN), _age(age), _height(height), _gender(g), _status(s) {}

string Actor::getName()const {
	return _name;
}
string Actor::getSurname()const {
	return _surname;
}
unsigned int Actor::getAge() const {
	return _age;
}
unsigned int Actor::getHeight()const {
	return _height;
}
Actor::status Actor::getStatus()const {
	return _status;
}
Actor::gender Actor::getGender()const {
	return _gender;
}

void Actor::setName(string name) {
	_name = name;
}
void Actor::setSurname(string surname) {
	_surname = surname;
}
void Actor::setAge(unsigned int age) {
	_age = age;
}
void Actor::setHeight(unsigned int height) {
	_height = height;
}
void Actor::setStatus(status status) {
	_status = status;
}
void Actor::setGender(gender gender) {
	_gender = gender;
}
void Actor::setPersonalData(string name, string surname, gender gender, status status,
	unsigned int age, unsigned int height) {
	_name = name;
	_surname = surname;
	_age = age;
	_height = height;
	_status = status;
	_gender = gender;
}

void Actor::printFullName() const {
	cout << *this << endl;
}

void Actor::printFullData() const {
	cout << *this << endl;
	cout << _age << endl;
	cout << _height << endl;
	switch (_status) {
	case status::amateur:
		cout << "amateur" << endl;
		break;
	case status::student:
		cout << "student" << endl;
		break;
	case status::professional:
		cout << "professional" << endl;
		break;
	default: cout << "test" << endl;
	}
	switch (_gender) {
	case gender::FEMALE:
		cout << "FEMALE" << endl;
		break;
	case gender::MALE:
		cout << "MALE" << endl;
		break;
	case gender::NONBINARY:
		cout << "NONBINARY" << endl;
		break;
	default: cout << "TEST" << endl;
	}
}

ostream& operator<<(ostream& out, const Actor& actor) { // only for full name
	out << actor.getName() << " " << actor.getSurname();
	return out;
}

