#ifndef STAR_CW
#define STAR_CW

#include "Planet.h"

class Star{
	private:
        int current_planets;
	public:
        Planet ** planets;
        Star();
        ~Star();
        long int addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
//      Planet getFurthest();
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets(){ return current_planets; };
        //you may add any additional methodas you may need.
};


class StarList{
public:
	List stars;
	StarList();
	~StarList();
	long addPlanet();
	bool removePlanet(long);
	Planet * getPlanet(long);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
}

#endif
