/*******************************
* Lab 5: diver.h               *
* Class Diver definition       *
* Author: Aida Nordman         *
********************************/

#ifndef Diver_H
#define Diver_H

#include <iostream>
#include <string>
#include <list>

using namespace std;


//Do not modify class Diver

class Diver
{
  public:
    Diver (string na = "TOM" , string id_nr = "TOM "); //also default constructor

    //Update the divers data for one more round:
    //score results and total are updated
    void update( int round, double result);

    string getID() const { return string(id); }
    string getName() const { return string(name); }

    double getTotal() const { return total; }

    friend ostream& operator <<(ostream&, const Diver& d);

    //Constants
    static const int NAME_LENGTH = 20;
    static const int ID_LENGTH = 5;
    static const int NR_OF_DIVES = 5;

  private:
    char name[NAME_LENGTH];
    char id[ID_LENGTH]; //e.g. D201
    double result[NR_OF_DIVES]; //array with results for 5 rounds of jumps
    double total; //sum of the points in the result array
};

#endif
