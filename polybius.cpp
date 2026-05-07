/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Gabriel Lang and Alex DiGennaro
 * gabelang and adigenna
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * polybius.cpp swaps characters in string/grid; with cipher utilizing numbers.
 */


#include "polybius.h"
#include <string>
#include <iostream>
using namespace std;


// returns the key followed by remaining ALNUM chars without duplicates
string mixKey(string key) {
    string y = key + ALNUM;
    string x = removeDuplicate(y);
    return x;
}

// returns a 6x6 grid with content given by the string
void fillGrid(char grid[SIZE][SIZE], string content) {
    int i = 0;
    if (content.length() == 36) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                grid[row][col] = content.at(i);
                i += 1;
            }
        }
    }
   else if (content.length() != 36) {
       cout << "Invalid Message!" << endl;
   }
}

// locates a char in grid and returns its coordinates in the grid
string findInGrid(char c, char grid[SIZE][SIZE]) {
    string temp1;
    string temp2;
    int row;
    int col;
    int tempRow;
    int tempCol;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (c == grid[row][col]) {
                tempRow = row;
                tempCol = col;
                temp1 = to_string(tempRow);
                temp2 = to_string(tempCol);
                return temp1 + temp2;
            }
        }
    }
    return temp1 + temp2;
}

// impliments the polybius cipher
string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool
                      encrypt) {
    string newKey = toUpperCase(key);
    newKey = removeDuplicate(newKey);
    string newOriginal = toUpperCase(original);
    string encrypted = "";
    if (encrypt == true) {
        newKey = mixKey(newKey);
        fillGrid(grid, newKey);
        for (int i = 0; i < newOriginal.length(); i++) {
            if (newOriginal[i] == ' ') {
                encrypted = encrypted + " ";
            }
            else {
            encrypted = encrypted + findInGrid(newOriginal[i], grid);
            }
        }
        return encrypted;
    }
    
    else {
        newKey = mixKey(newKey);
        fillGrid(grid, newKey);
        char tempRow;
        char tempCol;
        string decrypted;
        for (int j = 0; j < newOriginal.length(); j = j + 2) {
            if (newOriginal[j] == ' ') {
                decrypted = decrypted + " ";
                j--;
            }
            else {
                tempRow = newOriginal[j];
                tempCol = newOriginal[j + 1];
                decrypted = decrypted + (newKey[(charToInt(tempRow) * 6) + charToInt(tempCol)]);
            }
        }
        return decrypted;
    }
}
