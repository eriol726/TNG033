//Implement member functions of class Logarithm
#include <iostream>
#include <iomanip>
#include <math.h>

#include "logarithm.h"
#include "polynomial.h"

Log::Log()
: k1(1), k2(0), base(2)
{
    double arr[2] = {0,1};

    E = new Polynomial(1,arr);

}

Log::Log(const Expression &B, double c1, double c2,int b){

    k1 = c1;
    k2 = c2;
    base = b;
    E = B.clone();

}
 //copy constuctor
Log::Log(const Log &L)
{
    //Log newLog = L;
    Log newLog ;// = L.clone()

    newLog.base = L.base;
    newLog.k1 = L.k1;
    newLog.k2 = L.k2;
    newLog.E = L.E;

    *this = newLog;

    //cout << newLog << endl;
}


const Log& Log::operator=(const Log &inL)
{
    //this = l2  inL = l1
    //Log(inL);

    base = inL.base;
    k1 = inL.k1;
    k2 = inL.k2;
    E = inL.E;
    return (*this);
}

double Log::eval(double v) const
{
    if(log(E->eval(v))/log(base) == 0.00){
       return 0;
    }
    return k1+k2*log(E->eval(v))/log(base);
}

Log::~Log(){

}
void Log::display(ostream& os) const
{
   os << k1 ;
   if(k2>0)
   os << "+" << k2 ;
   os << "*ln_"<<base<<"("<<*E<<")";
}




Log* Log::clone() const{
    return new Log(*this);
}






