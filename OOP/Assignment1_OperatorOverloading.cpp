/*
Implement a class Complex which represents the Complex Number data type.
Implement the following operations:
1. Contructor(including a default constructor which creates the comples number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two comples numbers.
4. Overload <<and>> to print and read complex Numbers.
*/

#include <iostream>
using namespace std;
class Complex
{
    float r;
    float i;

public:
    Complex()
    {
        r = 0;
        i = 0;
    }
    Complex operator+(Complex);
    Complex operator*(Complex);
    friend istream &operator>>(istream &input, Complex &k)
    {
        cout << "Enter Real Part:";
        input >> k.r;
        cout << "Enter Imaginary Part:";
        input >> k.i;
    }
    friend ostream &operator<<(ostream &output, Complex &k)
    {
        if (k.i < 0)
        {
            output << k.r << "-" << k.i << "i" << endl;
        }
        else
        {
            output << k.r << "+" << k.i << "i" << endl;
        }
    }
};
Complex Complex::operator+(Complex c)
{
    Complex t1;
    t1.r = r + c.r;
    t1.i = i + c.i;
    return (t1);
}
Complex Complex::operator*(Complex c)
{
    Complex t2;
    t2.r = (r * c.r) - (i * c.i);
    t2.i = (i * c.r) + (r * c.i);
    return (t2);
}
int main()
{
    int ch, f;
    char c1;
    Complex C1, C2, C3, C4;
    f = 1;
    while (f == 1)
    {
        cout << "*********MENU*********\n1.Initiate Complex Numbers\n2.Addition\n3.Multiplication\n4.Exit" << endl;
        cout << "Enter your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the First Complex Number" << endl;
            cin >> C1;
            cout << C1;
            cout << "Enter the Second Complex Number" << endl;
            cin >> C2;
            cout << C2;
            cout << "Do You Want to Continue(Y/N):";
            cin >> c1;
            if (c1 == 'Y')
            {
                f = 1;
            }
            else
            {
                f = 0;
            }
            break;
        case 2:
            C3 = C1 + C2;
            cout << "Addition of the Complex Numbers:";
            cout << C3;
            cout << "Do You Want to Continue(Y/N):";
            cin >> c1;
            if (c1 == 'Y')
            {
                f = 1;
            }
            else
            {
                f = 0;
            }
            break;
        case 3:
            C4 = C1 * C2;
            cout << "Multiplication of the Complex Numbers:";
            cout << C4;
            cout << "Do You Want to Continue(Y/N):";
            cin >> c1;
            if (c1 == 'Y')
            {
                f = 1;
            }
            else
            {
                f = 0;
            }
            break;
        case 4:
            cout << "!!THANK YOU!!";
            f = 0;
            break;
        }
    }
    return 0;
}