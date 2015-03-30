
#ifndef Logarithm_H
#define Logarithm_H

#include <iostream>
#include <new>

using namespace std;

#include "expression.h"
#include "polynomial.h"



class Log: public Expression{
    public:

    //constructor

    Log();

    Log *clone() const;
    double eval(double x) const;
    //assignment operator
    const Log& operator=(const Log &inL);
    Log(const Expression &E, double c1,double c2, int b );

    //copy constuctor
    Log(const Log &L);


    ~Log();
   //bool isRoot(double v) const;
	protected:

        Expression *E;
        int base;
        double k2;
        double k1;
        void display(ostream& os) const;

};

#endif

