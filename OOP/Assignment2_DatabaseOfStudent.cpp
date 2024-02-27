/*
Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the
database with suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member functions, friend
class, this pointer, inline code and dynamic memory allocation operators-new and delete.
*/

#include<iostream>
#include<string.h>
using namespace std;
class Stud
{
    char address[50],license[10],insurance[20];
    long int contact;
    public:
    Stud()
    {
        strcpy(address,"ABC");
        strcpy(license,"AB-0000000000");
        strcpy(insurance,"AB000000000A");
        contact=0000000000;
    }
    ~Stud()
    {
        cout<<"Destructor";
    }
    friend class Student;
};
class Student
{
    char name[20],dob[10],blood[10];
    float h,w;
    static int c;
    Stud *p;
    public:
    Student()
    {
        strcpy(name,"ABC");
        strcpy(dob,"dd/mm/yy");
        strcpy(blood,"A+");
        h=0;
        w=0;
        p=new Stud;
    }
    Student(Student*p1)
    {
        strcpy(name,p1->name);
        strcpy(dob,p1->dob);
        strcpy(blood,p1->blood);
        h=p1->h;
        w=p1->w;
        p=new Stud;
        strcpy(p->address,p1->p->address);
        strcpy(p->license,p1->p->license);
        strcpy(p->insurance,p1->p->insurance);
        p->contact=p1->p->contact;
    }
    static void Count()
    {
        cout<<"\nNumber of Records="<<c<<"\n";

    }
    ~Student()
    {
        cout<<"\nDestructor\n";
    }
    void gData(char name[20]);
    inline void Print();
};
void Student::gData(char name[20])
{
    strcpy(this->name,name);
    cout<<"Enter Date of Birth:";
    cin>>dob;
    cout<<"Enter Blood Group:";
    cin>>blood;
    cout<<"Enter Height:";
    cin>>h;
    cout<<"Enter Weight:";
    cin>>w;
    cout<<"Enter Address:";
    cin>>p->address;
    cout<<"Enter License Number:";
    cin>>p->license;
    cout<<"Enter Insurance Policy Number:";
    cin>>p->insurance;
    cout<<"Enter Contact Number:";
    cin>>p->contact;
    c++;
}
void Student::Print()
{
    cout<<"\t\t\t"<<name;
    cout<<"\t"<<dob;
    cout<<"\t"<<blood;
    cout<<"\t"<<h;
    cout<<"\t"<<w;
    cout<<"\t"<<p->address;
    cout<<"\t"<<p->license;
    cout<<"\t"<<p->insurance;
    cout<<"\t"<<p->contact;
}
int Student::c;
int main()
{
    Student *p1,*p2;
    int ch;
    p1=new Student;
    p2=new Student(p1);
    cout<<"\t\t\tName";
    cout<<"\t   DOB";
    cout<<"\t      Blood";
    cout<<"\tH";
    cout<<"\tW";
    cout<<"     Address";
    cout<<"\t\tLicense";
    cout<<"\t\t  Insurance";
    cout<<"\tContact";
    cout<<endl;
    cout<<"Default Constructor\n";
    p1->Print();
    cout<<"\n";
    cout<<"Copy Constructor Value\n";
    p2->Print();
    int n;
    cout<<"\nEnter the Number of Records:";
    cin>>n;
    Student p3[n];
    char name[20];
    int a=0;
    do
    {
        cout<<"\nPersonal Database System"<<endl;
        cout<<"1.Enter Record\n2.Diplay Record\n3.Exit"<<endl;
        cout<<"Enter Your Choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter Name:";
                cin>>name;
                p3[a].gData(name);
                Student::Count();
                a++;
                break;
            }
            case 2:
            {
                cout<<"\t\t\tName";
                cout<<"\t   DOB";
                cout<<"\t      Blood";
                cout<<"\tH";
                cout<<"\tW";
                cout<<"\t     Address";
                cout<<"\t\tLicense";
                cout<<"\t\tInsurance";
                cout<<"\tContact";
                for(int i=0;i<n;i++)
                {
                    cout<<"\n";
                    p3[i].Print();
                }
                break;
            }
        }
    }
    while(ch!=3);
    delete p1;
    delete p2;
    return 0;
}