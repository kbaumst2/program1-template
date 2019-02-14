#include "Planet.h"
#include "Star.h"
#include <cstdlib>
#include <iostream>


Star::Star(){
  this->current_planets = 0;
  this->planets = NULL;
}

Star::~Star(){
	for(int i = 0; i < current_planets; i++) delete planets[i];
	delete [] planets;
}

long int Star::addPlanet(){
	if(planets == NULL){
		planets = new Planet*[1];
		Planet * new_planet = new Planet(rand() % 3001);
		planets[current_planets] = new_planet;
		current_planets++;
		return planets[current_planets-1]->getID();
	}
	Planet ** temp = new Planet*[current_planets+1];
	for (int i = 0; i < current_planets; i++){
		temp[i] = planets[i];
	}
	delete[] planets;
	planets = temp;
	Planet * new_planet = new Planet(rand() % 3001);
	planets[current_planets] = new_planet;
	current_planets++;
       	return planets[current_planets-1]->getID();
}

bool Star::removePlanet(int planet_id){
	if(planets == NULL || getPlanet(planet_id) == NULL){
		return false;
	}
	int remove_id = 0;
	for (int i = 0; i < current_planets; i++){
		if(planet_id == planets[i]->getID()){
			remove_id = i;
			break;
		}
	}
	Planet ** temp = new Planet*[current_planets-1];
	for (int i = 0; i < remove_id; i++){
	  temp[i] = planets[i];
	}
	for (int j = remove_id + 1; j < current_planets; j++){
	  temp[j-1] = planets[j];
	}
	delete planets[remove_id];
	delete[] planets;
	planets = temp;
	current_planets--;
       	return true;
}

Planet * Star::getPlanet(int planet_id){
	if(planets == NULL){
		return NULL;
	}
	for(int i = 0; i < current_planets; i++){
		if(planet_id == planets[i]->getID()) return planets[i];
	}
	return NULL;
}

//Planet Star::getFurthest(){
//  int ret_planet = 0;
//  int dist = 0;
//  for(int i = 0; i < current_planets; i++){
//    if(this->planets[i].getDistance() > dist){
//      dist = this->planets[i].getDistance();
//      ret_planet = i;
//    }
//  }
//  return this->planets[ret_planet];
//}

void Star::orbit(){
  for(int i = 0; i < current_planets; i++){
    this->planets[i]->orbit();
  }
}

void Star::printStarInfo(){
  std::cout << "The star has " << this->getCurrentNumPlanets() << " planets." << std::endl;
  std::cout << "Planets:" << std::endl;
  for(int i = 0; i <current_planets; i++){
    std::cout << "Planet " << this->planets[i]->getType() << this->planets[i]->getID() << " is " << this->planets[i]->getDistance() << " million miles away at position " << this->planets[i]->getPos() << " around the star." << std::endl;
      }
}
