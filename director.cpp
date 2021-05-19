#include "director.hpp"
#include "movie.hpp"

using namespace std;

Director::Director() : Actor() {};

Director::Director(const char* name, const char* surname) : Actor(name, surname) {}

Director::~Director(){
	deleteAll();
}

Director::Director(Director& x): Actor(x){
	copyAll(x);
}

Director& Director::operator=(Director& x){
	if (this == &x) return *this;
	deleteAll();
	setPersonalData(x.getName().c_str(), x.getSurname().c_str(),
		x.getGender(), x.getStatus(), x.getAge(), x.getHeight());
	copyAll(x);
	return *this;
}

void Director::copyAll(Director& x){
	std::vector<Movie*> copyMovieList = x.getMovieList();
	for (unsigned int i = 0; i < copyMovieList.size(); ++i) {
		Movie* newMovie = new Movie(this, copyMovieList[i]->getTitle());
		newMovie->setReleaseDate(copyMovieList[i]->getReleaseDate());
		newMovie->copyAllElements(*copyMovieList[i]);
	}
}

void Director::deleteAll(){
	std::vector<Movie*> deleteMovieList = getMovieList();
	while (!deleteMovieList.empty()) {
		deleteMovieList.back()->removeAllElements();
		delete deleteMovieList.back();
		deleteMovieList.pop_back();
	}
}
