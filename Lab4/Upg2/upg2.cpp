#include <iostream>
#include <String>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <iomanip>


using namespace std;

typedef map<string, vector<string>> tabell;

typedef pair<string, vector<string>> Table_Entry;

void load_table(tabell &T, int &count);

ostream& operator<<(ostream& out, const Table_Entry& e);


bool check_anagram(const Table_Entry &t);



int main()
{
    int count = 0;
    tabell t;
    load_table(t, count);

    cout << "Number of words in the file = " << count << endl << endl;
    //cout << "Number unique  words in the file = " << t.size() << endl << endl;

    ostream_iterator<Table_Entry> oit(cout, "");

    copy(t.begin(), t.end(), oit);

    cout << endl << endl << endl;


    return 0;
}

void load_table(tabell &T, int &count){

    //tabell::iterator it = T.begin();
    string line = "";
    ifstream is("uppgift2_kort.txt");


    while(is >> line)
    {

        string newLine = "";
        newLine = line;
        sort(line.begin(), line.end());


        T[line].push_back(newLine) ;

        count++;
    }

}

namespace std{
    ostream& operator<<(ostream& out, const Table_Entry& e)
    {
        for(int i = 0; i< e.second.size(); i++){

               out<<e.second[i] << " ";

        }
            if(e.second.size() > 1){
               out << "-> " << e.second.size() << " words"<< endl;
             }
        return out;
    }

}

