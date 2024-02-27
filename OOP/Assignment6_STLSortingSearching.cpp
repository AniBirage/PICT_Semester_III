/*
Write C++ program using STL for sorting and
searching user defined records such as Item records
(Item code, name, cost, quantity etc) using vector
container.
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class ItemRecord
{
public:
    string item_name;
    string item_code;
    float cost;
    int quantity;

    bool operator==(const ItemRecord &i1)
    {
        if (item_code == i1.item_code)
        {
            return 1;
        }
        else
            return 0;
    }
    bool operator<(const ItemRecord &i1)
    {
        if (item_code < i1.item_code)
            return 1;
        else
            return 0;
    }
};
vector<ItemRecord> o1;
void print(ItemRecord &i1);
void insert();
void display();
void search();
void dlt();

void insert()
{
    ItemRecord i1;
    cout << "Enter Item Name" << endl;
    cin.ignore();
    getline(cin, i1.item_name);
    cout << "Enter Item Code" << endl;
    cin >> i1.item_code;
    cout << "Enter Item Cost" << endl;
    cin >> i1.cost;
    cout << "Enter Item Quantity" << endl;
    cin >> i1.quantity;
    o1.push_back(i1);
}
void display()
{
    for_each(o1.begin(), o1.end(), print);
}
void print(ItemRecord &i1)
{
    cout << "\n";
    cout << "\tItem Name    : " << i1.item_name << endl;
    cout << "\tItem Code    : " << i1.item_code << endl;
    cout << "\tItem Cost    : " << i1.cost << endl;
    cout << "\tItem Quantity: " << i1.quantity << endl;
}
void search()
{
    vector<ItemRecord>::iterator p;
    ItemRecord i1;
    cout << "\n Enter Item Code to Search: " << endl;
    cin >> i1.item_code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
        cout << "\nNot Found" << endl;
    else
        cout << "\nFound" << endl;
}
bool compare(const ItemRecord &i1, const ItemRecord &i2)
{
    if (i1.item_name == i2.item_name)
        return i1.cost < i2.cost;
    return i1.cost < i2.cost;
}

void dlt()
{
    vector<ItemRecord>::iterator p;
    ItemRecord i1;
    cout << "\n Enter Item Code to Delete: " << endl;
    cin >> i1.item_code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
        cout << "\nNot Found" << endl;
    else
    {
        cout << "\nFound and Deleted.." << endl;
        o1.erase(p);
    }
}
int main()
{
    ItemRecord i1;
    int ch;
    cout << "\t****MENU****" << endl;
    cout << "\t1. Insert" << endl;
    cout << "\t2. Display" << endl;
    cout << "\t3. Search" << endl;
    cout << "\t4. Sort" << endl;
    cout << "\t5. Delete" << endl;
    cout << "\t6. Exit" << endl;
    do
    {

        cout << "\tEnter Choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();

            break;
        case 4:
            sort(o1.begin(), o1.end(), compare);
            display();
            break;
        case 5:
            dlt();
            break;
        case 6:
            cout << "Code Exited" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Choice!!!!!";
            break;
        }
    } while (ch != 6);
}