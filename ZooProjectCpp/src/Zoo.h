/*
 * Zoo.h
 * Keeps track of animals in the Zoo.
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#ifndef ZOO_H_
#define ZOO_H_

#include "Animal.h"
#include <iostream>
#include <vector>

class Zoo {

private:
	/**
	 * Container of all animals in the zoo.
	 */
	std::vector< Animal* > _animals;

public:
	/**
	 * The default constructor for Zoo.
	 */
	Zoo();

	/**
	 * Destructor for Zoo.
	 * Deletes all animals in the zoo.
	 */
	virtual ~Zoo();


	/**
	 * Adds an animal to the zoo animal list.
	 * @param animal to add to zoo.
	 */
	void addAnimal(Animal* animal);

	/**
	 * Gets a list of all animals that are in the zoo.
	 * @return the list of animals.
	 */
	std::vector< Animal* > getAllAnimals();

	/**
	 * Gets the animal that is specified by the id.
	 * @param id This is the id of the animal which corresponds to the index in the animal list.
	 * @return the animal specified in the array list.
	 */
	Animal* getAnimalById(int animalId);

	/**
	 * Prints all of the animals in the Zoo.
	 */
	void printAnimals();

	/**
	 * Gets a total count of all the animals in the zoo.
	 * @return the count of animals in the zoo.
	 */
	int getAnimalCount();
};

#endif /* ZOO_H_ */
