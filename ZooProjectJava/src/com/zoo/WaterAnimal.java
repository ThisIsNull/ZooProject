package com.zoo;

/**
 * WaterAnimal is an AirWaterAnimal that lives in the water.
 * @author lucaspoon
 *
 */
public class WaterAnimal extends AirWaterAnimal{

	// Used to name water animal.
	static int count = 0;
	public final static String WATER_ANIMAL = "WaterAnimal";

	/**
	 * Default constructor.
	 */
	public WaterAnimal(){
		this(WATER_ANIMAL+count);
		count++;
	}

	/**
	 * Constructor with a name.
	 * @param name of animal.
	 */
	public WaterAnimal(String name) {
		this(name, false, false);
	}
	
	/**
	 * Constructor for water animal with parameters.
	 * Water animals are never thirsty so thirsty is always set to false.
	 * @param name of animal.
	 * @param isHungry value of hungry.
	 * @param isAsleep value of sleep.
	 */
	public WaterAnimal(String name , boolean isHungry, boolean isAsleep){
		super(name, false, isHungry, isAsleep);
	}

	/**
	 * The water animal is never thirsty.
	 */
	@Override
	public void setIsThirsty(boolean isThirsty) {
		super.setIsThirsty(false);
		System.out.println("Water animals are never thirsty.");
	}
	
	/** 
	 * @return false water animal is never thirsty.
	 */
	@Override
	public boolean getIsThirsty() {
		if (super.getIsThirsty()) {
			super.setIsThirsty(false);
		}
		return super.getIsThirsty();
	}	
	
	/**
	 * Water animals cannot be forced to go to sleep.
	 */
	@Override
	public void setIsAsleep(boolean isAsleep) {
		System.out.println("Water animals cannot be put to sleep.");
	}
	
	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	@Override
	protected String getAnimalType() {
		return WATER_ANIMAL;
	}
	
	
}
