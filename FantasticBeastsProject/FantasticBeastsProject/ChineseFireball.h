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
// <initial construstor for chinesefireball and declares method to use>
//
// Instructor: Jocelyn Richardt
// Assignment: <Project 1 - OO Design & C++ Review (Dragon Classes)>
// Student: <Ben Greene>
// Date: <2/19/24>
//
// ---------------------------------------------------------------------------

#pragma once
#include "Dragon.h"

class ChineseFireball : public Dragon {
public:
    ChineseFireball();
    void train(std::list<Dragon*>& listIn) override;
    void print() override;
    void abstractMaker() override;
};


