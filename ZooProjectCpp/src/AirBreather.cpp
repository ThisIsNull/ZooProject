/*
 * AirBreather.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#include "AirBreather.h"
#include <iostream>
using namespace std;

int AirBreather::count = 0;
const string AirBreather::AIR_BREATHER = "AirBreather";

AirBreather::AirBreather() : AirWaterAnimal(generateName(),false,false,false){}

AirBreather::AirBreather(string name) : AirWaterAnimal(name, false, false, false){}

AirBreather::AirBreather(string name, bool isThirsty, bool isHungry, bool isAsleep) : AirWaterAnimal(name, isThirsty, isHungry, isAsleep){}

string AirBreather::generateName(){
	string name = AIR_BREATHER;
	name.append(to_string(count));
	count++;
	return name;
}

string AirBreather::getAnimalType() {
	return AIR_BREATHER;
}

AirBreather::~AirBreather() {}

