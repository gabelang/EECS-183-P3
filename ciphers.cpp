/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Gabriel Lang and Alex DiGennaro
 * gabelang and adigenna
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * ciphers implements all cipher funcs to encrypt/decrypt messages at request.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;


void ciphers() {
    string cipherChoice;
    string Caesar;
    string Vigenere;
    string Polybius;
    int key;
    string keyword;
    string encryptChoice;
    string message;
    char grid[SIZE][SIZE];
    string encrypted;
    string decrypted;

    // asks user for a cipher (Caesar, Vigenere, or Polybius)
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherChoice);
    cipherChoice = toUpperCase(cipherChoice);

    // checks if cipher choice is valid or if it is invalid
    if (cipherChoice != "CAESAR" && cipherChoice != "C" && cipherChoice !=
        "VIGENERE" && cipherChoice != "V" && cipherChoice != "POLYBIUS" && cipherChoice
        != "P") {
        cout << "Invalid cipher!" << endl;
        return;
    }

    cout << "Encrypt or decrypt: ";
    getline(cin, encryptChoice);
    encryptChoice = toUpperCase(encryptChoice);

    // checks if encryption choice is valid or invalid
    if (encryptChoice != "ENCRYPT" && encryptChoice != "E" && encryptChoice !=
        "DECRYPT" && encryptChoice != "D") {
        cout << "Invalid mode!" << endl;
        return;
    }

    // implements if caesar cipher and encrypt are chosen
    if ((cipherChoice == "CAESAR" || cipherChoice == "C") && (encryptChoice ==
                                                              "ENCRYPT" || encryptChoice == "E")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        cin >> key;
        encrypted = caesarCipher(message, key, true);
        cout << "The encrypted message is: " << encrypted << endl;
    }

    // implements if caesar cipher and decrypt are chosen
    else if ((cipherChoice == "CAESAR" || cipherChoice == "C") &&
             (encryptChoice == "DECRYPT" || encryptChoice == "D")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        cin >> key;
        decrypted = caesarCipher(message, key, false);
        cout << "The decrypted message is: " << decrypted << endl;
    }

    // implements if vigenere cipher and encrypt are chosen
    else if ((cipherChoice == "VIGENERE" || cipherChoice == "V") &&
             (encryptChoice == "ENCRYPT" || encryptChoice == "E")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        
        // checks to see if the inputted key is valid or invalid
        for (int i = 0; i < keyword.size(); i++) {
            keyword = toUpperCase(keyword);
            if (keyword[i] >= 'A' && keyword[i] <= 'Z') {
                break;
            }
            else if (i == keyword.size() - 1) {
                cout << "Invalid key!" << endl;
                return;
            }
        }
        encrypted = vigenereCipher(message, keyword, true);
        cout << "The encrypted message is: " << encrypted << endl;
    }
    
    // implements if caesar vigenere and decrypt are chosen
    else if ((cipherChoice == "VIGENERE" || cipherChoice == "V") &&
             (encryptChoice == "DECRYPT" || encryptChoice == "D")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        
        // checks to see if inputted key is valid or invalid
        for (int i = 0; i < keyword.size(); i++) {
            keyword = toUpperCase(keyword);
            if (keyword[i] >= 'A' && keyword[i] <= 'Z') {
                break;
            }
            else if (i == keyword.size() - 1) {
                cout << "Invalid key!" << endl;
                return;
            }
        }
        decrypted = vigenereCipher(message, keyword, false);
        cout << "The decrypted message is: " << decrypted << endl;
    }

    // implements if polybius cipher and encrypt are chosen
    else if ((cipherChoice == "POLYBIUS" || cipherChoice == "P") &&
             (encryptChoice == "ENCRYPT" || encryptChoice == "E")) {
        cout << "Enter a message: " << endl;
        getline(cin, message);
        message = toUpperCase(message);
        
        // checks to see if inputted message is valid or invalid
        for (int i = 0; i < message.size(); i++) {
            if ((message[i] >= 'A' && message[i] <= 'Z') && (message[i] >= '0'
                                                             && message[i] <= '9')) {
                break;
            }
            else if(i == message.size() - 1){
                cout << "Invalid message!" << endl;
                return;
            }
        }
        cout << "What is your key: ";
        getline(cin, keyword);
        keyword = toUpperCase(keyword);
        keyword = removeDuplicate(keyword);
        
        // checks to see if inputted key is valid or invalid
        for (int i = 0; i < keyword.size(); i++) {
            if ((keyword[i] >= 'A' && keyword[i] <= 'Z') || (keyword[i] >= '0'
                                                             && keyword[i] <= '9') || (keyword[i] == ' ')) {
                break;
            }
            else if (i == keyword.size() - 1) {
                cout << "Invalid key!" << endl;
                return;
            }
        }
        encrypted = polybiusSquare(grid, keyword, message, true);
        cout << "The encrypted message is: " << encrypted << endl;
    }
    
    // implements if polybius cipher and decrypt are chosen
    else if ((cipherChoice == "POLYBIUS" || cipherChoice == "P") &&
             (encryptChoice == "DECRYPT" || encryptChoice == "D")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        
        // checks to see if inputted key is valid or invalid
        for (int i = 0; i < keyword.size(); i++) {
            keyword = toUpperCase(keyword);
            if ((keyword[i] >= 'A' && keyword[i] <= 'Z') || (keyword[i] >= '0'
                                                             && keyword[i] <= '9')) {
                break;
            }
            else if (i == keyword.size() - 1) {
                cout << "Invalid key!" << endl;
                return;
            }
        }
        decrypted = polybiusSquare(grid, keyword, message, false);
        cout << "The decrypted message is: " << decrypted << endl;
    }
}

