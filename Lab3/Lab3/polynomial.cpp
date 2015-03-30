//Implement member functions of class Polynomial
#include <iostream>
#include <iomanip>
#include <math.h>
#include "polynomial.h"

Polynomial::Polynomial()
{
    degree = 2;
    coef = new double[degree];
    coef[0] = 0;
    coef[1] = 1;
}


//convertion constructor
Polynomial::Polynomial(double p)
: degree(0)
{
    coef = new double[degree];
    coef[0] = p;
}

Polynomial::Polynomial(int d, double c[])
: degree(d) //, Expression(c) //call constructor of base class to initialize degree
{
    coef = new double[degree+1];//allocate memory for the course codes

    for(int i = 0; i <= degree; i++){

        coef[i] = c[i];
    }

}

//copy constructor
Polynomial::Polynomial(const Polynomial &T)
 : degree(T.degree)//, Expression(T) //call base class copy constructor
{
    coef = new double[degree+1];//allocate memory for the bases
    for(int i = 0; i <= degree; i++){
        coef[i] = T.coef[i];  //copy bases from array p
    }

}

Polynomial::~Polynomial()
{
    delete[] coef;
    degree = 0;
}


double Polynomial::eval(double x) const
{
    double ans = 0;
    for(int i = 0; i<=degree ; i++)
    {
        if(i > 0)
        {
             ans += (coef[i] * pow(x, i));
        }
        else
        {
            ans +=coef[i];
        }

    }
    return ans;
}

/*
bool Polynomial::isRoot(double x) const
{
    double root = eval(x);
    if(root == 0)
    {
        return true;
    }
    return false;
}*/

double& Polynomial::operator[](const int x)
{
    return coef[x];       //returnerar det nya elementet på platsen x i arrayen
}
Polynomial Polynomial::operator+(const Polynomial &P) const
{

    Polynomial temp(*this);


    for(int i = 0; i <= P.degree; i++){
        temp.coef[i] += P.coef[i];
    }
    return temp;

}

Polynomial* Polynomial::clone() const
{
    return new Polynomial(*this);
}

Polynomial Polynomial::operator+(const double x) const
{
    coef[0] += x;
    return (*this);
}


const Polynomial& Polynomial::operator=(const Polynomial &P)
{
    if (this != &P) //test self-assignment
    {
        //1. Delete old memory
        delete[] coef;

        //2. Allocate new memory
        coef = new double[P.degree+1];
        //3. Copy
        degree = P.degree;

        for(int i = 0; i <= degree; i++){
                coef[i] = P.coef[i];
        }
    }
    return (*this);
}



void Polynomial::display(ostream& os) const
{

    int n = 0;
    cout << setprecision(2) << fixed << coef[0] << " + " ;
    for(int i = 1; i < degree+1; i++){

            if(coef[i] != 0 && i != 0){
                cout << coef[i] <<" * X^" << i;
            }
            if(i < degree && coef[i] != 0){
                cout << " + ";
            }




    }


}


