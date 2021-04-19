#include "artist.hpp"

Artist::Artist() : _specialization(spec::test) {}

Artist::Artist(spec s) : _specialization(s) {}

void Artist::setSpec(spec s){
	_specialization = s;
}

Artist::spec Artist::getSpec() const{
	return _specialization;
}
