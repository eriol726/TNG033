/********************************
* DO NOT MODIFY any declaration *
*********************************/

#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>

//Return the largest value stored in V
//Return the smallest value stored in V through reference argument min
//a is an array with n occupied slots
int max_min (int a[], int n, int& min);


//Return the average of the values stored in a
//a is an array with n occupied slots
double mean (int a[], int n);


//Return the median of the values stored in a
//a is a sorted array storing n values
//Medianvärdet är det mittersta värdet
//i den sorterade arrayen
//Om n är jämnt blir det medelvärdet av de två talen i mitten.
double median (int a[], int n);


//Returns the standard deviation of n integer numbers in array a
double standard_deviation(int a[], int n);


//Sort array a
//a is an array storing n values
//Use a sorting algorithm different from bubblesort, e.g. selection sort, insertion sort
void sort (int a[], int n);


//swap the values of parameters a and b
//to be used by sort function
void swap(int& a, int& b);

#endif
