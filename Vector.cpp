#include "Planet.h"
#include "Vector.h"
#include <cstdlib>
#include <iostream>


Vector::Vector(){
	sizeV = 0;
	vector = NULL;
}

Vector::~Vector(){
	for(int i = 0; i < size; i++) delete vector[i];
	delete [] vector;
}

void Vector::insert(int index, Planet * p){
	if(vector == NULL){
		sizeV = index+1;
		vector = new Planet*[sizeV];
		Planet * new_planet = new Planet(rand() % 3001);
		vector[index] = new_planet;
		return;
	}
	if(index >= sizeV){
		Planet ** temp = new Planet*[index+1];
		for (int i = 0; i < sizeV; i++){
			temp[i] = vector[i];
		}
		delete vector[];
		Planet * new_planet = new Planet(rand() % 3001);
		vector[index] = new_planet;
		for (int i = sizeV; i < index; i++){
			vector[i] = N;
		}
		sizeV = index+1;
		return;
	}
	Planet ** temp = new Planet*[sizeV+1];
	for (int i = 0; i < index; i++){
		temp[i] = vector[i];
	}
	for (int j = index; j < sizeV; j++){
		temp[j+1] = vector[j];
	}
	delete[] vector;
	vector = temp;
	Planet * new_planet = new Planet(rand() % 3001);
	vector[index] = new_planet;
	sizeV++;
	return;
}

bool Vector::remove(int index){
	if(planets == NULL || getPlanet(planet_id) == NULL){
		return false;
	}
	Planet ** temp = new Planet*[sizeV-1];
	for (int i = 0; i < index; i++){
		temp[i] = vector[i];
	}
	for (int j = index + 1; j < sizeV; j++){
		temp[j-1] = vector[j];
	}
	delete vector[index];
	delete[] vector;
	vector = temp;
	sizeV--;
      	return true;
}

Planet * Vector::read(int index){
	if(vector == NULL){
		return NULL;
	}
	if(index >= sizeV) return NULL;
	return vector[index];
}
