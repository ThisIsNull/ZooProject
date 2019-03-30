package com.zoo;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

/**
 * AnimalTest class is for testing the Animal class.
 * @author lucaspoon
 *
 */
class AnimalTest {

	/**
	 * Test animal created with default values.
	 */
	@Test
	void animal_createWithNoParameters_valid() {
		Animal animal = new Animal();
		String expectedName = Animal.ANIMAL+0;
		assertEquals(animal.getAnimalName(), expectedName);
		assertFalse(animal.getIsThirsty());
		assertFalse(animal.getIsHungry());
		assertFalse(animal.getIsAsleep());
	}
	
	/**
	 * Test animal created with custom values.
	 */
	@Test
	void animal_createWithParameters_valid() {
		final String name = "testName";
		final boolean thirsty = true;
		final boolean hungry = true;
		final boolean asleep = false;
		
		Animal animal = new Animal(name, thirsty, hungry, asleep);
		assertEquals(animal.getAnimalName(), name);
		assertTrue(animal.getIsThirsty());
		assertTrue(animal.getIsHungry());
		assertFalse(animal.getIsAsleep());
	}

}
