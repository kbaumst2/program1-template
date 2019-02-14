#include "List.h"

class Starlist{
	StarList();
	~StarList();
	long addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
};


