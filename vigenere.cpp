/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Gabriel Lang and Alex DiGennaro
 * gabelang and adigenna
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * This file will code vigenere to shift message with alphanumbers in a keyword
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

using namespace std;
//string original;
void toUpperCase();
void removeNonAlphas();
void shiftAlphaCharacter();

// impliments the vigenere cipher
string vigenereCipher(string original, string keyword, bool encrypt) {
    string newKeyword;
    newKeyword = toUpperCase(keyword);
    newKeyword = removeNonAlphas(newKeyword);
    int positionInKeyword = 0;
    if (encrypt == true) {
        for (int i = 0; i < original.length(); i++) {
            if ((original[i] >= 'a' && original[i] <= 'z') || (original[i] >= 'A' &&
                                                               original[i] <= 'Z')) {
                original[i] = shiftAlphaCharacter(original[i], (newKeyword[positionInKeyword]
                                                                - 'A'));
                positionInKeyword = (positionInKeyword + 1) % newKeyword.length();
            }
        }
    }
    
    else if (encrypt == false) {
        for (int j = 0; j < original.length(); j++) {
            if ((original[j] >= 'a' && original[j] <= 'z') || (original[j] >= 'A' &&
                                                               original[j] <= 'Z')) {
            original[j] = shiftAlphaCharacter(original[j], (-1 *
                                                            newKeyword[positionInKeyword] - 'A'));
            positionInKeyword = (positionInKeyword + 1) % newKeyword.length();
            }
        }
    }
    return original;
}
