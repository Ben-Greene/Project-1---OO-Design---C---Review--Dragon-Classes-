// ---------------------------------------------------------------------------
//
// University of Wisconsin-Stout
// Mathematics, Statistics & Computer Science
// CS-244 Data Structures -- Spring 2024
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2024
//
// <FantasticBeastsProject>
//
// <Expresses how the methods of the .h file are to be executed and conplmetes the constructer initialization>
//
// Instructor: Jocelyn Richardt
// Assignment: <Project 1 - OO Design & C++ Review (Dragon Classes)>
// Student: <Ben Greene>
// Date: <2/19/24>
//
// ---------------------------------------------------------------------------
using namespace std;
#include "Dragon.h"
#include <cstdlib> 

Dragon::Dragon() {
    skinColor_ = "";
    nativeRange_ = "";
    firePower = 0;
    currentHealth_ = 0;
    restedHealth_ = 0;
    charisma_ = 0;
}

Dragon::~Dragon() {}

void Dragon::print() {
    cout << " Color: " << skinColor_ << "  Range: " << nativeRange_ << "  Firepower: " << firePower
        << "  Charisma: " << charisma_ << "  Health: " << currentHealth_ << endl;
}

void Dragon::train(list<Dragon*>& listIn) {
    currentHealth_ -= 20;
    if (rand() % 100 < 10) { // 10% chance of being attacked after training
        cout << "You are attacked by a wild dragon!" << endl;
        Dragon* wild1 = new Dragon();
        battle(listIn, wild1, false);
    }
    else {
        cout << "Training successful" << endl;
        currentHealth_ = restedHealth_;
        Dragon* copy = this;
        listIn.remove(this);
        listIn.push_back(copy);
    }
}

void Dragon::recruit(list<Dragon*>& listIn) {
    Dragon* wild1 = new Dragon(); 
    if (wild1->charisma_ < charisma_) {
        charisma_ += 5;
        if (charisma_ > 100) {
            charisma_ = 100;
        }
        listIn.push_back(wild1);
        cout << "Recruitment successful" << endl;
    }
    else {
        cout << "Recruitment unsuccessful, the wild dragon is attacking!" << endl;
        battle(listIn, wild1, false);
    }
}

void Dragon::battle(list<Dragon*>& listIn, Dragon* wild, bool chose) {
    bool battleEnd = false;
    if (!chose) {
        currentHealth_ -= wild->firePower;
    }

    while (currentHealth_ > 0 && wild->currentHealth_ > 0 && !battleEnd) {
        if (currentHealth_ <= 0) {
            cout << "Your dragon died" << endl;
            listIn.remove(this);
            battleEnd = true;
            break;
        }
        wild->currentHealth_ -= (rand() % 101) * firePower;
        if (wild->currentHealth_ <= 0) {
            wild->currentHealth_ = wild->restedHealth_;
            restedHealth_ += 10;
            currentHealth_ = restedHealth_;
            listIn.push_back(wild);
            Dragon* copy = this;
            listIn.remove(this);
            listIn.push_front(copy);
            cout << "You won the battle and recruited the new dragon" << endl;
            battleEnd = true;
            break;
        }
        currentHealth_ -= (rand() % 101) * wild->firePower;
    }
}

void Dragon::abstractMaker() {

}


