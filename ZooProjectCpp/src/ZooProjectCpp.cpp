//============================================================================
// Name        : ZooProjectCpp.cpp
// Author      : Lucas Poon
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Zoo.h"
#include "ZooKeeper.h"
#include "AirWaterAnimal.h"
#include "WaterAnimal.h"
#include "AirBreather.h"
#include <iostream>
using namespace std;

int main() {
	Zoo* zoo = new Zoo();
	ZooKeeper* zooKeeper = new ZooKeeper(zoo);

	// Create default animals in zoo.
	WaterAnimal* goldfish = new WaterAnimal("goldfish", true, false);
	AirBreather* tiger = new AirBreather("tiger", true, true, false);
	AirWaterAnimal* whale = new AirWaterAnimal("small whale", true, true, false);

	// Add animals to zoo.
	zoo->addAnimal(goldfish);
	zoo->addAnimal(tiger);
	zoo->addAnimal(whale);

	// ZooKeeper starts working (accepting commands).
	zooKeeper->startWork();

	// Delete objects.
	delete zooKeeper;
	delete zoo;

	return 0;
}
