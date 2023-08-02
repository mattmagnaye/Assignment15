/*
* Program: main.cpp (Assignment 15P: Recursion)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 08/02/2023
* Description: Write a recursive function named reverseWithinBounds 
*              that has an argument that is an array of characters 
*              and two arguments that are bounds on array indices. 
*
*/
#include<iostream>
#include<cstring>
using namespace std;

// Function to reverse array elements within given bounds (inclusive).
void reverseWithinBounds(char arr[], int start, int end) {
    if(start >= end)  // Base condition to break recursion when start meets or crosses end.
        return;
    swap(arr[start], arr[end]);  // Swap elements at positions start and end.
    reverseWithinBounds(arr, start + 1, end - 1);  // Recursive call with updated bounds.
}

// Function to reverse a null-terminated C string.
void reverseCString(char* str) {
    int n = strlen(str);  // Get length of string.
    reverseWithinBounds(str, 0, n-1);  // Call to reverseWithinBounds with full bounds of the string.
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D', 'E'};  // Test array.
    reverseWithinBounds(arr, 1, 4);  // Call to reverse elements within bounds 1 and 4.
    // Loop through array to print elements and their indices.
    for(char c : arr)
        cout << "a[" << (&c - arr) << "] == '" << c << "' ";
    cout << endl;

    char str[] = "Hello, World!";  // Test string.
    reverseCString(str);  // Call to reverse string.
    cout << "Reversed C string: " << str << endl;  // Print reversed string.

    return 0;
}
