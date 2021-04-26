#include "starring.hpp"

Starring::Starring() : _actor(nullptr), _movie(nullptr), _role("***no role assigned"), _salary(0) {}

Starring::Starring(Movie* m, string r, unsigned int s): _actor(nullptr), _movie(m), _role(r), _salary(s) {
    _movie->addStarring(*this);
}

Starring::Starring(Actor* a, Movie* m, string r, unsigned int s): _actor(a), _movie(m), _role(r), _salary(s) {
    _actor->addMovie(_movie);
    _movie->addStarring(*this);
}

Starring::~Starring(){
    _actor->removeMovie(_movie);
    _movie->removeStarring(*this);
}

Starring::Starring(const Starring& x) : _actor(x._actor), _movie(x._movie), _role(x._role), _salary(x._salary) {
    _actor->addMovie(_movie);
    _movie->addStarring(*this);
}

Starring Starring::operator=(Starring& x){
    if (this == &x) {
        return *this;
    }
    _actor->removeMovie(_movie);
    _movie->removeStarring(x);
    _actor = x._actor;
    _movie = x._movie;
    _role = x._role;
    _salary = x._salary;
    _actor->addMovie(_movie);
    _movie->addStarring(*this);
    return *this;
}

bool Starring::operator==(const Starring& x) const{
    if (_role == x._role &&
        _salary == x._salary &&
        _actor == x._actor &&
        _movie == x._movie) return true;
    else return false;
}

unsigned int Starring::getSalary()const {
    return _salary;
}

Actor* Starring::getActor()const {
    return _actor;
}

Movie* Starring::getMovie() const{
    return _movie;
}

string Starring::getRole() const{
    return _role;
}

void Starring::setActor(Actor* a) {
    _actor = a;
}

void Starring::setMovie(Movie* m){
    _movie = m;
}

void Starring::setSalary(const unsigned int s) {
    _salary = s;
}

void Starring::setRole(const string r){
    _role = r;
}

void Starring::printFullData() const{
    cout << "Actor: "; _actor->printFullName();
    cout << "Movie: " << _movie->getTitle() << endl;
    cout << "Role: " << _role << endl;
    cout << "Salary: " << _salary << "$" << endl;
}
