package com.zoo;
import java.util.ArrayList;

/**
 * The Zoo class keeps track of its animals.
 * @author lucaspoon
 *
 */
public class Zoo {
	
	// List of all animals in the zoo.
	private ArrayList<Animal> animals;
	
	/**
	 * The default constructor for Zoo.
	 * Initializes the animals list.
	 */
	public Zoo() {
		this.animals = new ArrayList<Animal>();
	}
	
	/**
	 * Adds an animal to the zoo animal list.
	 * @param animal to add to zoo.
	 */
	protected void addAnimal(Animal animal) {
		this.animals.add(animal);
	}
	
	/**
	 * Gets a list of all animals that are in the zoo.
	 * @return the list of animals.
	 */
	protected ArrayList<Animal> getAllAnimals(){
		return this.animals;
	}
	
	/**
	 * Gets the animal that is specified by the id.
	 * @param id This is the id of the animal which corresponds to the index in the animal list.
	 * @return the animal specified in the array list.
	 */
	protected Animal getAnimalById(int id) {
		return this.animals.get(id);
	}
	
	/**
	 * Prints all of the animals in the Zoo.
	 */
	protected void printAnimals() {
		System.out.println("\nAnimals in the Zoo:");
		int i = 0;
		for(Animal animal : this.animals) {
			System.out.println("ID: " + i + ", " + animal.toString());
			i++;
		}
	}
	
	/**
	 * Gets a total count of all the animals in the zoo.
	 * @return the count of animals in the zoo.
	 */
	protected int getAnimalCount() {
		return this.animals.size();
	}

}
