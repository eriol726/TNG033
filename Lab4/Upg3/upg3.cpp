#include <iostream>
#include <String>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <iomanip>


using namespace std;


typedef map<string, vector<string>> Table;

typedef pair<string, vector<string>> Table_Entry;

void load_table(Table &T, int &count);

ostream& operator<<(ostream& out, const Table_Entry& e);

//void display(const vector<Table_Entry> &V);

void display(const Table_Entry& v);

bool compare(const Table_Entry &lhs, const Table_Entry &rhs){
    //cout << "size: "<<lhs.second.size() << ">" << rhs.second.size() << endl;
    return (lhs.second.size() > rhs.second.size());
}


int main()
{
    int count = 0;
    Table t;
    load_table(t, count);

    cout << "Number of words  = " << count << endl << endl;

    vector<Table_Entry> vec_table(t.size());

    copy(t.begin(), t.end(), vec_table.begin());

    sort(vec_table.begin(), vec_table.end(), compare);

    for_each(vec_table.begin(), vec_table.end(), display);



    return 0;
}

void load_table(Table &T, int &count){

    //tabell::iterator it = T.begin();
    string line = "";
    ifstream is("uppgift3_kort.txt");


    while(is >> line)
    {

        string newLine = "";
        newLine = line;
        sort(line.begin(), line.end());


        T[line].push_back(newLine) ;

        count++;
    }

}

/*
namespace std{
    ostream& operator<<(ostream& out, const vector<Table_Entry>& e)
    {
        for(int i = 0; i< e.second.size(); i++){
               out<<e.second[i] << " ";
        }

        out << "-> " << e.second.size() << " words"<< endl;

        return out;
    }

}
*/

void display(const Table_Entry& v){

    for(int i = 0; i< v.second.size(); i++){
        cout  << v.second[i] << " " ;
    }

    cout << "-> " << v.second.size() << " words"<< endl;
}
