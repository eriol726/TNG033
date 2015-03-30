#include <iostream>
#include <String>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <iomanip>


using namespace std;

typedef map<string,int> tabell;

typedef pair<string,int> Table_Entry;

void load_table(tabell &T, int &count);

ostream& operator<<(ostream& out, const Table_Entry& e);

void display(const Table_Entry& v);

ostream& operator<<(ostream& out, const vector<Table_Entry>& V);

vector<Table_Entry> make_vector(const tabell &T);

bool compare(const Table_Entry &e1, const Table_Entry &e2);

const string trash = "(.,!?:\"();";

char to_lower(char c);

bool remove_c(char c);

int main()
{
    int count = 0;
    tabell t;
    load_table(t, count);

    cout << "Number of words in the file = " << count << endl;
    cout << "Number unique  words in the file = " << t.size() << endl << endl;

    ostream_iterator<Table_Entry> oit(cout, "\n");

    cout << "Frequency table sorted alphabetically ... " << endl;

    copy(t.begin(), t.end(), oit);

    cout << endl << endl << endl;


    vector<Table_Entry> vec_table(t.size());

    //1. Copy the pairs in the map to a vector
    //vec_table = make_vector(t);
    copy(t.begin(), t.end(), vec_table.begin());

    //2. Sort vector by destiny
    sort(vec_table.begin(), vec_table.end(), compare);

    //3. Display vector sorted by destiny (string)
    cout << "Frequency table sorted by frequence ..." << endl << endl;

    for_each(vec_table.begin(), vec_table.end(), display);

    //alternativ
    //cout << vec_table;

    return 0;
}

void load_table(tabell &T, int &count){

    tabell::iterator it = T.begin();
    string line = "";
    ifstream is("uppgift1_kort.txt");

    int i = 0;

    while(is >> line)
    {

        string newLine = "";

        transform(line.begin(), line.end(), line.begin(), to_lower);
        copy_if(line.begin(), line.end(), back_inserter(newLine), remove_c);

        T[newLine]++;

        count++;
    }

}
char to_lower(char c)
{

    return toupper(c);
}

bool remove_c(char c)
{
    if ( find(trash.begin(), trash.end(), c) != trash.end() )
        return false;
    return true;
}

bool compare(const Table_Entry &e1, const Table_Entry &e2)
{
    return (e1.first <= e2.first);
}

vector<Table_Entry> make_vector(const tabell &T)
{
    vector<Table_Entry> ret;

    tabell::const_iterator map_it = T.begin();

    //Table_Entry p;

    while (map_it != T.end())
    {
        //p = make_pair(map_it->first, map_it->second);

        ret.push_back(*map_it);

        map_it++;
    }

    return ret;
}

namespace std{

    ostream& operator<<(ostream& out, const Table_Entry& e)
    {
        return out << setw(12) << left << e.first << " " << e.second ;
    }

}
//alternativ
/*
ostream& operator<<(ostream& out, const vector<Table_Entry>& V)
{
    vector<Table_Entry>::const_iterator cit = V.begin();

    while (cit != V.end())
    {
        out << *cit << setw(15)<< left;
        cit++;
    }
    return out  ;

}*/

void display(const Table_Entry& v){

    cout << setw(12) << left << v.first << " " << v.second << endl ;
}



