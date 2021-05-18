#include "director.hpp"
#include "movie.hpp"

Director::Director() : Actor() {};

Director::Director(const char* name, const char* surname) : Actor(name, surname) {}

Director::~Director(){
	/*std::vector<Movie*> movieList = getMovieList();
	for (unsigned int i = 0; i < movieList.size(); ++i) {
		std::cout << movieList[i] << " in array: " << i << std::endl;
	}*/
}

Director::Director(const Director&){
	std::vector<Movie*> movieList = getMovieList();
	for (unsigned int i = 0; i < movieList.size(); ++i) {
		Movie* newMovie = new Movie(*movieList[i]);
	}
}

Director& Director::operator=(const Director&){
	return *this;
	//to do
}
