/*
 * AirWaterAnimal.h
 * AirWaterAnimal is an animal that is an air breather and a water animal.
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#ifndef AIRWATERANIMAL_H_
#define AIRWATERANIMAL_H_

#include "Animal.h"
#include <string>


class AirWaterAnimal : public Animal{

private:
	/**
	 * count variable for naming animals.
	 */
	static int count;
	/**
	 * @return a generated name.
	 */
	std::string generateName();

public:
	static const std::string AIR_WATER_ANIMAL;

	/**
	 * Default constructor.
	 */
	AirWaterAnimal();

	/**
	 * Constructor given a name.
	 * @param name of animal.
	 */
	AirWaterAnimal(std::string name);

	/**
	 * AirWaterAnimal constructor with provided parameters.
	 * @param name of the animal.
	 * @param isThirsty value of thirsty.
	 * @param isHungry value of hungry.
	 * @param isAsleep value if asleep.
	 */
	AirWaterAnimal(std::string name, bool isThirsty, bool isHungry, bool isAsleep);
	virtual ~AirWaterAnimal();

	/**
	 * This overrides the set method in Animal.
	 * @param isThirsty the value to set.
	 */
	virtual void setIsThirsty(bool isThirsty) override;

	/**
	 * This overrides the set method in Animal.
	 * @param isAsleep the value to set.
	 */
	virtual void setIsAsleep(bool isAsleep) override;

	/**
	 * Gets type of animal.
	 * This overrides the set method in Animal.
	 * @return animal type.
	 */
	virtual std::string getAnimalType() override;

};

#endif /* AIRWATERANIMAL_H_ */
