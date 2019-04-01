/*
 * Zoo.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#include "Zoo.h"
#include <iostream>
using namespace std;

Zoo::Zoo() {
	_animals.clear();
}

void Zoo::addAnimal(Animal* animal) {
	_animals.push_back(animal);
}

vector< Animal* > Zoo::getAllAnimals(){
	return _animals;
}

Animal* Zoo::getAnimalById(int animalId) {
	return _animals.at(animalId);
}

void Zoo::printAnimals() {
	cout << "\nAnimals in the Zoo:" << endl;
	int i = 0;
	for(Animal* animal : _animals) {
		cout << "ID: " << i << ", " << *animal << endl;
		i++;
	}
}

int Zoo::getAnimalCount() {
	return _animals.size();
}

Zoo::~Zoo() {
	for(Animal* animal : _animals) {
		delete animal;
	}
	_animals.clear();
}

