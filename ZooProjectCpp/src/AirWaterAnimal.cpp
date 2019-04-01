/*
 * AirWaterAnimal.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#include "AirWaterAnimal.h"
#include <iostream>
using namespace std;

int AirWaterAnimal::count = 0;
const string AirWaterAnimal::AIR_WATER_ANIMAL = "AirWaterAnimal";

AirWaterAnimal::AirWaterAnimal() : Animal(generateName(),false,false,false){}

AirWaterAnimal::AirWaterAnimal(string name) : Animal(name, false, false, false){}

AirWaterAnimal::AirWaterAnimal(string name, bool isThirsty, bool isHungry, bool isAsleep) :
		Animal(name, isThirsty, isHungry, isAsleep){}

string AirWaterAnimal::generateName(){
	string name = AIR_WATER_ANIMAL;
	name.append(to_string(count));
	count++;
	return name;
}

void AirWaterAnimal::setIsThirsty(bool isThirsty){
	Animal::setIsThirsty(isThirsty);
}

void AirWaterAnimal::setIsAsleep(bool isAsleep){
	Animal::setIsAsleep(isAsleep);
}

string AirWaterAnimal::getAnimalType() {
	return AIR_WATER_ANIMAL;
}

AirWaterAnimal::~AirWaterAnimal() {}

