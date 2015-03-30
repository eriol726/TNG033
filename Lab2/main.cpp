#include <iostream>
#include <iomanip>

#include "set.h"

//DO NOT MODIFY
//Expected output is given in teh file out_uppg2.txt

using namespace std;

int main()
{
  int A1[] = { 1, 3, 5 };
  int A2[] = { 4, 3, 2 };

  Set S1(A1, 3);
  Set S2(A2, 3);

  Set S3;
  Set S4;
  Set S5(S1);

  cout << "\n** constructors\n" << endl;
  cout << "S1 = " << S1 << endl;
  cout << "S2 = " << S2 << endl;
  cout << "S3 = " << S3 << endl;
  cout << "S4 = " << S4 << endl;
  cout << "S5 = " << S5 << endl;


  S3 = S4 = S5;

  cout << "\n** assignment\n" << endl;
  cout << "S3 = " << S3 << endl;

  cout << "\n** member functions\n" << endl;
  for (int i = 1; i <= 5; i++) {
    cout << "S3.member(" << i << ") ? " << (S3.member(i) ? 'T' : 'F') << endl;
  }
  cout << "\nS3.member(99999) ? " << (S3.member(99999) ? 'T' : 'F') << endl;
  cout << "\nS3.cardinality() = " << S3.cardinality() << endl;

  S3 = S1 + S2 + 4;
  S4 = S1 * S2;
  S5 = S1 - S2;

  cout << "\n** union, intersection, difference\n" << endl;
  cout << "S3 = " << S3 << endl;
  cout << "S4 = " << S4 << endl;
  cout << "S5 = " << S5 << endl;



  cout << "\n** equality, subset, proper subset\n" << endl;
  cout << "S2 == S3 ? " << (S2 == S3 ? 'T' : 'F') << endl;
  cout << "S2 <= S3 ? " << (S2 <= S3 ? 'T' : 'F') << endl;
  cout << "S2 <  S3 ? " << (S2 <  S3 ? 'T' : 'F') << endl;

  S4 = S1 + 4 - 5 - 99999;
  S5 = S2 - 2 + 1 - 99999;

  cout << "\n** insertion, deletion\n" << endl;
  cout << "S4 = " << S4 << endl;
  cout << "S5 = " << S5 << endl;

  cout << "\n** equality, subset, proper subset\n" << endl;
  cout << "S4 == S5 ? " << (S4 == S5 ? 'T' : 'F') << endl;
  cout << "S4 <= S5 ? " << (S4 <= S5 ? 'T' : 'F') << endl;
  cout << "S4 <  S5 ? " << (S4 <  S5 ? 'T' : 'F') << endl;


  return 0;
}
