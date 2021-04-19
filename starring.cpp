#include "starring.hpp"
#include "movie.hpp"

Starring::Starring() : _actor(nullptr), _movie(nullptr), _salary(0) {};

Starring::Starring(Actor* a, Movie* m, unsigned int salary) : _actor(a), _movie(m), _salary(salary) {
    *m += *this;
}
Starring::~Starring(){
    //*_movie -= *this;
}
;

Actor* Starring::getActor()const {
    return _actor;
}

Movie* Starring::getMovie()const {
    return _movie;
}

unsigned int Starring::getSalary()const {
    return _salary;
}

void Starring::setActor(Actor* a) {
    _actor = a;
}

void Starring::setMovie(Movie* m){
    _movie = m;
    *m += *this;
}


void Starring::setSalary(const unsigned int s) {
    _salary = s;
}

void Starring::printFullData() const{
    cout << "Actor: "; _actor->printFullName();
    cout << "Movie: " <<_movie->getTitle() << endl;
    cout << "Salary: " << _salary << "$" << endl;
}

/*
ostream& operator<<(ostream& out, const Starring& starring){
    
}*/

