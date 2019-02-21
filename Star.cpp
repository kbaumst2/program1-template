#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include "Star.h"
#include <cstdlib>
#include <iostream>

Starvector::Starvector(){
	planets = new Vector();
}

Starvector::~Starvector(){
	delete planets;
}

long Starvector::addPlanet(){
	Planet * new_planet = new Planet();
	planets->insert(planets->size(), new_planet);
	return planets->read(planets->size() - 1)->getID();
}

bool Starvector::removePlanet(int id){
	return planets->remove(id);
}

Planet * Starvector::getPlanet(int id){
	return planets->read(id);
}

void Starvector::orbit(){
	for(unsigned int i = 0; i < planets->size(); i++){
		planets->read(i)->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "The star has " << this->getCurrentNumPlanets() << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < planets->size(); i++){
		std::cout << "Planet " << this->planets->read(i)->getType() << this->planets->read(i)->getID() << " is " <<this->planets->read(i)->getDistance() << " million miles away at position " << this->planets->read(i)->getPos() << " around the star." << std::endl;
      	}
}


// ====================STARLIST============================

Starlist::Starlist(){
  this->stars=new List();
}

Starlist::~Starlist(){
  int size=stars->size();
  int index=size-1;
  while(index>=0){
  //while(stars->read(index)!=NULL){
    //Planet * temp=stars->read(index+1);
    stars->remove(index);
    index--;
  }

}
long Starlist::addPlanet(){
	Planet * toAdd = new Planet(rand() % 3001);
	long id=toAdd->getID();
	stars->insert(stars->size(),toAdd);
	return id;
}

bool Starlist::removePlanet(long int id){
	//Planet * toRemove=id;
  bool ifFound=false;
	stars->reset();
	int index=0;
  while(stars->read(index) != NULL){
    if(stars->read(index)->getID()==id){
      stars->remove(index);
      ifFound=true;
      break;
    }
    //stars->next();
    index++;
  }
  return ifFound;
}

/*
	while(stars->current!=NULL){
		if(stars->current->data->getID()==id){
			stars->remove(index);
			return true;
		}
		stars->current=stars->current->next;
		index++;
	}
	return false;
}*/


Planet * Starlist::getPlanet(long id){
	stars->reset();
	int index=0;
  while(stars->read(index)!=NULL){
    if(stars->read(index)->getID()==id){
      return stars->read(index);
    }
    //stars->next();
    index++;
  }
  return NULL;
}

/*
	while(stars->current!=NULL){
		if(stars->current->data->getID()==id){
			return stars->read(index);
		}
		stars->current=stars->current->next;
		index++;
	}
	return NULL;
}
*/

void Starlist::orbit(){
	stars->reset();
  int index=0;
  while(stars->read(index)!=NULL){
    stars->read(index)->orbit();
    index++;
    //stars->next();
  }
  /*
	while(stars->current!=NULL){
		stars->current->data->orbit();
		stars->current=stars->current->next;
	}
  */

}

void Starlist:: printStarInfo(){
	stars->reset();
	std::cout << "The star has " << stars->size() << " planets." << std::endl;
  std::cout << "Planets:" << std::endl;
  for(unsigned i = 0; i <getCurrentNumPlanets(); i++){
		std::cout << "Planet " << stars->read(i)->getType() << stars->read(i)->getID() << " is " << stars->read(i)->getDistance()<< " million miles away at position " << stars->read(i)->getPos() << " around the star." << std::endl;
    //stars->next();
      }
}
unsigned int Starlist:: getCurrentNumPlanets(){
	return stars->size();
}
