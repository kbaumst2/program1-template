#ifndef VECTOR_CW
#define VECTOR_CW

#include "Planet.h"
#include "Vector.h"

class Starvector{
public:
	Vector planets;
	Starvector();
	~Starvector();
	long addPlanet();
	bool removePlanet(int id);
	Planet * getPlanet(int id);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets(){ return planets.size(); };
};
