/*
Imagine a publishing company which does marketing for book and audio cassette
versions. Create a class publication that stores the title (a string) and price (type
float) of publications. From this class derive two classes: book which adds a page
count (type int) and tape which adds a playing time in minutes (type float).
*/

#include <iostream>
#include <string.h>
using namespace std;
class publication
{
private:
    string title;
    float price;

public:
    publication()
    {
        title = "";
        price = 0.0;
    }

public:
    void getdata()
    {
        cout << "Enter Title:";
        cin >> title;
        cout << "Enter Price:";
        cin >> price;
    }
    void putdata()
    {
        cout << "Title:" << title << endl;
        cout << "Prices:" << price << endl;
    }
};

class book : public publication
{
private:
    int pgct;

public:
    book()
    {
        pgct = 0;
    }
    void getdata()
    {
        publication::getdata();
        cout << "Enter Pages:";
        cin >> pgct;
    }
    void putdata(void)
    {
        publication::putdata();
        try
        {
            if (pgct < 0)
                throw pgct;
        }
        catch (int f)
        {
            cout << "Invalid Page Count" << f;
            pgct = 0;
        }
        cout << "Pages:" << pgct << endl;
    }
};

class tape : public publication
{
private:
    float time;

public:
    tape()
    {
        time = 0.0;
    }
    void getdata()
    {
        publication::getdata();
        cout << "Minutes:";
        cin >> time;
    }
    void putdata()
    {
        publication::putdata();
        try
        {
            if (time < 0.0)
                throw time;
        }
        catch (float r)
        {
            cout << "Invalid Playing Time" << time;
            time = 0.0;
        }
        cout << "Minutes:" << time << endl;
    }
};

int main()
{
    book b;
    tape t;
    b.getdata();
    t.getdata();
    cout<<endl;
    b.putdata();
    t.putdata();
    return 0;
}