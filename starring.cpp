#include "starring.hpp"

Starring::Starring() : _actor(nullptr), _movie(nullptr), _role("***no role assigned"), _salary(0) {}

Starring::Starring(string r, unsigned int s) : _actor(nullptr), _movie(nullptr), _role(r), _salary(s) {}

Starring::Starring(Movie* m, string r, unsigned int s): _actor(nullptr), _movie(m), _role(r), _salary(s) {
    _movie->addStarring(*this);
}

Starring::Starring(Actor* a, Movie* m, string r, unsigned int s): _actor(a), _movie(m), _role(r), _salary(s) {
    if (_movie != nullptr) _actor->addMovie(_movie);
    if (_movie != nullptr) _movie->addStarring(*this);
}

Starring::~Starring(){
    if (_actor != nullptr) _actor->removeMovie(_movie);
    if (_movie != nullptr) _movie->removeStarring(*this);
}

Starring::Starring(const Starring& x) : _actor(x._actor), _movie(x._movie), _role(x._role), _salary(x._salary) {
    if (_actor != nullptr) _actor->addMovie(_movie);
    if (_movie != nullptr) _movie->addStarring(*this);
}

Starring Starring::operator=(Starring& x){
    if (this == &x) {
        return *this;
    }
    if (_actor != nullptr) _actor->removeMovie(_movie);
    if (_movie != nullptr) _movie->removeStarring(x);
    _actor = x._actor;
    _movie = x._movie;
    _role = x._role;
    _salary = x._salary;
    if (_actor != nullptr) _actor->addMovie(_movie);
    if (_movie != nullptr) _movie->addStarring(*this);
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
    cout << "Role: " << _role << endl;
    cout << "Salary: " << _salary << "$" << endl;

    cout << "Actor: ";
    if(_actor!=nullptr) _actor->printFullName();
    cout << endl;
    cout << "Movie: ";
    if (_movie != nullptr) cout << _movie->getTitle();
    cout << endl;
}

ostream& operator<<(ostream& out, const Starring& starring){
    out << starring.getActor() << 
        " as " << starring.getRole() <<
        " in " << starring.getMovie() << 
        " and earns " << starring.getSalary() << "$" << endl;
    return out;
}
