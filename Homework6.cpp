/*
* File Name: Homework6.cpp
* Author: Juan Martinez
* Email Address: mart1316@pnw.edu
* Assignment Number: Homework 6: Chapter 8, Question 1
* Description: Program reads a sentence and outputs the sentence with correct spacing and capitalization
* Last Changed: April 11, 2018
*/

#include <iostream>
#include <string>
using namespace std;

void properCase(string& a);
//precondition: receives a string
//postcondition: string is modified to lower case and the initial character is capitalized
void removeLinebreak(string& a);
//precondition: receives a string
//postcondition: scans string for a line break and replaces the line break with a blank space
void removeDoubleBlanks(string& a);
//precondition: receives a string
//postcondition: scans string for double spaces and replaces them with one space
void trimEnds(string& a);
//precondition: receives a string
//postcondition: calls  leftTrim function() and rightTrim() to remove leading and trailing blank spaces
void leftTrim(string &a);
//precondition: receives a string
//postcondition: scans the leading end of a string for blank spaces and erases them
void rightTrim(string &a);
//precondition: receives a string
//postcondition: scans the trail end of a string for blank spaces and erases them

int main(){
    string input;

    do {
        cout << "Type a sentence of up to 100 characters and end it with a period: ";
        getline(cin, input, '.');
    } while (input.length() > 100);

    removeLinebreak(input);
    removeDoubleBlanks(input);
    trimEnds(input);
    properCase(input);
    input += ".";
    cout << input;
    return 0;
}

void trimEnds(string &a) {
    leftTrim(a);
    rightTrim(a);
}

void properCase(string &a) {
    a[0] = toupper(a[0]);
    for(int i = 1; i < a.length(); i++){
        a[i] = tolower(a[i]);
    }
}

void removeLinebreak(string &a) {
    int index = 0;
    while(index < a.length()){
        if(a[index] == '\n') {
            a[index] = ' ';
        } else {index++;}
    }
}

void removeDoubleBlanks(string &a) {
    while(a.find("  ") < a.length()) {
        a.erase(a.find("  "), 1);
    }
}

void leftTrim(string &a) {
    while(a.at(0) == ' '){
        a.erase(0,1);
    }
}

void rightTrim(string &a) {
    while(a.at(a.length()-1) == ' '){
        a.erase(a.length() - 1);
    }
}