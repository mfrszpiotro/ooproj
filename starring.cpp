#include "starring.hpp"
#include "movie.hpp"

Starring::Starring() : _actor(nullptr), _movie(nullptr), _role("***no role assigned"), _salary(0) {}

Starring::Starring(string r, unsigned int s) : _actor(nullptr), _movie(nullptr), _role(r), _salary(s) {}

Starring::Starring(Movie* m, string r, unsigned int s): _actor(nullptr), _movie(m), _role(r), _salary(s) {
    connectWith(m);
}

Starring::Starring(Actor* a, Movie* m, string r, unsigned int s): _actor(a), _movie(m), _role(r), _salary(s) {
    connectWith(a, m);
}

Starring::~Starring(){
    disconnectWith(_actor,_movie);
}

Starring::Starring(const Starring& x) : _actor(x._actor), _movie(x._movie), _role(x._role), _salary(x._salary) {
    connectWith(x._actor,x._movie);
}

Starring Starring::operator=(const Starring& x){
    if (this == &x) return *this;
    unlink(x._actor, x._movie);
    link(x._actor, x._movie);
    setRole(x._role);
    setSalary(x._salary);
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

void Starring::link(Actor* a){
    connectWith(a);
    _actor = a;
}

void Starring::link(Movie* m){
    connectWith(m);
    _movie = m;
}

void Starring::link(Actor* a, Movie* m){
    connectWith(a);
    _actor = a;
    connectWith(m);
    _movie = m;
}

void Starring::unlink(Actor* a){
    disconnectWith(a);
    _actor = nullptr;
}

void Starring::unlink(Movie* m){
    disconnectWith(m);
    _actor = nullptr;
}

void Starring::unlink(Actor* a, Movie* m){
    disconnectWith(a);
    _actor = nullptr;
    disconnectWith(m);
    _actor = nullptr;
}

void Starring::setMovie(Movie* m){
    _movie = m;
}

void Starring::setActor(Actor* a){
    _actor = a;
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

void Starring::setSalary(const unsigned int s) {
    _salary = s;
}

void Starring::setRole(const string r){
    _role = r;
}

void Starring::printFullData() const{
    cout << "Role: " << _role << endl;
    cout << "Salary: " << _salary << "$" << endl;

    if (_actor != nullptr) cout << "Actor: " << *_actor << endl;
    if (_movie != nullptr) cout << "Movie: " << _movie->getTitle() << endl;
}

void Starring::connectWith(Actor* a) {
    if (a == nullptr || _movie == nullptr) return;
    if(a->findMovie(_movie) == -1) a->addMovie(_movie);
}

void Starring::connectWith(Movie* m){
    if (m == nullptr) return;
    m->insertElement(this); //didnt think about it much, watch out
}

void Starring::connectWith(Actor* a, Movie* m){
    connectWith(a);
    connectWith(m);
}

void Starring::disconnectWith(Actor* a){
    if (_movie == nullptr || _movie->getSize() <= 0) return;
    int placement = a->findMovie(_movie);
    if (placement <= (_movie->getSize() - 1) && placement >= 0) {
        a->removeMovie(_movie);
        return;
    }
    cerr << "Starring::disconnectWith error" << endl;
}

void Starring::disconnectWith(Movie* m){
    m->removeElement(this); //didnt think about it much, watch out
}

void Starring::disconnectWith(Actor* a, Movie* m){
    disconnectWith(a);
    disconnectWith(m);
}

ostream& operator<<(ostream& out, const Starring& starring){
    if (starring.getMovie() == nullptr && starring.getActor() == nullptr)
        out << "Role: " << starring.getRole() <<
        " to earn: " << starring.getSalary() << "$";
    else if (starring.getActor() == nullptr)
        out << "Role: " << starring.getRole() <<
        " in " << *starring.getMovie() <<
        " to earn: " << starring.getSalary() << "$";
    else out << *starring.getActor() <<
        " as " << starring.getRole() <<
        " in " << *starring.getMovie() <<
        " and earns " << starring.getSalary() << "$";
    return out;
}
