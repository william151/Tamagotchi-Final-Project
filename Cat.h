#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#include "Pets.h"


class Cat : public Pet {
public:
    Cat(string name) : Pet(name) {}

    void play() override {
        Pet::play();
        cout << "___________________________________________________________" << endl;
        cout << "Meow! " << name << " enjoyed playing! Boredom updated" << endl;
        cout << "-----------------------------------------------------------" << endl;
        hunger -= 20;
        boredom -= 15;
    }
    void feed() override {
        Pet::feed();
        cout << "_______________________________________________________________________" << endl;
        cout << "Meow! " << name << " Really enjoyed the salmon! Hunger updated" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        hunger += 10;
        boredom -= 5;
    }

    void sleep() override {
        Pet::sleep();
        cout << "_____________________________________________________________" << endl;
        cout << "MeowZ! " << name << " enjoyed napping! Sleepiness updated" << endl;
        cout << "-------------------------------------------------------------" << endl;
        boredom -= 10;
        sleepiness -= 15;
        hunger -= 5;
    }
};

#endif