#include <iostream>
#include <cmath>



#include "statistics.h"


//Return the largest value stored in V
//Return the smallest value stored in V through reference argument min
//a is an array with n occupied slots
int max_min (int a[], int n, int& min)
{
    int max = 0;

     for(int i = 0; i < n; i++)
    {
        if (a[i] > max) //new max?
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }

    return max;
}

//Return the average of the values stored in a
//a is an array with n occupied slots
double mean (int a[], int n)
{
    double avg = 0.0;

    for(int i = 0; i < n; i++){
        avg += a[i];
    }

    avg /= n;


   return avg;
}


//Return the median of the values stored in a
//a is a sorted array storing n values
//Medianvärdet är det mittersta värdet
//i den sorterade arrayen
//Om n är jämnt blir det medelvärdet av de två talen i mitten.
double median (int a[], int n)
{
    double median = 0.0;

    if (n%2 == 0)
    {
          median = (a[n/2 - 1]+a[n/2]) / 2;
    }
    else
    {
          median = a[n/2];
    }
    return median;
}


//Returns the standard deviation of n integer numbers in array a
double standard_deviation(int a[], int n)
{
    double avg = mean(a, n);

    double S = 0.0;

    for(int i = 0; i < n; i++){
        S += pow((a[i]-avg), 2);
    }
    S = sqrt(S/n);

    return S;

}


//Sort array a
//a is an array storing n values
//Use a sorting algorithm different from bubblesort
void sort (int a[], int n) //selection sort
{
    for(int i = 0; i<n-1; i++){
        if(a[i] < a[i+1]){
            swap(a[i] ,a[i+1]);
        }
        for(int i = n-1; i>0; i--){
            if(a[i] < a[i-1]){
                swap(a[i] ,a[i-1]);
            }
        }
    }
}

//swap the values of parameters a and b
//to be used by sort function
void swap(int& a, int& b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
