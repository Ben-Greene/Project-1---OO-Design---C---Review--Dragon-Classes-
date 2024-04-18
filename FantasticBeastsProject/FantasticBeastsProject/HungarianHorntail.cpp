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

#include "HungarianHorntail.h"
#include <cstdlib> // For rand()

HungarianHorntail::HungarianHorntail() {
    firePower = rand() % 75 + 10;
    skinColor_ = "Black";
    nativeRange_ = "Hungary";
    restedHealth_ = rand() % 31 + 60;
    currentHealth_ = restedHealth_;
    charisma_ = rand() % 21 + 75;
}

void HungarianHorntail::train(list<Dragon*>& listIn) {
    firePower = (firePower < 20) ? (firePower + 5) : (firePower + (rand() % 26) + 15);
    if (firePower > MAX_FIRE_POWER) { firePower = 100; }
    Dragon::train(listIn);
}

void HungarianHorntail::print() {
    cout << "Hungarian Horntail- ";
    Dragon::print();
}

void HungarianHorntail::abstractMaker() {}



