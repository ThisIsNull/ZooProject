/*
 * WaterAnimal.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#include "WaterAnimal.h"
#include <iostream>
using namespace std;

int WaterAnimal::count = 0;
const string WaterAnimal::WATER_ANIMAL = "WaterAnimal";

WaterAnimal::WaterAnimal() : AirWaterAnimal(generateName(),false,false,false){}

WaterAnimal::WaterAnimal(string name) : AirWaterAnimal(name, false, false, false){}

WaterAnimal::WaterAnimal(string name, bool isHungry, bool isAsleep) : AirWaterAnimal(name, false, isHungry, isAsleep){}

string WaterAnimal::generateName(){
	string name = WATER_ANIMAL;
	name.append(to_string(count));
	count++;
	return name;
}

void WaterAnimal::setIsThirsty(bool isThirsty) {
	AirWaterAnimal::setIsThirsty(false);
	cout << "Water animals are never thirsty." << endl;
}

bool WaterAnimal::getIsThirsty() {
	return false;
}

void WaterAnimal::setIsAsleep(bool isAsleep) {
	cout << "Water animals cannot be put to sleep." << endl;
}

string WaterAnimal::getAnimalType() {
	return WATER_ANIMAL;
}

WaterAnimal::~WaterAnimal() {}

