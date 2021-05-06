#include "movie.hpp"

Movie::Movie(Director* dir) : _head(nullptr), _filmCastSize(0), _director(dir), _title("No title assigned!!!"), _releaseDate(tm()) {}

Movie::Movie(Director* dir, const string& title) : _head(nullptr), _filmCastSize(0), _director(dir), _title(title), _releaseDate(tm()) {
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
	if (tmp != nullptr && tmp != this) cerr << "Error Movie:insertElement: this starring is already occupied" << endl;
	if (x->getActor() != nullptr) {
		if (x->getActor()->findMovie(this)) x->getActor()->addMovie(this);
	}

	element* etr = new element; // (std::nothrow)
	if (etr == nullptr) {
		cerr << "Movie::insertElement: Allocation not sucessful!" << endl;
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
		if (x->getActor()->findMovie(this)) x->getActor()->removeMovie(this);
	}

	element* tmp = _head;
	if (tmp && tmp->data == x) {
		_head = tmp->next;
		tmp->data->setMovie(nullptr);
		delete tmp;
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
		return false;
	}
}

Starring* Movie::getNthElement(int n){
	element* etr = _head;
	for (int i = 1; i < n && etr->next != nullptr; i++) {
		etr = etr->next;
	}
	return etr->data;
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

string Movie::getTitle() const {
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
		element* ntr = new element;
		if (!ntr) {
			cerr << "Movie::copyAllElements: Allocation not successfull!" << endl;
			break;
		}
		ntr->data = copied; // xtr->data;
		ntr->data->link(ntr->data->getActor());
		ntr->next = nullptr;

		if (!_head) {
			_head = ntr;
		}
		else {
			etr->next = ntr;
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
		_head->data->unlink(_head->data->getActor());
		delete _head;
		_head = etr;
	}
	_filmCastSize = 0;
}

string Movie::getDirectorName() const {
	return (_director->getName() + " " + _director->getSurname());
}

int Movie::getSize() const {
	return _filmCastSize;
}

void Movie::setTitle(const string& x) {
	_title = x;
}

void Movie::setReleaseDate(const tm& x) {
	_releaseDate = x;
}

void Movie::printReleaseDate(){
	if (_releaseDate.tm_mday < 10) cout << "0" << _releaseDate.tm_mday;
	else cout << _releaseDate.tm_mday;
	cout << ".";
	if (_releaseDate.tm_mon < 10) cout << "0" << _releaseDate.tm_mon;
	else cout << _releaseDate.tm_mon;
	cout << ".";
	cout << _releaseDate.tm_year;
}

void Movie::copyActorStarrings(Actor* a){
	vector<int> placements = findActorStarrings(a);
	if (placements.empty()) {
		cerr << "Movie::removeActorStarrings: This actor is not present in the movie!" << endl;
		return;
	}
	int count = 0;
	element* etr = _head;
	while (etr) {
		for (unsigned int i = 0; i < placements.size(); ++i) {
			if (placements[i] == count) {
				if (getNthElement(i)->getActor() == a) {
					cout << "***Successfull search" << endl;
					insertElement(getNthElement(i)); //copying element
					cout << "***Successfull copy" << endl;
					break;
				}
			}
		}
		count++;
		etr = etr->next;
	}
	return;
}

void Movie::removeActorStarrings(Actor* a){
	vector<int> placements = findActorStarrings(a);
	if (placements.empty()) {
		cerr << "Movie::removeActorStarrings: This actor is not present in the movie!" << endl;
		return;
	}
	element* etr = _head;
	while (etr) {
		if (etr->data->getActor() == a) {
			etr->data->setActor(nullptr);
		}
	etr = etr->next;
	}
}

vector<int> Movie::findActorStarrings(const Actor* a) const{
	vector<int> placements;
	int count = 0;
	element* etr = _head;
	while (etr) {
		if (etr->data->getActor() == a) {
			placements.push_back(count);
		}
		count++;
		etr = etr->next;
	}
	return placements;
}

void Movie::printFilmCast(){
	element* tmp = _head;
	while (tmp) {
		cout << "- " << *tmp->data->getActor() << endl;
		tmp = tmp->next;
	}
}

void Movie::printFullData(){
	cout << "Directed by: " << _director->getName() << " " << _director->getSurname() << endl;
	cout << "Title: " << _title << endl;
	cout << "Release date: "; printReleaseDate(); cout << endl;
	cout << "Film cast: " << endl; printFilmCast();
}

ostream& operator<<(ostream& out, const Movie& x){ // only title
	out << x.getTitle();
	return out;
}

Movie& Movie::operator=(Movie& src) {
	return *this;
}
