#include "Serialize.hpp"

Serialize::Serialize() {}

Serialize::~Serialize() {}


//
uintptr_t Serialize::serialize(Data *ptr) {

	uintptr_t res;

	res = reinterpret_cast<uintptr_t>(ptr);

	return res;

}

Data *Serialize::deserialize(uintptr_t raw) {

	Data *res;

	res = reinterpret_cast<Data *>(raw);

	return res;

}

