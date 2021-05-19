#include "movie.hpp"
using namespace std;

Movie::Movie(Director* dir) : _head(nullptr), _filmCastSize(0), _director(dir), _title("No title assigned!!!"), _releaseDate(tm()) {}

Movie::Movie(Director* dir, string title) : _head(nullptr), _filmCastSize(0), _director(dir), _title(title), _releaseDate(tm()) {
	_director->addMovie(this);
}

Movie::~Movie() {
	_director->removeMovie(this);
	removeAllElements();
}

Movie::Movie(const Movie& src): _head(nullptr), _filmCastSize(0), _director(src._director), _title(src._title), _releaseDate(src._releaseDate) {
	copyAllElements(src);
	_director->addMovie(this);
}

void Movie::insertElement(Starring* x){
	Movie* tmp = x->getMovie(); // maybe copy element function is needed
	if (tmp != nullptr && tmp != this) std::cerr << "Movie:insertElement: this starring is already occupied" << std::endl;
	if (x->getActor() != nullptr) {
		if (x->getActor()->findMovie(this)) x->getActor()->addMovie(this);
	}

	element* etr = new element; // (std::nothrow)
	if (etr == nullptr) {
		std::cerr << "Movie::insertElement: Allocation not sucessful!" << std::endl;
		return;
	}
	etr->data = x;
	etr->data->setMovie(this);
	etr->next = _head; // insertion at the beginning of the list 
	_head = etr;
	++_filmCastSize;
}

bool Movie::removeElement(Starring* x){
	if (!findElement(x)) return false;
	if (x->getActor() != nullptr) {
		if (x->getActor()->findMovie(this)) {
			x->getActor()->removeMovie(this);
		}
	}

	element* tmp = _head;
	if (tmp && tmp->data == x) {
		_head = tmp->next;
		tmp->data->setMovie(nullptr);
		delete tmp;
		--_filmCastSize;
		return true;
	}
	else {
		element* prev = nullptr;
		while (tmp != nullptr && tmp->data != x) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == nullptr) return false;
		prev->next = tmp->next;
		tmp->data->setMovie(nullptr);
		delete tmp;
		--_filmCastSize;
		return true;
	}
}

Starring Movie::getNthElement(int n){
	element* etr = _head;
	for (int i = 1; i < n && etr->next != nullptr; i++) {
		etr = etr->next;
	}
	return *etr->data;
}

bool Movie::findElement(const Starring* x) const{
	if (x->getMovie() == nullptr) return false;
	element* etr = _head;
	while (etr) {
		if (etr->data == x) return true;
		etr = etr->next;
	}
	return false;
}

std::string Movie::getTitle() const {
	return _title;
}

tm Movie::getReleaseDate() const {
	return _releaseDate;
}

void Movie::copyAllElements(const Movie& x){
	element* etr = _head;
	element* xtr = x._head;

	while (xtr) {
		Starring* copied = xtr->data;
		Starring* newStar = new Starring(copied->getRole(), copied->getSalary());
		element* ntr = new element;
		if (!ntr || !newStar) {
			std::cerr << "Movie::copyAllElements: Allocation not successfull!" << std::endl;
			break;
		}
		newStar->link(xtr->data->getActor());
		newStar->link(this);
		ntr->data = newStar;
		ntr->next = nullptr;

		if (!_head) {
			_head = ntr;
		}
		else {
			//etr->next = ntr;
		}
		etr = ntr; //keep track of the last element in *this

		xtr = xtr->next;
	}
	_filmCastSize = x._filmCastSize;
}

void Movie::removeAllElements(){
	element* etr = _head;
	while (etr) {
		etr = etr->next;
		if(_head->data->getActor() != nullptr) _head->data->unlinkActor();
		removeElement(_head->data);
		_head = etr;
	}
	_filmCastSize = 0;
}

std::string Movie::getDirectorName() const {
	return (_director->getName() + " " + _director->getSurname());
}

int Movie::getSize() const {
	return _filmCastSize;
}

void Movie::setTitle(const char* x) {
	_title = x;
}

void Movie::setReleaseDate(const tm& x) {
	_releaseDate = x;
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
	element* etr = _head;
	while (etr) {
		if (etr->data->getActor() == nullptr) return foundStars;
		if (*etr->data->getActor() == *a) {
			foundStars.push_back(etr->data);
		}
		etr = etr->next;
	}
	return foundStars;
}

void Movie::printFilmCast(){
	element* tmp = _head;
	while (tmp) {
		std::cout << "- " << *tmp->data << std::endl;
		tmp = tmp->next;
	}
}

std::ostream& operator<<(std::ostream& out, const Movie& x){
	out << x.getTitle() << "(dir. " << x.getDirectorName() << ", "
		<< x.getReleaseDate().tm_year << ")";
	return out;
}

Movie& Movie::operator=(Movie& src) {
	return *this;
}
