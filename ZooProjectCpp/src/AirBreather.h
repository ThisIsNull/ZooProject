/*
 * AirBreather.h
 * AirBreather is an AirWaterAnimal that breathes air.
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#ifndef AIRBREATHER_H_
#define AIRBREATHER_H_

#include "AirWaterAnimal.h"
#include <string>

class AirBreather : public AirWaterAnimal {
private:
	/**
	 * count variable for naming animal.
	 */
	static int count;

	/**
	 * @return a generated name for animal.
	 */
	std::string generateName();

public:
	static const std::string AIR_BREATHER;

	/**
	 *  Default constructor.
	 */
	AirBreather();

	/**
	 * Constructor with name.
	 * @param name of animal.
	 */
	AirBreather(std::string name);

	/**
	 * Constructor of AirBreather with provided parameters.
	 * @param name of animal.
	 * @param isThirsty value of thirsty.
	 * @param isHungry value of hungry.
	 * @param isAsleep value of asleep.
	 */
	AirBreather(std::string name, bool isThirsty, bool isHungry, bool isAsleep);
	virtual ~AirBreather();

	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	std::string getAnimalType() override;
};

#endif /* AIRBREATHER_H_ */
