/*
Write a program in C++ to use map associative
container.The keys will be the names of statesand
the values will be the populations of the states.
When the program runs, the user is prompted to
type the name of a state.The program then looks in
the map, using the state name as an indexand
returns the population of the state.
*/

#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
class Map
{
    int n;
    string name;
    long p;

public:
    map<string, long> m1;
    void insert();
    void display();
    void search();
};
void Map::insert()
{
    cout << "Enter The No. Of states for which the population is to be Entered: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Name of State " << (i + 1) << endl;
        cin >> name;
        cout << "Enter Population Of " << name << endl;
        cin >> p;
        m1.insert(pair<string, long>(name, p));
    }
}
void Map::display()
{
    map<string, long>::iterator it;
    for (it = m1.begin(); it != m1.end(); ++it)
    {
        cout << "Population of " << it->first << " is: " << it->second << endl;
    }
}
void Map::search()
{
    string s;
    map<string, long>::iterator it;
    cout << "Enter Name Of State Whose Population is to be found: " << endl;
    cin >> s;
    it = m1.find(s);
    if (it != m1.end())
        cout << "Population of " << s << " is: " << it->second << endl;
    else
        cout << "Key is Not Population Map\n"
             << endl;
}

int main()
{
    Map m;
    int ch;
    do
    {
        cout << "\t****MENU****" << endl;
        cout << "\t1. Insert" << endl;
        cout << "\t2. Display" << endl;
        cout << "\t3. Search" << endl;
        cout << "\t4. Exit" << endl;
        cout << "\tEnter Choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            m.insert();
            break;
        case 2:
            m.display();
            break;
        case 3:
            m.search();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid Choice!!!!!";
            break;
        }
    } while (ch != 4);
}
