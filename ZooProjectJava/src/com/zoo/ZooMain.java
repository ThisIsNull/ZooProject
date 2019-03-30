package com.zoo;

/**
 * The class ZooMain contains the main program of the Zoo.
 * @author lucaspoon
 *
 */
public class ZooMain {

	/**
	 * Main program to create and start the Zoo.
	 * @param args arguments for main method.
	 */
	public static void main(String[] args) {
		Zoo zoo = new Zoo();
		ZooKeeper zooKeeper = new ZooKeeper(zoo);
		
		// Create default animals in zoo.
		WaterAnimal goldfish = new WaterAnimal("goldfish", true, false);
		AirBreather tiger = new AirBreather("tiger", true, true, false);
		AirWaterAnimal whale = new AirWaterAnimal(" small whale", true, true, false);
				
		// Add animals to zoo.
		zoo.addAnimal(goldfish);
		zoo.addAnimal(tiger);
		zoo.addAnimal(whale);	
				
		zooKeeper.startWork();
	}

}
