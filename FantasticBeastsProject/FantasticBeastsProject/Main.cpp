//
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
// <contains the 'main' function. Program execution begins and ends there.>
//
// Instructor: Jocelyn Richardt
// Assignment: <Project 2 - Linked List Usage (Dragon Game)>
// Student: <Ben Greene>
// Date: <3/21/2024>
//
// ---------------------------------------------------------------------------

#include <iostream>
#include <time.h>
#include "ChineseFireball.h"
#include "CommonWelsh.h"
#include "HungarianHorntail.h"
#include<list>

using namespace std;
Dragon* randomDragonConstructor();

int main()
{
		srand((unsigned int)time(NULL));
    list<Dragon*> dList;
    for (int i = 0; i < 3; i++) {
        dList.push_front(randomDragonConstructor());
    }

    cout << "Array populated." << endl;

    list<Dragon*>::iterator iter;
    string input;
    int indexIn;
    int iterIndex = 0;

    do {
        // Print dragon stats after menu cycle
        cout << "\nCurrent dragon stats:" << endl;
        for (iter = dList.begin(); iter != dList.end(); iter++) {
            cout << "index " << iterIndex << ": ";
            (*iter)->print();
            iterIndex++;
        }

        cout << "\nWould you like to train, recruit, or battle? Enter 'x' to exit" << endl;
        cin >> input;

        if (input == "train" || input == "Train") {
            cout << "Which dragon would you like to train? Enter the index" << endl;
            cin >> indexIn;
            if (indexIn >= 0 && indexIn < dList.size()) {
                iter = dList.begin();
                advance(iter, indexIn);
                (*iter)->train(dList);
            }
            else {
                cout << "Invalid index" << endl;
            }
        }
        else if (input == "recruit" || input == "Recruit") {
            cout << "Which dragon would you like to use to recruit? Enter the index" << endl;
            cin >> indexIn;
            if (indexIn >= 0 && indexIn < dList.size()) {
                iter = dList.begin();
                advance(iter, indexIn);
                (*iter)->recruit(dList);
            }
            else {
                cout << "Invalid index" << endl;
            }
        }
        else if (input == "battle" || input == "Battle") {
            cout << "Which dragon would you like use to battle? Enter the index" << endl;
            cin >> indexIn;
            if (indexIn >= 0 && indexIn < dList.size()) {
                iter = dList.begin();
                advance(iter, indexIn);
                Dragon* wildDragon = randomDragonConstructor();
                (*iter)->battle(dList, wildDragon, true);
            }
            else {
                cout << "Invalid index" << endl;
            }
        }
        else {
            if (input != "x") {
                cout << "Invalid input, try again" << endl;
            }
        }

        iterIndex = 0; // Reset the index for printing
    } while (input != "x");

    // Clean up memory by deleting dragons
    for (iter = dList.begin(); iter != dList.end(); iter++) {
        delete* iter;
    }

    cout << "Ending program" << endl;

    return 0;
}

Dragon* randomDragonConstructor() {
    int randDrag = rand() % 3;
    switch (randDrag) {
    case 0:
        return new HungarianHorntail();
    case 1:
        return new ChineseFireball();
    default:
        return new CommonWelsh();
    }
}
