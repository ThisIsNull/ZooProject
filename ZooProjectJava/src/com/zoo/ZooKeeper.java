package com.zoo;
import java.util.Scanner;

/**
 * The ZooKeeper class is created for a Zoo. The zooKeeper can perform different commands in the zoo.
 * @author lucaspoon
 *
 */
public class ZooKeeper {

	protected static final String CMD_EXIT = "exit";
	protected static final String CMD_FEED = "feed";
	protected static final String CMD_WATER = "water";
	protected static final String CMD_SLEEP = "sleep";
	protected static final String CMD_HELP = "help";
	protected static final String CMD_SHOW = "show";
	protected static final String CMD_ERROR = "error";
	
	private Zoo zoo;

	/**
	 * The ZooKeeper constructor creates a zookeeper for a zoo.
	 * @param zoo is the specific zoo that zookeeper is working at.
	 */
	public ZooKeeper(Zoo zoo) {
		this.zoo = zoo;
	}
	
	/**
	 * Give food to an animal.
	 * @param animalId is the id of the animal.
	 */
	private void giveFoodToAnimal(int animalId) {
		System.out.println("Feeding food to Animal: " + animalId);
		Animal animal = zoo.getAnimalById(animalId);
		animal.feed();
	}
	
	/**
	 * Give water to an animal.
	 * @param animalId is the id of the animal.
	 */
	private void giveWaterToAnimal(int animalId) {
		System.out.println("Giving water to Animal: " + animalId);
		Animal animal = zoo.getAnimalById(animalId);
		animal.giveWater();
	}
	
	/**
	 * Put animal to sleep.
	 * @param animalId is the id of the animal.
	 */
	private void putAnimalToSleep(int animalId) {
		System.out.println("Putting Animal to sleep: " + animalId);
		Animal animal = zoo.getAnimalById(animalId);
		animal.putToSleep();
	}
	
	/**
	 * Checks if there exists an animal with the id.
	 * @param id of the animal.
	 * @return true if animal exists, otherwise false.
	 */
	private boolean checkAnimalId(int id) {
		// Checking if the id is >= to the the total animals count.
		// The max id possible is the total animal count - 1.
		// Ex: if there are 3 animals then only id's 0,1,2 exist.
		if (id >= zoo.getAnimalCount()) {
	    	printCommandErrorMessage("There is no animal with ID: " + id);
	    	return false;
	    }
		return true;
	}
	
	/**
	 * Handles the command and prints error messages if needed.
	 * @param command the command to process.
	 * @return the command that was processed.
	 */
	private String handleCommand(String command) {
		String processedCommand = CMD_ERROR;
		// Trim extra white space off ends of string, change all letters to lower case, and split by space.
		String[] splitCmd = command.trim().toLowerCase().split("\\s+");
		
		if (splitCmd.length == 1) {
			// Command is less than 2 words.	
			processedCommand = splitCmd[0];
			switch(splitCmd[0]) {
				case CMD_EXIT:
					break;
				case CMD_HELP:
					printHelp();
					break;
				case CMD_SHOW:
					zoo.printAnimals();
					break;
				default:
					printCommandErrorMessage();
					processedCommand = CMD_ERROR;
					break;
			}
		} else if (splitCmd.length == 2){
			// Command is 2 words, should be a command word followed by an animal id
			// Ex: 'feed 2' feeds animal with id 2.
			int animalId;
			try {  
			    animalId = Integer.valueOf(splitCmd[1]);  
			    processedCommand = splitCmd[0];
			    switch(splitCmd[0]) {
					case CMD_FEED:
						if (checkAnimalId(animalId)) {
							giveFoodToAnimal(animalId);
							zoo.printAnimals();
						} else {
							processedCommand = CMD_ERROR;
						}
						break;
					case CMD_WATER:
						if (checkAnimalId(animalId)) {
							giveWaterToAnimal(animalId);
							zoo.printAnimals();
						} else {
							processedCommand = CMD_ERROR;
						}
						break;
					case CMD_SLEEP:
						if (checkAnimalId(animalId)) {
							putAnimalToSleep(animalId);
							zoo.printAnimals();
						} else {
							processedCommand = CMD_ERROR;
						}
						break;
					default:
						printCommandErrorMessage();
						processedCommand = CMD_ERROR;
						break;
			    }
			} catch(NumberFormatException e){  
				printCommandErrorMessage();
				processedCommand = CMD_ERROR;
			}  			
		} else {
			// Command has more than 2 words.
			printCommandErrorMessage();
			processedCommand = CMD_ERROR;
		}
		return processedCommand;
	}
	
	/**
	 * The default command error message.
	 */
	private void printCommandErrorMessage() {
		printCommandErrorMessage("The input command was in the wrong format.");
	}
	
	/**
	 * Print command error message.
	 * @param msg is the error message.
	 */
	private void printCommandErrorMessage(String msg) {
		System.out.println(msg + "\nTry again or type 'help'.");
	}

	/**
	 * Runs a continuous loop asking for commands.
	 */
	@SuppressWarnings("resource")
	protected void startWork() {
		boolean finished = false;
		Scanner sc = new Scanner(System.in);
		
		// Initial print of the zoo animals and help commands.
		zoo.printAnimals();
		printHelp();
		
		// Loops until command 'exit' is given.
		while (!finished) {
			System.out.println("\nPlease enter a command (or type 'help'):");
			String command = sc.nextLine();
			
			finished = (handleCommand(command).equals(CMD_EXIT));
		}
		
		System.out.println("Zoo is closing.");
		
	}
	
	/**
	 * Prints the valid commands.
	 */
	private void printHelp() {
		System.out.println("\nThese are the valid commands:");
		System.out.println("- 'help' Displays this list.");
		System.out.println("- 'show' Displays a list of animals in the Zoo.");
		System.out.println("- 'feed N' Gives food to one animal specified by the positive integer N.");
		System.out.println("- 'water N' Gives water to one animal specified by the positive integer N.");
		System.out.println("- 'sleep N' Puts one animal to sleep specified by the positive integer N. The Animal must be an AirBreather.");
		System.out.println("- 'exit' End this Zoo program.");
	}

}
