/*
 * ZooKeeper.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#include "ZooKeeper.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const string ZooKeeper::CMD_EXIT = "exit";
const string ZooKeeper::CMD_FEED = "feed";
const string ZooKeeper::CMD_WATER = "water";
const string ZooKeeper::CMD_SLEEP = "sleep";
const string ZooKeeper::CMD_HELP = "help";
const string ZooKeeper::CMD_SHOW = "show";
const string ZooKeeper::CMD_ERROR = "error";

ZooKeeper::ZooKeeper(Zoo *zoo) {
	_zoo = zoo;
}

void ZooKeeper::giveFoodToAnimal(int animalId) {
	cout << "Feeding food to Animal: " << animalId << endl;
	Animal* animal = _zoo->getAnimalById(animalId);
	animal->feed();
}

void ZooKeeper::giveWaterToAnimal(int animalId) {
	cout << "Giving water to Animal: " << animalId << endl;
	Animal* animal = _zoo->getAnimalById(animalId);
	animal->giveWater();
}

void ZooKeeper::putAnimalToSleep(int animalId) {
	cout << "Putting Animal to sleep: " << animalId << endl;
	Animal* animal = _zoo->getAnimalById(animalId);
	animal->putToSleep();
}

bool ZooKeeper::checkAnimalId(int animalId) {
	// Checking if the id is >= to the the total animals count.
	// The max id possible is the total animal count - 1.
	// Ex: if there are 3 animals then only id's 0,1,2 exist.
	if (animalId >= _zoo->getAnimalCount()) {
		string msg = "There is no animal with ID: ";
		msg.append(to_string(animalId));
		printCommandErrorMessage(msg);
		return false;
	}
	return true;
}

string ZooKeeper::handleCommand(string command) {
	string processedCommand = CMD_ERROR;

	string buf;                 	// Buffer string
	stringstream ss(command);       // Insert the string into a stream
	vector<std::string> splitCmd; 	// Create vector to hold the words

	while (ss >> buf)
		splitCmd.push_back(buf);

	if (splitCmd.size() == 1) {
		// Command is less than 2 words.
		processedCommand = splitCmd[0];
		if (splitCmd[0] == CMD_HELP) {
			printHelp();
		} else if (splitCmd[0] == CMD_SHOW) {
			_zoo->printAnimals();
		} else if (splitCmd[0] != CMD_EXIT) {
			printCommandErrorMessage();
			processedCommand = CMD_ERROR;
		}
	} else if (splitCmd.size() == 2){
		// Command is 2 words, should be a command word followed by an animal id
		// Ex: 'feed 2' feeds animal with id 2.
		int animalId;
		try {
			animalId = stoi(splitCmd[1]);
			processedCommand = splitCmd[0];

			if (splitCmd[0] == CMD_FEED) {
				if (checkAnimalId(animalId)) {
					giveFoodToAnimal(animalId);
					_zoo->printAnimals();
				} else {
					processedCommand = CMD_ERROR;
				}
			} else if (splitCmd[0] == CMD_WATER) {
				if (checkAnimalId(animalId)) {
					giveWaterToAnimal(animalId);
					_zoo->printAnimals();
				} else {
					processedCommand = CMD_ERROR;
				}
			} else if (splitCmd[0] == CMD_SLEEP) {
				if (checkAnimalId(animalId)) {
					putAnimalToSleep(animalId);
					_zoo->printAnimals();
				} else {
					processedCommand = CMD_ERROR;
				}
			} else {
				printCommandErrorMessage();
				processedCommand = CMD_ERROR;
			}

		} catch (...) {
			printCommandErrorMessage();
			processedCommand = CMD_ERROR;
		}
	} else {
		// Command has more than 2 words.
		printCommandErrorMessage();
		processedCommand = CMD_ERROR;
	}
	return processedCommand;
}

void ZooKeeper::printCommandErrorMessage() {
	printCommandErrorMessage("The input command was in the wrong format.");
}

void ZooKeeper::printCommandErrorMessage(string msg) {
	cout << msg + "\nTry again or type 'help'." << endl;
}

void ZooKeeper::startWork() {
	bool finished = false;

	// Initial print of the zoo animals and help commands.
	_zoo->printAnimals();
	printHelp();

	// Loops until command 'exit' is given.
	while (!finished) {
		cout << "\nPlease enter a command (or type 'help'):"  << endl;
		string command;
		getline(cin, command);

		finished = (handleCommand(command) == CMD_EXIT);
	}

	cout << "Zoo is closing." << endl;

}

void ZooKeeper::printHelp() {
	cout << "\nThese are the valid commands:" <<
	"\n- 'help' Displays this list." <<
	"\n- 'show' Displays a list of animals in the Zoo." <<
	"\n- 'feed N' Gives food to one animal specified by the positive integer N." <<
	"\n- 'water N' Gives water to one animal specified by the positive integer N." <<
	"\n- 'sleep N' Puts one animal to sleep specified by the positive integer N. The Animal must be an AirBreather." <<
	"\n- 'exit' End this Zoo program." << endl;
}

ZooKeeper::~ZooKeeper() {}

