/*
The ticket booking system of Cinemax theatre has to be
implemented using C++ program. There are 10 rows and 7 seats in
each row. Doubly circular linked list has to be maintained to keep
track of free seats at rows. Assume some random booking to start with.
Use array to store pointers (Head pointer) to each row. On demand a)
The list of available seats is to be displayed b) The seats are to be
booked c) The booking can be cancelled.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    bool status;
    char name[25];
    Node *next, *prev;
};

class cinema
{
    Node *a[10];

public:
    Node *hn, *nn;
    cinema()
    {
        hn = NULL;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                Node *cn;

                nn = new Node;
                nn->status = 0;
                if (j == 0)
                {
                    a[i] = nn;
                    a[i]->prev = a[i];
                    a[i]->next = a[i];
                }
                else
                {
                    cn = a[i];
                    do
                    {
                        cn = cn->next;
                    } while (cn->next != a[i]);

                    nn->next = cn->next;
                    cn->next->prev = nn;
                    cn->next = nn;
                    nn->prev = cn;
                }
            }
        }
    }

    void bookSeat();
    void deleteBooking();
    void display();
};

void cinema::bookSeat()
{
    int row, seat;
    cout << "\nWhich seat you want to book?(Mention Row number and Seat number):";
    cin >> row;
    cin >> seat;
    if (row > 10 || row < 0 || seat > 7 || seat < 0)
    {
        cout << "\nInvalid Seat choice";
        return;
    }

    Node *cn;
    cn = a[--row];

    for (int i = 1; i < seat; i++)
    {
        cn = cn->next;
    }
    if (cn->status == 1)
    {
        cout << "\nSorry Seat is Already Booked";
    }
    else
    {
        cn->status = 1;
        cout << "\nEnter Name:";
        cin >> cn->name;
    }

    display();
}

void cinema::deleteBooking()
{
    Node *cn;
    int row, seat;
    cout << "\nEnter row number and seat number to delete booking:";
    cin >> row >> seat;
    if (row > 10 || row < 0 || seat > 7 || seat < 0)
    {
        cout << "\nInvalid Seat choice";
        return;
    }

    cn = a[--row];
    for (int i = 1; i < seat; i++)
    {
        cn = cn->next;
    }
    if (cn->status == 0)
        cout << "\nSeat is already Free!!!";
    else
    {
        cn->status = 0;
        strcpy(cn->name, "");
        display();
    }
}

void cinema::display()
{
    cout << "\n\tS  C  R  E  E  N\tT  H  I  S\t W  A  Y\n\n";
    Node *cn;
    for (int j = 0; j < 8; j++)
        cout << j << "\t";

    cout << "\n";
    for (int k = 0; k < 8; k++)
        cout << "--------";

    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cn = a[i];
        int k = i;
        cout << ++k << "\t";
        for (int j = 0; j < 7; j++)
        {
            cout << cn->status << "\t";
            cn = cn->next;
        }
        cout << "\n";
    }
    cout << "\n----------------------------------------------------------------\n";
}

int main()
{
    cinema t;
    int ch;

    t.display();
    do
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n\t**MENU**";
        cout << "\n--------------------------";
        cout << "\n1.Book a seat\n2.Delete Booking\n3.Exit";
        cout << "\nEnter Choice:";
        cin >> ch;
        cout << "\n--------------------------";
        switch (ch)
        {
        case 1:
            t.bookSeat();
            break;
        case 2:
            t.deleteBooking();
            break;
        case 3:
            cout << "\nExiting from Menu...";
            break;
        default:
            cout << "\nxxxx Wrong Choice xxxx";
        }
    } while (ch != 3);
    return 0;
}
