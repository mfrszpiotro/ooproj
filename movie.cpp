#include "movie.hpp"
#include "director.hpp"
#include "starring.hpp"
using namespace std;

Movie::Movie(Director* dir) : _filmCast(), _director(dir), _title("No title assigned!!!"), _releaseDate(tm()) {}

Movie::Movie(Director* dir, const string& title) : _filmCast(), _director(dir), _title(title), _releaseDate(tm()) {
	_director->addMovie(this);
}

Movie::~Movie() {
	_director->removeMovie(this);
	removeAllElements();
}

Movie::Movie(const Movie& src): _filmCast(), _director(src._director), _title(src._title), _releaseDate(src._releaseDate) {
	copyAllElements(src);
	_director->addMovie(this);
}

void Movie::insertElement(Starring* x){
	Movie* tmp = x->getMovie(); // maybe copy element function is needed
	if (tmp != nullptr && tmp != this) std::cerr << "Movie:insertElement: this starring is already occupied" << std::endl;
	if (x->getActor() != nullptr) {
		if (x->getActor()->findMovie(this)) x->getActor()->addMovie(this);
	}
	_filmCast.push_back(x);
	_filmCast.back()->setMovie(this);
}

bool Movie::removeElement(Starring* x){
	if (!findElement(x)) return false;
	if (x->getActor() != nullptr) {
		if (x->getActor()->findMovie(this)) {
			x->getActor()->removeMovie(this);
		}
	}
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		if (_filmCast[i] == x) {
			_filmCast[i]->setMovie(nullptr);
			_filmCast[i] = _filmCast.back();
			_filmCast.pop_back();
			return true;
		}
	}
	return false;
}

Starring Movie::getNthElement(int n) {
	//set range (except.)
	return *_filmCast[n];
}

bool Movie::findElement(const Starring* x) const{
	if (x->getMovie() == nullptr) return false;
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		if (_filmCast[i] == x) return true;
	}
	return false;
}

void Movie::copyAllElements(const Movie& x){
	for (unsigned int i = 0; i < x._filmCast.size(); ++i) {
		Starring* copied = x._filmCast[i];
		Starring* newStar = new Starring(copied->getRole(), copied->getSalary());
		newStar->link(x._filmCast[i]->getActor());
		newStar->link(this);
		_filmCast[i] = newStar;
	}
}

void Movie::removeAllElements(){
	while (_filmCast.size() > 0) {
		_filmCast.back()->unlinkActor();
		removeElement(_filmCast.back());
	}
}

void Movie::copyActorStarrings(Actor* _this, Actor* a){
	std::vector<Starring*> foundStars = findActorStarrings(a);
	for (unsigned int i = 0; i < foundStars.size(); ++i) {
		Starring* copy = foundStars[i];
		Starring* newStar = new Starring(copy->getRole(), copy->getSalary());
		newStar->link(_this, this);
	}
}

void Movie::removeActorStarrings(Actor* a){
	/*std::vector<Starring*> foundStars = findActorStarrings(a);
	while (foundStars.size() != 0){
		foundStars.back()->setActor(nullptr);
		foundStars.back()->setMovie(nullptr);
		delete foundStars.back();
		foundStars.pop_back();
	}*/
}

std::vector<Starring*> Movie::findActorStarrings(const Actor* a) const{
	std::vector<Starring*> foundStars;
	for (unsigned int i = 0; i < _filmCast.size(); ++i) {
		if (_filmCast[i]->getActor() == nullptr) return foundStars;
		if (*_filmCast[i]->getActor() == *a) {
			foundStars.push_back(_filmCast[i]);
		}
	}
	return foundStars;
}

string Movie::getDirectorName() const {
	return (_director->getName() + " " + _director->getSurname());
}

std::ostream& operator<<(std::ostream& out, const Movie& x){
	out << x.getTitle() << "(dir. " << x.getDirectorName() << ", "
		<< x.getReleaseDate().tm_year << ")";
	return out;
}

Movie& Movie::operator=(Movie& src) {
	return *this;
}
