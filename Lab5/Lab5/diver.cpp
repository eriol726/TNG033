/*******************************
* Lab 5: diver.cpp             *
* Class Diver implementation   *
* Author: Aida Nordman         *
*******************************/


#include "diver.h"
#include <algorithm>
#include <iterator>
#include <cstring>
#include <iomanip>
#include <cmath>


Diver::Diver(string na, string id_nr)
{
  strcpy(name, na.c_str());
  strcpy(id, id_nr.c_str());

  fill(result, result+NR_OF_DIVES, -1.0);
//  for (int i = 0; i < NR_OF_DIVES; i++)
//    result[i] = -1.0;

  total = 0;
}


ostream& operator <<(std::ostream& os, const Diver& d)
{
  os << d.id << " "
     << setw(Diver::NAME_LENGTH) << left << d.name;

  os << fixed << setprecision(1) << right;

  for (int i = 0; i < Diver::NR_OF_DIVES; i++)
    os << setw(8) << d.result[i];

  os << setw(8) << d.total << endl;

  return os;
}



//Update the divers data for one more round:
//score results and total are updated
void Diver::update( int round, double res)
{
  result[round - 1] = res;
  total += res;
}

