/*
 * ZooKeeper.h
 * The ZooKeeper class is created for a Zoo. The zooKeeper can perform different commands in the zoo.
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#ifndef ZOOKEEPER_H_
#define ZOOKEEPER_H_

#include "Zoo.h"
#include <string>

class ZooKeeper {

private:
	Zoo* _zoo;

	/**
	 * Give food to an animal.
	 * @param animalId is the id of the animal.
	 */
	void giveFoodToAnimal(int animalId);

	/**
	 * Give water to an animal.
	 * @param animalId is the id of the animal.
	 */
	void giveWaterToAnimal(int animalId);

	/**
	 * Put animal to sleep.
	 * @param animalId is the id of the animal.
	 */
	void putAnimalToSleep(int animalId);

	/**
	 * Checks if there exists an animal with the id.
	 * @param id of the animal.
	 * @return true if animal exists, otherwise false.
	 */
	bool checkAnimalId(int animalId);

	/**
	 * Handles the command and prints error messages if needed.
	 * @param command the command to process.
	 * @return the command that was processed.
	 */
	std::string handleCommand(std::string command);

	/**
	 * The default command error message.
	 */
	void printCommandErrorMessage();

	/**
	 * Print command error message.
	 * @param msg is the error message.
	 */
	void printCommandErrorMessage(std::string msg);

	/**
	 * Prints the valid commands.
	 */
	void printHelp();

public:
	/**
	 * Constructor for ZooKeeper.
	 */
	ZooKeeper(Zoo* zoo);

	/**
	 * Destructor for ZooKeeper.
	 */
	virtual ~ZooKeeper();

	/**
	 * Runs a continuous loop asking for commands.
	 */
	void startWork();

protected:
	/**
	 * Commands for ZooKeeper.
	 */
	static const std::string CMD_EXIT;
	static const std::string CMD_FEED;
	static const std::string CMD_WATER;
	static const std::string CMD_SLEEP;
	static const std::string CMD_HELP;
	static const std::string CMD_SHOW;
	static const std::string CMD_ERROR;

};

#endif /* ZOOKEEPER_H_ */
