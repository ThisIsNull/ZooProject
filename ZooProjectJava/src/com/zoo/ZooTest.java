package com.zoo;
import static org.junit.Assert.assertNotNull;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

/**
 * ZooTest class is for testing the Zoo class.
 * @author lucaspoon
 *
 */
class ZooTest {

	private Zoo zoo;
	
	/**
	 * Before each test, create a new zoo and add 3 animals.
	 */
	@BeforeEach
	public void setup_zoo() {
		zoo = new Zoo();
		assertNotNull(zoo);
		
		// Create default animals in zoo.
		WaterAnimal goldfish = new WaterAnimal("goldfish", true, false);
		AirBreather tiger = new AirBreather("tiger", true, true, false);
		AirWaterAnimal whale = new AirWaterAnimal(" small whale", true, true, false);
				
		// Add animals to zoo.
		zoo.addAnimal(goldfish);
		zoo.addAnimal(tiger);
		zoo.addAnimal(whale);
	}
	
	/**
	 * Test method getAnimalCount().
	 */
	@Test
	public void getAnimalCount_countOfThreeAnimals_valid() {
		final int expectedResult = 3;
		int animalCount = zoo.getAnimalCount();
		assertEquals(animalCount, expectedResult);
	}
	
	/**
	 * Test getAnimalById(int).
	 */
	@Test
	public void getAnimalById_IdZeroIsGoldfish_valid() {
		Animal animal = zoo.getAnimalById(0);
		String expectedResult = "goldfish";
		assertEquals(animal.getAnimalName(), expectedResult);
	}
	
}
