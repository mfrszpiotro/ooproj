#include "animation.hpp"

Animation::Animation(vector<Artist> list) : _artList(list) {}

void Animation::addArtist(Artist x){
	_artList.push_back(x);
}

void Animation::copyArtList(vector<Artist> list){
	_artList = list;
}

vector<Artist> Animation::getArtList() const{
	return _artList;
}

void Animation::printArtList() const{
	cout << "List of artists: " << endl;
	for (unsigned int i = 0; i < _artList.size(); ++i) {
		cout << "- " << _artList[i] << endl;
	}
}
