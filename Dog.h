#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#include "Pets.h"


class Dog : public Pet {
public:
    Dog(string name) : Pet(name) {}

    void play () override {
        Pet::play();
        cout << "___________________________________________________________" << endl;
        cout << "Woof! " << name << " enjoyed playing! Boredom updated" << endl;
        cout << "-----------------------------------------------------------" << endl;
        hunger -= 20;
        boredom -= 15;
    }
    void feed() override {
        Pet::feed();
        cout << "_______________________________________________________________________" << endl;
        cout << "Woof! " << name << " Really enjoyed the Burger! Hunger updated" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        hunger += 10;
        boredom -= 5;
    }
    void sleep() override {
        Pet::sleep();
        cout << "_____________________________________________________________" << endl;
        cout << "Woof! " << name << " enjoyed napping! Sleepiness updated" << endl;
        cout << "-------------------------------------------------------------" << endl;
        boredom -= 10;
        sleepiness -= 15;
        hunger -= 5;
    }
};

#endif