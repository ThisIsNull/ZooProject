package com.zoo;


import static org.junit.Assert.assertNotNull;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * ZooKeeperTets class is for testing the ZooKeeper class.
 * @author lucaspoon
 *
 */
class ZooKeeperTest {
	
	private Zoo zoo;
	private ZooKeeper zooKeeper;
	
	/**
	 * Before each test, 
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
		
		zooKeeper = new ZooKeeper(zoo);
		assertNotNull(zooKeeper);
	}
	
	@Test
	void checkAnimalId_idOutOfRange_false() 
		throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		
		// Id of 3 does not exist in the zoo. Initial IDs are 0,1,2.
		int id = 3;
		
		Method method;
		method = zooKeeper.getClass().getDeclaredMethod("checkAnimalId", int.class);
		method.setAccessible(true);
		boolean isValid = (boolean) method.invoke(zooKeeper, id);
		assertFalse(isValid);
	}
	
	@Test
	void checkAnimalId_idInRange_true() 
		throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		
		// Id of 0 exists in zoo.
		int id = 0;
		
		Method method;
		method = zooKeeper.getClass().getDeclaredMethod("checkAnimalId", int.class);
		method.setAccessible(true);
		boolean isValid = (boolean) method.invoke(zooKeeper, id);
		assertTrue(isValid);
	}
	
	@Test
	void handleCommand_exit_valid() 
		throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		
		// This is the exit command.
		String command = ZooKeeper.CMD_EXIT;
		
		Method method;
		method = zooKeeper.getClass().getDeclaredMethod("handleCommand", String.class);
		method.setAccessible(true);
		String processedCommand = (String) method.invoke(zooKeeper, command);
		assertEquals(processedCommand, ZooKeeper.CMD_EXIT);
	}
	
	@Test
	void handleCommand_wrongCommand_inValid() 
		throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		
		// This is an invalid command.
		String command = "wrongCMD 99";
		
		Method method;
		method = zooKeeper.getClass().getDeclaredMethod("handleCommand", String.class);
		method.setAccessible(true);
		String processedCommand = (String) method.invoke(zooKeeper, command);
		assertEquals(processedCommand, ZooKeeper.CMD_ERROR);
	}
	
	@Test
	void handleCommand_feed_valid() 
		throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		
		// Valid feed command is 'feed 0' to feed animal with id 0.
		String command = ZooKeeper.CMD_FEED + " " + 0;
		
		Method method;
		method = zooKeeper.getClass().getDeclaredMethod("handleCommand", String.class);
		method.setAccessible(true);
		String processedCommand = (String) method.invoke(zooKeeper, command);
		assertEquals(processedCommand, ZooKeeper.CMD_FEED);
	}

}
