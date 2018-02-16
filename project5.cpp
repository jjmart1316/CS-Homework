/*
 * File Name: project5.cpp
 * Author: Juan J. Martinez
 * Email Address: mart1316@pnw.edu
 * Assignment Number: Homework 3: Chapter 4, Question 2
 * Description: Program to compute hat size, jacket size, and waist size
 * Last Changed: February 9, 2018
 * */

#include <iostream>
using namespace std;

//function declarations
void welcome();
void compute(double height, double weight, int age);
double computeHatSize(double weight, double height);
double computeJacketSize(double height, double weight, int age);
double computeWaist(double weight, int age);

int main() {
    double height, weight;
    int age;
    char input;

    welcome();//Prints a welcome message
    do{
        cout << endl;
        cout << "Height (inches): ";
        cin >> height;
        cout << "Weight (lbs): ";
        cin >> weight;
        cout << "age: ";
        cin >> age;

        compute(height, weight, age);//computes the collected information and prints the results

        cout << "Run program again [Y/n]: ";
        cin >> input;
    } while(tolower(input) == 'y');
    return 0;
}

void welcome(){
//prints information of tasks the program completes
    cout << endl;
    cout << "========================================================================" << endl;
    cout << " This program will calculate your hat size, jacket size, and waist size" << endl;
    cout << "========================================================================" << endl;
    return;
}
void compute(double height, double weight, int age) {
//prints out the results of data collected in main().
    cout << endl;
    cout << "Your hat size is: " << computeHatSize(weight, height) << endl;
    cout << "Your jacket size is: " << computeJacketSize(height, weight, age) << endl;
    cout << "Your waist size is: " << computeWaist(weight, age) << endl;
    cout << endl;
    return;
}
double computeHatSize(double weight, double height) {
    return (weight / height) * 2.9;
}
double computeJacketSize(double height, double weight, int age) {
//computes jacket size and adds 1/8 of an inch for every 10 years after 30
    double temp = 0, tempJacketSize = (height * weight) / 288;
    if ((age - 30) > 0) {
        temp = ((age - 30) / 10) * 0.125;
    }
    return tempJacketSize + temp;
}
double computeWaist(double weight, int age) {
//computes waist size and adds 1/10 of an inch for every two years after 28
    double temp = 0, tempWaist = weight / 5.7;
    if ((age - 28) > 0) {
        temp = ( (age - 28) / 2) * .1;
    }
    return tempWaist + temp;
}