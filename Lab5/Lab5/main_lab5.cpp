/********************************************************
* Lab 5                                                 *
* 1. Read each text file with jump scores for a round   *
* 2. Binary file of divers should be updated            *
*********************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#include <algorithm>
#include <iterator>




#include "diver.h"

using namespace std;

const int NR_OF_REF = 7;

/*******************************
* Function declarations        *
********************************/

typedef map<string, vector<double> > tabell;

typedef pair<string, vector<double> > Table_Entry;

//lab 1
double calculate_result(double scores [], double difficulty);

//Compare two divers by total number of points
bool compare(Diver d1, Diver d2);

//Update the binary file with the data in textfile
void update_bin_file(ifstream& textfile, fstream& binfile);

//Read the binary file binfile and load the Diver records into vector D
void read_bin_file(ifstream &binfile, vector<Diver> &D);


/*********************************
* main -- Do not modify          *
**********************************/

int main( )
{

    //Read a text file for one round of jumps

    string file_name = "round_4.txt";

    cout << "Filname: ";
    //cin >> file_name;

    ifstream textfile(file_name.c_str());

    //Open the binary file in read+write mode
    fstream binfile("divers.bin", ios::in | ios::out | ios::binary);

    if (!textfile || !binfile)
    {
        cout << "\nCould not open a file!!" << endl;
        return 0;

    }

    cout << "\nUpdating binary file of divers data ..." << endl;
    update_bin_file(textfile, binfile);

    binfile.close();
    textfile.close();

    /* *************************************************************** */

    //Read the updated binary file and load the diver records into a vector

    ifstream binfile1("divers.bin", ios::in | ios::binary); //open binary file in reading mode

    vector<Diver> all_divers;

    if(binfile1)
    {
      cout << "\nReading updated binary file ..." << endl;
      read_bin_file(binfile1, all_divers);

      binfile1.close();
    }

    sort (all_divers.begin(), all_divers.end(), compare);

    cout <<"\nDisplay the binary file sorted by total points ..." << endl;
    cout << "Nr   Name"
         << setw(25) << "Round 1"
         << setw(8) << "Round 2"
         << setw(8) << "Round 3"
         << setw(8) << "Round 4"
         << setw(8) << "Round 5"
         << setw(8) << "Total" << endl;

    for(int i = 0; i != all_divers.size(); i++)
        cout << all_divers[i] << endl;

    return 0;
}


/*******************************
* Function implementation      *
********************************/

//lab 1
double calculate_result(double scores [], double difficulty)
{
    double max = scores[0], min = scores[0], result;

    for (int i = 1; i < NR_OF_REF; i++ )
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }

        if (scores[i] < min)
        {
            min = scores[i];
        }
    }

    double sum = 0;
    for (int i = 0; i < NR_OF_REF ; i++)
    {
        sum += scores[i];
    }

    sum = sum - max - min;
    result = 3 * difficulty * sum / (NR_OF_REF - 2);

    return result;
}


//Compare two divers by total number of points
bool compare(Diver d1, Diver d2)
{
    return d1.getTotal() > d2.getTotal();
}


//Update the binary file with the data in textfile
void update_bin_file(ifstream& textfile, fstream& binfile)
{

    double score[NR_OF_REF];
    double difficulty = 0.0;
    string id_from_txt_file;
    string round = "";
    string name = "";
    string id = "";
    getline(textfile, round);
    int i = 0;

    string nmuber = round.substr(5, round.length());
    int col = atoi(nmuber.c_str());


    while (i<14 && !textfile.eof()){

        /*
        stringstream instream1(id_from_txt_file);
        int x = 0;
        instream1 >> x;*/

        getline(textfile, id_from_txt_file);

        id_from_txt_file.erase(0,1);

        int value = atoi(id_from_txt_file.c_str());

        value-=200;

        textfile >> difficulty ;

        string line = "";
        getline(textfile, line);

        istringstream instream(line);

        //lägger in enskilda poäng i en array
        int n = 0;
        while(instream >> score[n]){
            n++;
        }

        double result = calculate_result(score, difficulty);

        Diver temp;

        streampos pos = (value-1) * sizeof(Diver);
        binfile.seekg(pos, ios::beg);

        binfile.read((char*)&temp, sizeof(Diver));


        temp.update(col,result);

       // cout << temp << endl;

        binfile.seekp(pos, ios::beg);

        binfile.write( (char*) &temp, sizeof(Diver));

        i++;
    }

}



//Read the binary file binfile and load the Diver records into vector D
void read_bin_file(ifstream &binfile, vector<Diver> &D)
{
    int i = 0;
    Diver temp;
    binfile.read((char*)&temp, sizeof(Diver));
    while( binfile && i < 15)
    {
        D.push_back(temp);
        //sort(D.begin(), D.end());
        binfile.read((char*)&temp, sizeof(Diver));
        i++;
    }
}

