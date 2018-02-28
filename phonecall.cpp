/*
 * File Name: phonecall.cpp
 * Author: Juan J. Martinez
 * Email Address: mart1316@pnw.edu
 * Assignment Number: Homework 2: Chapter 3, Question 1
 * Description: Program to compute the cost of a long-distance call
 */

#include <iostream>
using namespace std;

void info();
void days();

const double WEEKEND = 0.15;
const double BEFORE_8_AFTER_6 = 0.25;
const double BETWEEN_8_AND_6 = 0.40;

int main(){
    char choice, first, second;
    bool isValid;
    int sTime, minutes;
    double cost = 0;

    info(); //Prints information on what do program does

    do{

        isValid = false;
        while(!isValid) { //Loop set to false if first and second characters are not valid
            isValid = true;
            days();//Prints information on what characters are acceptable for the selected day
            cout << "[day]: ";
            cin >> first >> second;
            first = tolower(first);//Switch to lower case for convenience in conditional statements.
            second = tolower(second);//Switch to lower case for convenience in conditional statements.
            if (first == 'm' && second == 'o') {
                cout << "You typed Monday" << endl;
            } else if (first == 't' && second == 'u') {
                cout << "you typed Tuesday" << endl;
            } else if (first == 'w' && second == 'e') {
                cout << "you typed Wednesday" << endl;
            } else if (first == 't' && second == 'h') {
                cout << "you typed Thursday" << endl;
            } else if (first == 'f' && second == 'r') {
                cout << "You typed Friday" << endl;
            } else if (first == 's' && second == 'a') {
                cout << "You typed Saturday" << endl;
            } else if (first == 's' && second == 'u') {
                cout << "You typed Sunday" << endl;
            } else {
                //If first and second characters are not valid the boolean value is set to false for
                // the loop to run again
                cout << "That is not a valid day, please type the correct characters for the day." << endl;
                isValid = false;
            }
            cout << endl;
        }

        cout << "What time will the long-distance call start?" << endl;
        cout << "Time should be typed as military time [1:30 pm as 1330]" << endl;
        cout << "Starting time: ";
        cin >> sTime;
        cout << endl;
        cout << "how many minutes long will the long-distance call take?" << endl;
        cin >> minutes;

        bool isWeekend = (first == 's');//boolean used for convenience on conditional statements.

        if (!isWeekend) {
            if (sTime >= 800 && sTime <= 1800) {
                cost = minutes * BETWEEN_8_AND_6;
            } else {
                cost = minutes * BEFORE_8_AFTER_6;
            }
        } else {
            cost = minutes * WEEKEND;
        }

        cout << "The cost of the call is: $" << cost << endl;

        cout << "Would you like to run the program again?" << endl;
        cout << "[Y/n]: ";
        cin >> choice;
    } while(tolower(choice) == 'y');
    return 0;
}
void info(){
    cout << "============================================================" << endl;
    cout << " This program will compute the cost of a long-distance call" << endl;
    cout << " $0.40 per minute: Calls between 8:00 am - 6:00 pm" << endl;
    cout << " $0.25 per minute: Calls before 8:00 am or after 6:00 pm" << endl;
    cout << " $0.15 per minute: Calls on Saturday or Sunday" << endl;
    cout << "============================================================" << endl;
    cout << endl;
}
void days(){
    cout << "Type the day of the week the phone-call will be taking place" << endl;
    cout << "The day should be typed using only two characters [Mo, Tu, We, Th, Fr, Sa, Su]." << endl;
}