#include <iostream>
#include <String>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <iomanip>


using namespace std;

struct Anagram{

    string key;
    vector<string> word;
    int howMany;

};

typedef map<string, vector<string>> Table;

typedef pair<string, vector<string>> Table_Entry;

void load_table(Table &T, int &count);

ostream& operator<<(ostream& out, const Table_Entry& e);

void display(const vector<Anagram> &V);

vector<Anagram> make_vector(const Table &T);

bool sortbyHowMany(const Anagram &lhs, const Anagram &rhs) { return lhs.howMany > rhs.howMany; }


int main()
{
    int count = 0;
    Table t;
    load_table(t, count);

    cout << "Number of words  = " << count << endl << endl;


    vector<Anagram> vec_table(t.size());

    vec_table = make_vector(t);

    sort(vec_table.begin(), vec_table.end(), sortbyHowMany);

    display(vec_table);


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
vector<Anagram> make_vector(const Table &T)
{
    vector<Anagram> ret;

    Table::const_iterator map_it = T.begin();

    Anagram a;

    while (map_it != T.end())
    {
        a.key =  map_it->first;
        a.word = map_it->second;
        a.howMany = map_it->second.size();

        ret.push_back(a);

        map_it++;
    }

    return ret;
}


void display(const vector<Anagram> &V){


    for(int i = 0; i < V.size(); i++){
        for(int j = 0; j < V.at(i).word.size(); j++)
        {
            cout << V.at(i).word[j] << " " ;

        }
        cout << "--> " << V.at(i).word.size() << " words"<< endl;
    }
}


