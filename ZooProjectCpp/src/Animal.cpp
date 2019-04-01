/*
 * Animal.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#include "Animal.h"
#include <iostream>
using namespace std;

int Animal::count = 0;
const string Animal::ANIMAL = "Animal";

Animal::Animal(){
	string name = ANIMAL;
	name.append(to_string(count));
	Animal::init(name, false, false, false);
	count++;
}

Animal::Animal(string name) {
	Animal::init(name, false, false, false);
}

Animal::Animal(string name, bool isThirsty, bool isHungry, bool isAsleep){
	Animal::init(name, isThirsty, isHungry, isAsleep);
}

void Animal::init(string name, bool isThirsty, bool isHungry, bool isAsleep){
	_animalName = name;
	_isThirsty = isThirsty;
	_isHungry = isHungry;
	_isAsleep = isAsleep;
}

string Animal::getAnimalName() { return _animalName; }

void Animal::setAnimalName(string animalName) { _animalName = animalName; }

bool Animal::getIsThirsty() { return _isThirsty; }

void Animal::setIsThirsty(bool isThirsty) { _isThirsty = isThirsty; }

bool Animal::getIsHungry() { return _isHungry; }

void Animal::setIsHungry(bool isHungry) { _isHungry = isHungry; }

bool Animal::getIsAsleep() { return _isAsleep; }

void Animal::setIsAsleep(bool isAsleep) { _isAsleep = isAsleep; }

void Animal::feed() {
	setIsHungry(false);
}

void Animal::giveWater() {
	setIsThirsty(false);
}

void Animal::putToSleep() {
	setIsAsleep(true);
}

string Animal::getAnimalType() {
	return ANIMAL;
}

std::ostream& operator<<(std::ostream &strm, Animal &a){
	return strm << "Type: " << a.getAnimalType() <<
			", Name: " << a.getAnimalName() <<
			", Thirsty: " << a.getIsThirsty() <<
			", Hungry: " << a.getIsHungry() <<
			", Sleeping: " << a.getIsAsleep();
}

Animal::~Animal() {}

