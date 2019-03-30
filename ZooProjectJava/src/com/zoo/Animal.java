package com.zoo;

/**
 * Animal class that keeps track of its name, thirsty, hungry, sleep values.
 * @author lucaspoon
 *
 */
public class Animal {
	
	// Used to name the animal if no name is given.
	private static int count = 0;
	public static final String ANIMAL = "Animal";
	
	// Private values for animal.
	private String animalName;
	private boolean isThirsty;
	private boolean isHungry;
	private boolean isAsleep;
	
	/**
	 * Default constructor of animal. The default name is ANIMAL#.
	 */
	public Animal() {
		this(ANIMAL+count);
		count++;
	}
	
	/**
	 * Constructor for creating animal with provided name.
	 * @param name of animal
	 */
	public Animal(String name) {
		this(name, false, false, false);
	}
	
	/**
	 * Constructor of animal with parameters.
	 * @param name is the name of the animal.
	 * @param isThirsty true if animal is thirsty.
	 * @param isHungry true if animal is hungry.
	 * @param isAsleep true if animal is asleep.
	 */
	public Animal(String name, boolean isThirsty, boolean isHungry, boolean isAsleep){
		this.animalName = name;
		this.isThirsty = isThirsty;
		this.isHungry = isHungry;
		this.isAsleep = isAsleep;
	}
	
	/**
	 * @return the animalName
	 */
	public String getAnimalName() {
		return this.animalName;
	}

	/**
	 * @param animalName the animal name to set.
	 */
	protected void setAnimalName(String animalName) {
		this.animalName = animalName;
	}
	
	/**
	 * @return isThirsty
	 */
	public boolean getIsThirsty() {
		return this.isThirsty;
	}

	/**
	 * @param isThirsty the value to set.
	 */
	protected void setIsThirsty(boolean isThirsty) {
		this.isThirsty = isThirsty;
	}

	/**
	 * @return isHungry
	 */
	public boolean getIsHungry() {
		return this.isHungry;
	}

	/**
	 * @param isHungry the value to set.
	 */
	protected void setIsHungry(boolean isHungry) {
		this.isHungry = isHungry;
	}

	/**
	 * @return isAsleep
	 */
	public boolean getIsAsleep() {
		return isAsleep;
	}

	/**
	 * @param isAsleep the value to set.
	 */
	protected void setIsAsleep(boolean isAsleep) {
		this.isAsleep = isAsleep;
	}
	
	/**
	 * Feeds the animal and sets isHungry to false.
	 */
	protected void feed() {
		setIsHungry(false);
	}
	
	/**
	 * Gives water to animal and sets isThirsty to false.
	 */
	protected void giveWater() {
		setIsThirsty(false);
	}
	
	/**
	 * Puts animal to sleep and sets isAsleep to true.
	 */
	protected void putToSleep() {
		setIsAsleep(true);
	}
	
	/**
	 * Gets type of animal.
	 * @return animal type.
	 */
	protected String getAnimalType() {
		return ANIMAL;
	}
	
	/**
	 * @return the string of an animal which has the name, thirsty, hungry, and sleep values.
	 */
	@Override
	public String toString() {
		return String.format("Type: %s, Name: %s, Thirsty: %b, Hungry: %b, Sleeping: %b", 
			getAnimalType(), getAnimalName(), getIsThirsty(), getIsHungry(), getIsAsleep());
	}

}
