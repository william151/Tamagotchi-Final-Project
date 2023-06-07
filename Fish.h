#ifndef FISH_H
#define FISH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#include "Pets.h"


class Fish : public Pet {
public:
    Fish(string name) : Pet(name) {}

    void play() override {
        Pet::play();
        cout << "___________________________________________________________" << endl;
        cout << "Blub Blub! " << name << " enjoyed playing! Boredom updated" << endl;
        cout << "-----------------------------------------------------------" << endl;
        hunger -= 20;
        boredom -= 15;
    }
    void feed() override {
        Pet::feed();
        cout << "_______________________________________________________________________" << endl;
        cout << "Blub Blub! " << name << " Really enjoyed the fish food! Hunger updated" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        hunger += 5;
    }
    void sleep() override {
        Pet::sleep();
        cout << "_____________________________________________________________" << endl;
        cout << "Blub Blub! " << name << " enjoyed napping! Sleepiness updated" << endl;
        cout << "-------------------------------------------------------------" << endl;
        boredom -= 10;
        sleepiness -= 15;
        hunger -= 5;
    }
};

#endif