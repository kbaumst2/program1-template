#ifndef VECTOR_CW
#define VECTOR_CW

#include "Planet.h"

class Vector{
	unsigned size;
public:
	Planet ** vector;
	Vector::Vector();
	Vector::~Vector();
	int Vector::insert(int index, Planet * p);
	bool Vector::remove(int index);
	Planet * Vector::read(int index);
	unsigned Vector::size();
};

#endif
