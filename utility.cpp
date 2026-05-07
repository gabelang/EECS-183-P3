/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Gabriel Lang and Alex DiGennaro
 * gabelang and adigenna
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * utility implements functions as helping functions to be used in other files.
 */

#include "utility.h"
#include <iostream>


// Return copy of original string but all alpha chars in caps
// Also, all other chars remain unchanged.
string toUpperCase(string original) {
    for(int i = 0; i < original.length(); i++) {
    original[i] = toupper(original[i]);
    }
    return original;
}

//returns a copy of string without non-alpha characters
string removeNonAlphas(string original) {
    string newString;
    for (int i = 0; i < original.length(); i++) {
        if ((original[i] >= 'a' && original[i] <= 'z') || (original[i] >= 'A'
                                                && original[i] <= 'Z')) {
            newString += original[i];
        }
    }
    return newString;
}

//removes 0-9 and A-Z duplicates from a string
string removeDuplicate(string original) {
    int i;
    int j;
    string modified = "";
    original = toUpperCase(original);
    for (i = 0; i < original.size(); i++) {
        for (j = 0; j < original.size(); j++) {
            if (original[i] == original[j]) {
                break;
            }
        }
        if (i == j) {
            modified += original[i];
        }
    }
    return modified;
}

// returns all char numbers 0-9 as their respective ints
int charToInt(char original) {
    int a;
    for (int i = 0; i != original; ++i) {
        
        if (i + 1 == original) {
            a = i + 1;
        }
    }
    return a - 48;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
