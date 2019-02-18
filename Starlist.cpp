#include "List.h"
#include "Star.h"

StarList::StarList(){
	this->stars=new List();
}

StarList::~StarList(){
	stars->reset();
	while(stars->current->next!=NULL){
		Node * temp=stars->current->next;
		delete stars->current->next;
		stars->current=temp;
	}
	delete stars->current;
}

long StarList::addPlanet(){
	Planet * toAdd = new Planet(rand() % 3001);
	long id=toAdd->getID();
	stars->insert(toAdd);
	return id;
}

bool StarList::removePlanet(long id){
	Planet * toRemove=id;
	stars->reset();
	int index=0;
	while(stars->current!=NULL){
		if(stars->current->data->getID()==id){
			stars->remove(index);
			return true;
		}
		stars->current=stars->current->next;
		index++;
	}
	return false;
}

Planet * StarList::getPlanet(long id){
	stars->reset();
	int index=0;
	while(stars->current!=NULL){
		if(stars->current->data->getID()==id){
			return stars->read(index);
		}
		stars->current=stars->current->next;
		index++;
	}
	return NULL;
}

void StarList::orbit(){
	stars->reset();
	while(stars->current!=NULL){
		stars->current->data->orbit();
		stars>current=stars->current->next;
	}
}

void StarList:: printStarInfo(){
	stars->reset();
	std::cout << "The star has " << stars->getCurrentNumPlanets() << " planets." << std::endl;
  std::cout << "Planets:" << std::endl;
  for(int i = 0; i <getCurrentNumPlanets(); i++){
		std::cout << "Planet " << stars->current->data->getType() << stars->current->data->getID() << " is " << stars->current->data->getDistance()<< " million miles away at position " << stars->current->data->getPos() << " around the star." << std::endl;
    stars->current=stars->current->next;
      }
}
unsigned int StarList:: getCurrentNumPlanets(){
	return stars->size();
}
};
