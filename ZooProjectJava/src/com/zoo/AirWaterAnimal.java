package com.zoo;

/**
 * AirWaterAnimal is an animal that is an air breather and a water animal.
 * @author lucaspoon
 *
 */
public class AirWaterAnimal extends Animal{
	
	// Used to name a airwater animal when no name is given.
	private static int count = 0;
	public static final String AIR_WATER_ANIMAL = "AirWaterAnimal";
	
	/**
	 * Default constructor of AirWaterAnimal.
	 */
	public AirWaterAnimal() {
		this(AIR_WATER_ANIMAL+count);
		count++;
	}
	
	/**
	 * Constructor with the name of animal.
	 * @param name of the animal.
	 */
	public AirWaterAnimal(String name) {
		this(name, false, false, false);
	}
	
	/**
	 * AirWaterAnimal constructor with provided parameters.
	 * @param name of the animal.
	 * @param isThirsty value of thirsty.
	 * @param isHungry value of hungry.
	 * @param isAsleep value if asleep.
	 */
	public AirWaterAnimal(String name, boolean isThirsty, boolean isHungry, boolean isAsleep){
		super(name, isThirsty, isHungry, isAsleep);
	}

	/**
	 * @param isThirsty the value to set.
	 */
	@Override
	public void setIsThirsty(boolean isThirsty) {
		super.setIsThirsty(isThirsty);
		
	}
	
	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	@Override
	protected String getAnimalType() {
		return AIR_WATER_ANIMAL;
	}

}
