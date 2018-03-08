/* File Name: project7.cpp
 * Author: Juan Martinez
 * Email Address: mart1316@pnw.edu
 * Assignment Number: Homework 4: Chapter 6, Question 2
 * Description: Program copies data from a file, then computes and transfers that data to a new file
 * Last Changed: March 4, 2018
 */

#include <iostream>
#include <fstream>
using namespace std;

void totalScore(ifstream& fin, ofstream& fout);
void names(ifstream& fin, ofstream& fout);

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

    names(fin, fout); //Calls a function to copy names and transfers them to an output-file
    totalScore(fin, fout); //Calls to compute scores and transfers data to an output-file

    fin.close();
    fout.close();

    cout << "Program completed."; //prints out statement when program completes tasks
    return 0;
}

void names(ifstream& fin, ofstream& fout) {
    //Copies the last name and first name from a file and transfers them to the output file
    string lastName, firstName;
    fin >> lastName >> firstName;
    fout << lastName << " " << firstName << " ";
}
 void totalScore(ifstream& fin, ofstream& fout) {
     //Copies the scores, adds them, finds the average score from the addition and transfers the data to the output file
     double score, totalSum = 0;
     int counter = 0;
     while(fin >> score) {
        fout << score << " ";
        totalSum += score;
        counter++;
     }
     fout << totalSum / counter << endl;
}