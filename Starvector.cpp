#include "Vector.h"
#include "Planet.h"

Starvector::Starvector(){
	planets = new Vector();
}

Starvector::~Starvector(){
	delete planets;
}

long Starvector::addPlanet(){
	Planet * new_planet = new Planet();
	planets.insert(planets.size(), new_planet);
	return planets[planets.size() - 1]->getID();
}

bool Starvector::removePlanet(int id){
	return planets.remove(id);
}

Planet * Starvector::getPlanet(int id){
	return planets.read(id);
}

void Starvector::orbit(){
	for(int i = 0; i < planets.size(); i++){
		planets[i]->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "The star has " << this->getCurrentNumPlanets() << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < planets.size(); i++){
		std::cout << "Planet " << this->planets[i]->getType() << this->planets[i]->getID() << " is " <<this->planets[i]->getDistance() << " million miles away at position " << this->planets[i]->getPos() << " around the star." << std::endl;
      	}
}
