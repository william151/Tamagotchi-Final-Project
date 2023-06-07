# Tamagotchi-Final-Project
This is a recreation of the famous tamagotchi pet game! This was done as a final project for my University. 

Introduction:

Users may select, care for, and interact with a pet in the simple and engaging console-based Tamagotchi game. It was made using C++. Players may engage in a range of actions, including feeding, playing with, and lulling the pet to sleep, according to the game's straightforward game cycle. The objective of this article is to analyze the game's design and development process, with a focus on the use of object-oriented programming ideas and the structure of the code.
The Tamagotchi game was developed using the principles of object-oriented programming (OOP). With this approach, the emphasis is using classes and objects to represent actual things, like dogs, and their traits and behaviors. The concept of the game is based on a main Pet class, from which subclasses for other types of pets were developed. The Pet class must monitor the pet's health, including its levels of boredom, fatigue, and hunger. Derived classes like Cat, Dog, and Fish inherit the primary Pet class, but they override the methods to provide unique behaviors for each type of pet.

Instructions:
Compile and run the C++ program using a suitable compiler.

You will be presented with a menu to either create a new pet, load a saved pet, or exit.

After choosing the pet type, you will be able to give your pet a name.

When a pet is either loaded or given a name, base stats of 50 will be given to each pet if created or stats from the previous save will be loaded.

In the main loop, you have the options of either feeding, playing or putting your pet to sleep.

This will update their values accordingly to what you choose;

To exit the game, you can either select to save the game for future use or exit the program.


Differences Between the Final Implementation and the Plan:

During the final testing of the game, I noticed that some updates weren’t updating correctly and some updated too quick for the game to finish. I was able to find some of the errors but some errors are still lingering around the code that I wasn’t able to find. I also added the virtual void in the pets class in order to call the message that is chosen in main.

Classes:

Pet: This is a general-purpose pet's basic class. It controls the pet's condition, including how hungry, sleepy, and bored it is. The Pet class also has interaction methods that modify the state variables, such as feed(), play(), and sleep(). It also offers the nextHour() method, which modifies the pet's state data to account for the passing of time.

Cat: This is a cat-specific derived class that derives from the Pet class. The interaction methods (feed(), play(), and sleep()) are overridden by the Cat class to offer certain cat-specific behaviors and messages.

Dog: Another derived class that a dog that derives from the Pet class is this one. The Dog class extends the interaction routines to give certain behaviors and messages tailored to dogs, much like the Cat class does.

Fish: This derived class, which represents a fish, likewise descended from the Pet class. Like the other derived classes, the Fish class extends the interaction functions to offer certain fish-specific behaviors and messages.

 
