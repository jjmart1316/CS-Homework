/* File Name: project7.cpp
 * Author: Juan Martinez
 * Email Address: mart1316@pnw.edu
 * Assignment Number: Homework 4: Chapter 6, Question 2
 * Description: Program copies data from a file, then computes and transfers that data to a new file
 * Last Changed: March 14, 2018
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("grades.dat");
    if (fin.fail()) {
        //Prints an error if ifstream failed to open an input-file
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    fout.open("results.dat");
    if(fout.fail()) {
        //Prints an error if ofstream failed to open an output-file
        cout << "Output file opening failed." << endl;
        exit(1);
    }
    string lName, fName;
    int score, total;

    while(fin >> lName >> fName) {
        //Loop collects name's of students along with data
        cout << lName << " " << fName << " ";
        fout << lName << " " << fName << " ";
        score = 0; total = 0;
        for(int i = 0; i < 10; i++){
            //Loop collects scores from file, adds them together, and print the average score per student
            fin >> score;
            cout << score << " ";
            fout << score << " ";
            total += score;
        }
        cout << total / 10.0;
        fout << total / 10.0;
        cout << endl;
        fout << endl;
    }

    fin.close();
    fout.close();

    cout << "Program completed."; //prints out statement when program completes tasks
    return 0;
}