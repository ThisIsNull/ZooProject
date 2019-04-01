/*
 * Animal.h
 * Animal class that keeps track of its name, thirsty, hungry, sleep values.
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {

private:

	/**
	 * count variable for naming animal.
	 */
	static int count;

	/**
	 * Animal variables for name and states.
	 */
	std::string _animalName;
	bool _isThirsty;
	bool _isHungry;
	bool _isAsleep;

	/**
	 * Initializes the animal values.
	 * @param name is the name of the animal.
	 * @param isThirsty true if animal is thirsty.
	 * @param isHungry true if animal is hungry.
	 * @param isAsleep true if animal is asleep.
	 */
	void init(std::string name, bool isThirsty, bool isHungry, bool isAsleep);

public:
	static const std::string ANIMAL;

	/*
	 * Default constructor of animal. The default name is ANIMAL#.
	 */
	Animal();

	/**
	 * Constructor for creating animal with provided name.
	 * @param name of animal
	 */
	Animal(std::string name);

	/**
	 * Constructor of animal with parameters.
	 * @param name is the name of the animal.
	 * @param isThirsty true if animal is thirsty.
	 * @param isHungry true if animal is hungry.
	 * @param isAsleep true if animal is asleep.
	 */
	Animal(std::string name, bool isThirsty, bool isHungry, bool isAsleep);

	/**
	 * Destructor for Animal.
	 */
	virtual ~Animal();

	/**
	 * @return the animalName
	 */
	std::string getAnimalName();

	/**
	 * @param animalName the animal name to set.
	 */
	virtual void setAnimalName(std::string animalName);

	/**
	 * @return isThirsty
	 */
	virtual bool getIsThirsty();

	/**
	 * @param isThirsty the value to set.
	 */
	virtual void setIsThirsty(bool isThirsty);

	/**
	 * @return isHungry
	 */
	virtual bool getIsHungry();

	/**
	 * @param isHungry the value to set.
	 */
	virtual void setIsHungry(bool isHungry);

	/**
	 * @return isAsleep
	 */
	virtual bool getIsAsleep();

	/**
	 * @param isAsleep the value to set.
	 */
	virtual void setIsAsleep(bool isAsleep);

	/**
	 * Feeds the animal and sets isHungry to false.
	 */
	void feed();

	/**
	 * Gives water to animal and sets isThirsty to false.
	 */
	void giveWater();

	/**
	 * Puts animal to sleep and sets isAsleep to true.
	 */
	void putToSleep();

	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	virtual std::string getAnimalType();

	/**
	 * Overloads the  operator << for printing out the animal.
	 * @return the string of an animal which has the name, thirsty, hungry, and sleep values.
	 */
	friend std::ostream& operator<<(std::ostream &strm, Animal &a);

};

#endif /* ANIMAL_H_ */
