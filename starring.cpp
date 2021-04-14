#include "starring.hpp"

Actor* Starring::getActor()const {
    return _actor;
}

unsigned int Starring::getSalary()const {
    return _salary;
}

void Starring::setActor(Actor* a) {
    _actor = a;
}

void Starring::setSalary(const unsigned int s) {
    _salary = s;
}