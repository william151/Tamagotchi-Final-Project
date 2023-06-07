#ifndef PETS_H
#define PETS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


class Pet {
protected:
    string name;
    int hunger;
    int boredom;
    int sleepiness;

public:
    Pet(string name)
            : name(name), hunger(50), boredom(50), sleepiness(50) {}

    virtual void feed() {
        hunger -= 10;
        if (hunger < 0) hunger = 0;
    }

    virtual void play() {
        boredom -= 10;
        hunger += 5;
        if (boredom < 0) boredom = 0;
        if (hunger > 100) hunger = 100;
    }

    virtual void sleep() {
        sleepiness -= 10;
        hunger -= 10;
        if (sleepiness < 0) sleepiness = 0;
        if (hunger > 100) hunger = 100;
    }

    void nextHour() {
        hunger += 10;
        boredom += 10;
        sleepiness += 10;

        if (hunger > 100) hunger = 100;
        if (boredom > 100) boredom = 100;
        if (sleepiness > 100) sleepiness = 100;

        if (hunger < 0) hunger = 0;
        if (boredom < 0) boredom = 0;
        if (sleepiness < 0) sleepiness = 0;



        if (hunger <= 49) cout << name << " is hungry!" << endl;
        if (boredom <= 49) cout << name << " is not bored!" << endl;
        if (sleepiness <= 49) cout << name << " is not sleepy!" << endl;

        if (hunger >= 50) cout << name << " is currently full!" << endl;
        if (boredom >= 50) cout << name << " is bored!" << endl;
        if (sleepiness >= 50) cout << name << " is sleepy!" << endl;
    }

    void save(const string &filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << name << endl;
            outFile << hunger << endl;
            outFile << boredom << endl;
            outFile << sleepiness << endl;
            outFile.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    bool load(const string &filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            inFile >> name;
            inFile >> hunger;
            inFile >> boredom;
            inFile >> sleepiness;
            inFile.close();
            return true;
        } else {
            cout << "Unable to open file" << endl;
            return false;
        }
    }

    void printStatus() {
        cout << " ______________" << endl;
        cout << "| Name:      " << name  << " |" << endl;
        cout << "| Hunger:  " << hunger << " |" << endl;
        cout << "| Boredom: " << boredom << " |" << endl;
        cout << "| Sleepiness: " << sleepiness << "| " << endl;
        cout << " --------------" << endl;

    }

    string getName() const {
        return name;
    }

    bool isGameOver() const {
        return sleepiness == 0 || hunger == 0 || boredom == 0;
    }
};

#endif