#include "director.hpp"

Director::Director() : Actor() {};

Director::Director(string name, string surname) : Actor(name, surname) {}
Director::~Director(){
	vector<Movie*> movieList = getMovieList();
	for (int i = 0; i < movieList.size(); ++i) {
		cout << movieList[i] << " in array: " << i << endl;
	}
}
Director::Director(const Director&){
}
Director& Director::operator=(const Director&){
	return *this;
}
;
