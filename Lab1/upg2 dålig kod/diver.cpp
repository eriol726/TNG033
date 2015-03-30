#include <iomanip>
#include <ios>
#include <sstream>

#include "diver.h"


//Overload operator>> to read data for a diver d from stream in
//If errors were encountered while reading the data for a diver d
//then d.name is set to an empty string
//Return the stream in
istream& operator>>(istream& in, Diver& d)
{



    string trash = "";
    in >> ws;
    getline(in, d.name);
    in >> ws;
    getline(in, trash);
    istringstream instream(trash);


    if (findTrash(trash)){
        return instream;
    }

    else if(trash.length() < 31){
        return in;
    }

    else{
    //"no trash";*/
    instream >> d.difficulty;

        int i = 0;
        while(i<7 && instream >> d.points[i]){
             double point = d.points[i];
             i++;

        }
    }

    return instream;
}


//Calculate final score for diver d
//and store it in d.final_score
void calculate_final_score(Diver& d)
{
    //sorterar
      for ( int pass = 0; pass < 7 ; pass++ ){
          for (int i = 0; i< 6; i++ ){
            if(d.points[i] > d.points[i+1]  )
                 {
                     double temp = d.points[i+1];
                     d.points[i+1] = d.points[i];
                     d.points[i] = temp;
                 }
          }
      }

    d.final_score = 0;

    //plockar ut de dom 5 elementen som ligger i mitten
    for (int n = 1; n < 6; n++ ){
            d.final_score += d.points[n];
    }
    d.final_score /= 5;
    d.final_score *= 3*d.difficulty;
}


//Overload operator<< to write data for diver d
//to stream out: name and final score
void operator<<(ostream& out, const Diver& d)
{

    out << setw(25)  << left << fixed << d.name ;
    out << setprecision(1) << d.final_score << '\n';

}


//Overload comparison operator
//Return true if d1.final_score < d2.final_score
bool operator<(const Diver& d1, const Diver& d2)
{
    if (d2.final_score < d1.final_score){
        return true;
    }
    return false;

}



bool findTrash(string trash){

    string tecken = "?%abcdefghijklmnopqrstuvwyXz";

    for(int i = 0; i < trash.length(); i++){
        for(int n = 0; n < tecken.length(); n++){

            if(trash.at(i) == tecken.at(n) ){

                return true;

            }
        }
    }
    return false;
}

