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

#include "CommonWelsh.h"
#include <cstdlib> // Include for rand()

const int MAX_TRUST_FACTOR = 50;
int trustFactor = 5;

CommonWelsh::CommonWelsh() : Dragon()
{
    firePower = (rand() % 50) + 10;
    nativeRange_ = "Wales";
    skinColor_ = "Green";
    restedHealth_ = (rand() % 96) + 5;
    currentHealth_ = restedHealth_;
    charisma_ = (rand() % 11) + 45;
}

void CommonWelsh::train(list<Dragon*>& listIn)
{
    firePower += trustFactor;
    trustFactor = (trustFactor > MAX_TRUST_FACTOR) ? (5) : (trustFactor + 5);
    if (firePower > MAX_FIRE_POWER)
    {
        firePower = 100;
    }
    Dragon::train(listIn);
}

void CommonWelsh::print()
{
    cout << "Common Welsh- ";
    Dragon::print();
}

void CommonWelsh::abstractMaker()
{
}
