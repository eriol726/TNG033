//Implement member functions of class Expression

#include "expression.h"
#include "math.h"



const double EPSILON = 1.0e-5;

/*
double Expression::eval(double v) const
{
    return 0.0;

}*/

bool Expression::isRoot(double v) const
{
    return(fabs(eval(v)-0.0) < EPSILON );
}

ostream& operator<<(ostream& os, const Expression& E)
{
    E.display(os); //dynamic binding: call function display(os) for the class of the object referred by E

    return os;
}
