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
// <Impliments methods declared in the .h and specifies what they do>
//
// Instructor: Jocelyn Richardt
// Assignment: <Project 1 - OO Design & C++ Review (Dragon Classes)>
// Student: <Ben Greene>
// Date: <2/19/24>
//
// ---------------------------------------------------------------------------
using namespace std;

#include "ChineseFireball.h"
#include <cstdlib> // For rand()

ChineseFireball::ChineseFireball() {
    firePower = rand() % 50 + 50;
    nativeRange_ = "China";
    skinColor_ = "Scarlet";
    restedHealth_ = rand() % 36 + 50;
    currentHealth_ = restedHealth_;
    charisma_ = rand() % 31 + 25;
}

void ChineseFireball::train(std::list<Dragon*>& listIn) {
    firePower += rand() % 15 + 10;
    if (firePower > MAX_FIRE_POWER) { firePower = 100; }
    Dragon::train(listIn);
}

void ChineseFireball::print() {
    cout << "Chinese Fireball- ";
    Dragon::print();
}

void ChineseFireball::abstractMaker() {
}



