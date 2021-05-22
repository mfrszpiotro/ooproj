#include "starring.hpp"
#include "movie.hpp"
using namespace std;

Starring::Starring() : _actor(nullptr), _movie(nullptr), _role("***no role assigned"), _salary(0) {}

Starring::Starring(const string& r, unsigned int s) : _actor(nullptr), _movie(nullptr), _role(r), _salary(s) {}

Starring::Starring(Movie* m, const string& r, unsigned int s): _actor(nullptr), _movie(m), _role(r), _salary(s) {
    if (m == nullptr) return;
    m->insertElement(this);
}

Starring::Starring(Actor* a, Movie* m, const string& r, unsigned int s): _actor(a), _movie(m), _role(r), _salary(s) {
    if (a == nullptr || _movie == nullptr) return;
    if (a->findMovie(_movie) == -1) a->addMovie(_movie);

    if (m == nullptr) return;
    m->insertElement(this);
}

Starring::~Starring(){
    _movie->removeElement(this);
    if (_actor == nullptr || _movie == nullptr || _movie->getSize() <= 0) return;
    if (_movie->findActorStarrings(_actor).size() > 1) return;
    unsigned int placement = _actor->findMovie(_movie);
    if (placement <= (_movie->getSize() - 1) && placement >= 0) {
        _actor->removeMovie(_movie);
        return;
    }
    throw "~Starring: destructor error";
}

Starring::Starring(const Starring& x) : _actor(x._actor), _movie(x._movie), _role(x._role), _salary(x._salary) {
    if (_actor == nullptr || _movie == nullptr) return;
    if (_actor->findMovie(_movie) == -1) _actor->addMovie(_movie);

    if (_movie == nullptr) return;
    _movie->insertElement(this);
}

Starring Starring::operator=(const Starring& x){
    if (this == &x) return *this;
    unlink();
    link(x._actor, x._movie);
    setRole(x._role);
    setSalary(x._salary);
    return *this;
}

void Starring::link(Actor* a){
    if (a == nullptr || _movie == nullptr) {
        _actor = a;
        return;
    }
    if (a->findMovie(_movie) == -1) a->addMovie(_movie);
    _actor = a;
}

void Starring::link(Movie* m){
    if (m == nullptr){
        _movie = m;
        return;
    }
    m->insertElement(this);
    _movie = m;
}

void Starring::link(Actor* a, Movie* m){
    link(a);
    link(m);
}

void Starring::unlinkActor(){
    if (_actor == nullptr || _movie == nullptr || _movie->getSize() <= 0){
        _actor = nullptr;
        return;
    }
    if (_movie->findActorStarrings(_actor).size() > 1) {
        _actor = nullptr;
        return;
    };
    _actor->removeMovie(_movie);
    _actor = nullptr;
}

void Starring::unlinkMovie(){
    _movie->removeElement(this); //didnt think about it much, watch out
    _actor = nullptr;
}

void Starring::unlink(){
    unlinkActor();
    unlinkMovie();
}

std::ostream& operator<<(std::ostream& out, const Starring& starring){
    if (starring.getMovie() == nullptr && starring.getActor() == nullptr)
        out << "Role: " << starring.getRole() <<
        " to earn: " << starring.getSalary() << "$";
    else if (starring.getActor() == nullptr)
        out << "Role: " << starring.getRole() <<
        " in " << *starring.getMovie() <<
        " to earn: " << starring.getSalary() << "$";
    else if (starring.getMovie() == nullptr)
        out << *starring.getActor() <<
        " as: " << starring.getRole() <<
        " to earn: " << starring.getSalary() << "$";
    else out << *starring.getActor() <<
        " as " << starring.getRole() <<
        " in " << *starring.getMovie() <<
        " and earns " << starring.getSalary() << "$";
    return out;
}
