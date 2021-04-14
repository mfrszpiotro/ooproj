#include "actor.hpp"

Actor::Actor(string name, string surname):
	_name(name), _surname(surname), _age(0), _height(0), _genderAct(gender::TEST), _statusAct(status::test) {}

Actor::Actor(string firstN, string lastN, gender g, status s, unsigned int age, unsigned int height):
	_name(firstN), _surname(lastN), _age(age), _height(height), _genderAct(g), _statusAct(s) {}

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
	return _statusAct;
}
Actor::gender Actor::getGender()const {
	return _genderAct;
}

void Actor::updateName(string name) {
	_name = name;
}
void Actor::updateSurname(string surname) {
	_surname = surname;
}
void Actor::updateAge(unsigned int age) {
	_age = age;
}
void Actor::updateHeight(unsigned int height) {
	_height = height;
}
void Actor::updateStatus(status status) {
	_statusAct = status;
}
void Actor::updateGender(gender gender) {
	_genderAct = gender;
}

void Actor::printFullName() const {
	cout << *this << endl;
}

void Actor::printFullData() const {
	cout << *this << endl;
	cout << _age << endl;
	cout << _height << endl;
	switch (_statusAct) {
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
	switch (_genderAct) {
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

