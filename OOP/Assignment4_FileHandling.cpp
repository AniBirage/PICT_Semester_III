/*
Write a C++ program that creates an output file, writes
information to it, closes the file, open it again as an
input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Student{
    string name;
    int age;
public:
    Student()
    {
        name = "";
        age = 0;
    }
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void getInformation()
    {
        cout << "Enter the name of the student: " << endl;
        cin >> name;
        cout << "Enter the age of the student: " << endl;
        cin >> age;
    }
    void writeOnFile()
    {
        ofstream new_file;
        new_file.open("NewFile.txt",ios::in);
        if(!new_file)
        {    
            new_file.close();
            new_file.open("NewFile.txt",ios::out);
            cout << "File created successfully. Information is being written." << endl;
            new_file << "Name = " << name << endl;
            new_file << "Age = " << age << endl;
            new_file.close();
            cout << "File closed successfully." << endl;
        }
        else
        {
            new_file.close();
            cout << "File already exists. Information is being written on the file." << endl;
            new_file.open("NewFile.txt",ios::app);
            new_file << "Name = " << name << endl;
            new_file << "Age = " << age << endl;
            new_file.close();
            cout << "File closed successfully." << endl;
        }
    }
    static void readFromFile()
    {
        ifstream new_file;
        new_file.open("NewFile.txt",ios::in);
        if(!new_file)
        {
            cout << "File does not exist. Firstly write and create the file." << endl;
        }
        else
        {
            string var;
            while(!new_file.eof())
            {
                getline(new_file,var);
                cout << var << endl;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of students: " << endl;
    cin >> n;
    Student *o = new Student[n];
    for(int i=0;i<n;i++)
    {
        (o+i)->getInformation();
        (o+i)->writeOnFile();
    }
    Student::readFromFile();
    return 0;
}