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
// <Initializes Dragon object and assigns attributes>
//
// Instructor: Jocelyn Richardt
// Assignment: <Project 1 - OO Design & C++ Review (Dragon Classes)>
// Student: <Ben Greene>
// Date: <2/19/24>
//
// ---------------------------------------------------------------------------


#pragma once
#include <iostream>
#include <string>
#include <list>

class Dragon {
protected:
    std::string skinColor_;
    std::string nativeRange_;
    static const int MAX_FIRE_POWER = 100;
    int firePower;
    int currentHealth_;
    int restedHealth_;
    int charisma_;

public:
    virtual void print();
    virtual void train(std::list<Dragon*>& listIn);
    virtual void recruit(std::list<Dragon*>& listIn);
    virtual void battle(std::list<Dragon*>& listIn, Dragon* wild, bool chose);
    virtual void abstractMaker(); // Abstract method

    Dragon();
    virtual ~Dragon();
};

