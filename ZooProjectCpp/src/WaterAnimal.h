/*
 * WaterAnimal.h
 * WaterAnimal is an AirWaterAnimal that lives in the water.
 *
 *  Created on: Mar 31, 2019
 *      Author: lucaspoon
 */

#ifndef WATERANIMAL_H_
#define WATERANIMAL_H_

#include "AirWaterAnimal.h"
#include <string>

class WaterAnimal : public AirWaterAnimal{
private:
	/**
	 * counter variable for naming animal.
	 */
	static int count;

	/**
	 * @return a generated name.
	 */
	std::string generateName();

public:
	static const std::string WATER_ANIMAL;

	/**
	 * Default constructor.
	 */
	WaterAnimal();

	/**
	 * Constructor with a name.
	 * @param name of animal.
	 */
	WaterAnimal(std::string name);

	/**
	 * Constructor for water animal with parameters.
	 * Water animals are never thirsty so thirsty is always set to false.
	 * @param name of animal.
	 * @param isHungry value of hungry.
	 * @param isAsleep value of sleep.
	 */
	WaterAnimal(std::string name, bool isHungry, bool isAsleep);

	/**
	 * Destructor of WaterAnimal.
	 */
	virtual ~WaterAnimal();

	/**
	 * @param isThirsty the value to set.
	 */
	void setIsThirsty(bool isThirsty) override;

	/**
	 * @return false water animal is never thirsty.
	 */
	bool getIsThirsty() override;

	/**
	 * Water animals cannot be forced to go to sleep.
	 */
	void setIsAsleep(bool isAsleep) override;

	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	std::string getAnimalType() override;
};

#endif /* WATERANIMAL_H_ */
