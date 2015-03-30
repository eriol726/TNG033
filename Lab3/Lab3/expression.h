#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <new>


using namespace std;

class Expression
{
    public:
    //constructor
    Expression(){};
    //Destructor
    virtual ~Expression() { };
    virtual Expression* clone() const = 0;

    virtual double eval(double v) const = 0;

    bool isRoot(double v) const;

    friend ostream& operator<<(ostream& os, const Expression& E);


	protected:


    virtual void display(ostream& os) const{  } ;


};




#endif
