#ifndef VECTOR_CW
#define VECTOR_CW

#include "Planet.h"

class Vector{
	unsigned int size;
public:
	Planet ** vector;
	Vector();
	~Vector();
	int insert(int index, Planet * p);
	bool remove(int index);
	Planet * read(int index);
	unsigned int size();
};

#endif
