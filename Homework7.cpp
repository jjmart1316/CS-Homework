/* File Name: Homework7
 * Author: Juan Martinez
 * E-mail: mart1316@gmail.com
 * Description: Reverses a c-string
 */
#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char *a);
//precondition: Takes a cstring by their location
//postcondition: Reverses the string

int main() {

    char str[101];
    cout << "Type something: ";
    cin.getline(str, 101);
    reverseString(str);
    cout << str;
    return 0;
}

void reverseString(char *a) {
    typedef char* charPointer;
    charPointer pStart, pEnd;

    pStart = a;
    pEnd = a + strlen(a) - 1;

    while(pStart < pEnd) {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }
}
