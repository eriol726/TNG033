#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

#include "statistics.h"

using namespace std;

/******************************
* 1. Functions declarations   *
*******************************/

//Read a sequence of values from cin and store them in array a
//V has n slots, i.e. at most n values can be read and stored in array a
//Return how many values were read and stored in a
int read_seq(int a[], int size);


//Display all values stored in array a to cout
//array a stores n integers
//10 values per line should be displayed
void display(int a[], int n);


//Copy n values from array to into array from
void copy(int to[], int from[], int n);



/******************************
* 2. Main function            *
******************************/


int main ()  //DO NOT MODIFY
{
    const int SIZE = 1000;

	int theNumbers[SIZE], theCopy[SIZE];

	int howMany = read_seq(theNumbers, SIZE);

	if (!howMany)
	{
	    cout << "No data given!!" << endl;
	    return 0;
	}

	cout << "Sequence size = " << howMany << endl;

	copy (theCopy, theNumbers, howMany);
	sort(theCopy, howMany);

	cout << "\nList of values not sorted" << endl;
	display(theNumbers, howMany);
	cout << endl;

	cout << "\nList of sorted values" << endl;
	display(theCopy, howMany);
	cout << endl;

	int max = 0, min = 0;

	max = max_min(theNumbers, howMany, min);
	cout << "\n\nMax = " << max << " och Min = " << min << endl;

	double theMean = mean(theNumbers, howMany);
	cout << "Average = " << theMean << endl;

	double theMedian = median (theCopy, howMany);
	cout << "Median = " << theMedian << endl;

	double theStandardDev = standard_deviation(theNumbers, howMany);
	cout << "Standard deviation = " << theStandardDev << endl;

	return 0;
}


/******************************
* 3. Functions definitions    *
*******************************/


//Read a sequence of values from cin and store them in array a
//V has n slots, i.e. at most n values can be read and stored in array a
//Return how many values were read and stored in a
int read_seq(int a[], int size)
{

    ifstream in_file("stat_data.txt"); //file to read

    //Test if opening the files succeeded
    if ( !in_file.good()  )
    {
        cout << "Error in file opening" << endl;
        return 0; // end the program
    }


    bool loop = true;

    double number;

    int i = 0;

    while ( (i < size) && in_file >> number   )
    {

        a[i] = number;

        i++;

    }



    in_file.close();
    return i;


}


//Display all values stored in array a to cout
//array a stores n integers
//10 values per line should be displayed
void display(int a[], int n)
{
   for(int i = 0; i < n; i++){

        if(i%10 == 0 ){
            cout << endl;
        }
        cout << setw(5) << a[i] ;
    }

}


//Copy n values from array to into array from
void copy(int to[], int from[], int n)
{
    for(int i = 0; i <= n; i++){
        to[i] = from[i];
    }
}

