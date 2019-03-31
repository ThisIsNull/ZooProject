# Zoo Project

This project is an object oriented design of a zoo. The Zoo has a ZooKeeper and different Animals.

JavaDocs: TBD

## Prerequisites

```
Built with : Eclipse IDE for Java 
Version: 2018-12 (4.10.0)
Build id: 20181214-0600
```

```
Java version "1.8.0_191"
```

## Running the Program

### Run Program in Eclipse

In Eclipse, select the `ZooMain.java` file and from  the top toolbar `Run > Run As > Java Application`.
The  terminal output will display:

```
Animals in the Zoo:
ID: 0, Type: WaterAnimal, Name: goldfish, Thirsty: false, Hungry: true, Sleeping: false
ID: 1, Type: AirBreather, Name: tiger, Thirsty: true, Hungry: true, Sleeping: false
ID: 2, Type: AirWaterAnimal, Name:  small whale, Thirsty: true, Hungry: true, Sleeping: false

These are the valid commands:
- 'help' Displays this list.
- 'show' Displays a list of animals in the Zoo.
- 'feed N' Gives food to one animal specified by the positive integer N.
- 'water N' Gives water to one animal specified by the positive integer N.
- 'sleep N' Puts one animal to sleep specified by the positive integer N. The Animal must be an AirBreather.
- 'exit' End this Zoo program.

Please enter a command (or type 'help'):
```

### Run the JUnit tests

In Eclipse, select a test `*Test.java` file and from  the top toolbar `Run > Run As > JUnit Test`.

### Runnable Jar

In Eclipse, select from the top toolbar `File > Export > Java > Runnable Jar`.
* Launch Configuration: `ZooMain - ZooProjectJava`
* Select a location to save Jar and provide a filename.

Release Jars are located in `<path to ZooProject repo>/ZooProjectJava/releases-jar/`.

#### Run Jar in Terminal

`java -jar <path to ZooProject repo>/ZooProjectJava/releases-jar/Zoo-v1.jar`

## Generate Javadocs

This generates JavaDocs in Eclipse:
* Select the Java Project folder in the Package Explorer
* In the top toolbar select `Project > Generate Javadoc...`
* In "Select typesfor which Javadocwill be generated:" select the `ZooProjectJava` 
* In "Create Javadoc for members with visibility" select `Package`
* Choose a destination folder and click finish

JavaDocs are located in `<path to ZooProject repo>/docs`.

## Next Steps

* Add more commands for the ZooKeeper (Ex: adding animals, remove animals)
* Add more unit tests
* Add a GUI

## Authors

* **Lucas Poon** - *Initial work* - [ThisIsNull](https://github.com/ThisIsNull)

