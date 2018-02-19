/*
 * File Name: project6.cpp
 * Author: Juan
 * Email Address: XXXXXXXX
 * Assignment Number: Homework 3: Chapter 5, Question 4
 * Description: Program to compute coins to give out for any amount of change
 * Last Changed: February 9, 2018
 */

#include <iostream>
using namespace std;

//function declaration
void computeCoins(int& quarters, int& dimes, int& pennies);
void welcomeMessage();

int main() {
    char choice;
    int quarters, dimes, pennies;

    welcomeMessage();

    do{
        cout << "How many pennies? ";
        cin >> pennies;
        cout << pennies << " pennies can be given as" << endl;
        computeCoins(quarters, dimes, pennies);
        cout << quarters << " quarter(s) " << dimes << " dime(s) and " << pennies << " penny(pennies)" << endl;
        cout << endl;
        cout << "Run the program again? [Y/n]: ";
        cin >> choice;
        cout << endl;
    } while(tolower(choice) == 'y');
    return 0;
}
void welcomeMessage() {
    cout << "=======================================================================" << endl;
    cout << " This program will compute coins to give out from any amount of change " << endl;
    cout << "=======================================================================" << endl;
    return;
}
void computeCoins(int& quarters, int& dimes, int& pennies) {
    quarters = pennies / 25;
    pennies %= 25;
    dimes = pennies / 10;
    pennies %= 10;
    return;
}
