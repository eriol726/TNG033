
#ifndef POL_H
#define POL_H

#include <iostream>
#include <new>

using namespace std;

#include "expression.h"

//Define class Polynomial

class Polynomial : public Expression{
    public:

    //constructor

    Polynomial();
    //intierar mitt "head" evemtuellt Polynomial(int n = 0, double *p = nullptr);

    Polynomial(int d, double c[]);

    ~Polynomial();

    //copy constructor
    Polynomial(const Polynomial &P);


    //convertion constructor
    Polynomial(double p);

    //assignment oporator
    const Polynomial& operator=(const Polynomial &P);

    Polynomial *clone() const;

    double& operator[](const int x);

    Polynomial operator+(const Polynomial &P) const;
    Polynomial operator+(const double x) const;

    //bool isRoot(double x) const;

    double eval(double x) const;
  // Polynomial operator+(…) const;




	protected:
	    double* coef; //array of basees
        int degree;    //number of courses given by the teacher

        void display(ostream& os) const;



};

#endif
