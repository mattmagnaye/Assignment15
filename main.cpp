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

// Recursive function to reverse array within given bounds
void reverseWithinBounds(char arr[], int start, int end) {
    // base case
    if(start >= end) 
        return;

    // swap elements
    std::swap(arr[start], arr[end]);

    // Recursive call for remaining array
    reverseWithinBounds(arr, start + 1, end - 1);
}

// Function to reverse a C string
void reverseCString(char* str) {
    int n = strlen(str);
    // calling the recursive function with full length of string
    reverseWithinBounds(str, 0, n-1);
}

int main() {
    // testing reverseWithinBounds
    char arr[] = {'A', 'B', 'C', 'D', 'E'};
    reverseWithinBounds(arr, 1, 4);
    for(char c : arr)
        std::cout << c << " ";
    std::cout << std::endl;

    // testing reverseCString
    char str[] = "Hello, World!";
    reverseCString(str);
    std::cout << str << std::endl;

    return 0;
}
