#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

#include "Pets.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"


using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "** Tamagotchi Pet Game **" << endl;

    cout << "PLEASE READ ME" << endl;
    cout << "The goal of this is to not let your levels get to 0" << endl;
    cout << "Hunger has to be over 50 for pets to be happy!" << endl;
    cout << "Bordeom has to be less than 50 for pet to be happy!" << endl;
    cout << "Sleepiness has to be less than 50 for pet to not be sleepy!" << endl;

    Pet *pet = nullptr;
    string petName;
    int choice;

    while (true) {
        cout << "____________________________" << endl;
        cout << "| Please choose an option: |" << endl;
        cout << "| 1. Create a new pet      |"     << endl;
        cout << "| 2. Load an existing pet  |" << endl;
        cout << "| 3. Exit                  |" << endl;
        cout << "----------------------------" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << " ____________________" << endl;
            cout << "| Choose a pet type: |" << endl;
            cout << "| 1. Cat             |" << endl;
            cout << "| 2. Dog             |" << endl;
            cout << "| 3. Fish            |" << endl;
            cout << " --------------------" << endl;
            int petType;
            cin >> petType;

            cout << "Enter a name for your pet: ";
            cin >> petName;

            if (petType == 1) {
                pet = new Cat(petName);
            } else if (petType == 2) {
                pet = new Dog(petName);
            } else if (petType == 3) {
                pet = new Fish(petName);
            } else {
                cout << "Invalid pet type. Please try again." << endl;
                continue;
            }
            break;
        } else if (choice == 2) {
            cout << "Enter the filename to load your pet: ";
            string filename;
            cin >> filename;

            pet = new Pet("");
            if (pet->load(filename)) {
                cout << "Pet loaded successfully!" << endl;
                break;
            } else {
                delete pet;
                pet = nullptr;
                cout << "Failed to load pet. Please try again." << endl;
            }
        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
            return 0;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    while (true) {

        if (pet->isGameOver()) {
            cout << " _______________________________________________________________________" << endl;
            cout << "Game Over! " << pet->getName() << " is not doing well." << endl;
            cout << "Either your hunger reach 0, or boredom or sleepiness reached 100" << endl;
            cout << "-------------------------------------------------------------------------" << endl;

            break;
        }

        cout << endl << "Pet Status:" << endl;
        pet->printStatus();

        cout << " ___________________" << endl;
        cout << "| Choose an action: |" << endl;
        cout << "| 1. Feed           |" << endl;
        cout << "| 2. Play           |" << endl;
        cout << "| 3. Sleep          |" << endl;
        cout << "| 4. Save           |" << endl;
        cout << "| 5. Load           |" << endl;
        cout << "| 6. Exit           |" << endl;
        cout << " -------------------" << endl;

        cin >> choice;

        if (choice == 1) {
            pet->feed();
        } else if (choice == 2) {
            pet->play();
        } else if (choice == 3) {
            pet->sleep();
        } else if (choice == 4) {
            cout << "Enter the filename to save your pet: ";
            string filename;
            cin >> filename;
            pet->save(filename);
            cout << "Pet saved successfully!" << endl;
        } else if (choice == 5) {
            cout << "Enter the filename to load your pet: ";
            string filename;
            cin >> filename;
            if (pet->load(filename)) {
                cout << "Pet loaded successfully!" << endl;
            } else {
                cout << "Failed to load pet. Please try again." << endl;
            }
        } else if (choice == 6) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        pet->nextHour();

    }

    if (pet) {
        delete pet;
    }

    return 0;
}
