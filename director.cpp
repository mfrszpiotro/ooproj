#include "director.hpp"
#include "movie.hpp"
#include "starring.hpp"

Director::Director() : Actor() {};

Director::Director(string name, string surname) : Actor(name, surname) {}
Director::~Director(){
}
Director::Director(const Director&){
}
Director& Director::operator=(const Director&){
	return *this;
}
;
