package com.zoo;

/**
 * AirBreather is an AirWaterAnimal that breathes air.
 * @author lucaspoon
 *
 */
public class AirBreather extends AirWaterAnimal{
	
	// Used to name airbreather animal.
	static int count = 0;
	public final static String AIR_BREATHER = "AirBreather";
	
	/**
	 *  Default constructor.
	 */
	public AirBreather(){
		this(AIR_BREATHER+count);
		count++;
	}

	/**
	 * Constructor with name.
	 * @param name of animal.
	 */
	public AirBreather(String name) {
		this(name, false, false, false);
	}
	
	/**
	 * Constructor of AirBreather with provided parameters.
	 * @param name of animal.
	 * @param isThirsty value of thirsty.
	 * @param isHungry value of hungry.
	 * @param isAsleep value of asleep.
	 */
	public AirBreather(String name, boolean isThirsty, boolean isHungry, boolean isAsleep){
		super(name, isThirsty, isHungry, isAsleep);
	}
	
	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	@Override
	protected String getAnimalType() {
		return AIR_BREATHER;
	}

}
