/* File Name: homework5.cpp
 * Author: Juan Martinez
 * Email Address: mart1316@pnw.edu
 * Assignment Number: Homework 5: Chapter 7, Question 6
 * Description: Insertion sort: This program sorts an array in numerical order
 * Last Changed: March 4, 2018
 */

#include <iostream>
using namespace std;

//Algorithm to sort array in numerical order
void sort(int arr[], int size) {
    int i, x, j;
    for ( i = 1; i < size; i++) {
        x = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > x) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = x;
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
}

int main() {

    int arr[] = {8, 6, 10, 2, 16, 4, 18, 14, 12, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, size);// calls function to sort array in numerical order
    printArray(arr, size);//calls function to print array

    return 0;
}