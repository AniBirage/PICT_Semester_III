/*
A double-ended queue (deque) is a linear list in which
additions and deletions may be
made at either end. Obtain a data representation mapping a
deque into a one
dimensional array. Write C++ program to simulate deque
with functions to add and
delete elements from either end of the deque.
*/

#include <iostream>
using namespace std;

class deq
{
    int a[10];
    int front, rear;

public:
    void fpush(int);
    void rpush(int);
    void fpop();
    void rpop();
    void disp();

    deq()
    {
        front = rear = -1;
    }
};

void deq::fpush(int x)
{
    if (front == -1)
    {
        front = rear = 0;
        a[front] = x;
    }
    else if (rear > 9)
    {
        cout << "Dequeue full !";
        return;
    }
    else
    {
        rear++;
        int i = 1;
        int j = 0;
        while (rear - i != front - 1)
        {
            a[rear - j] = a[rear - i];
            i++;
            j++;
        }
        a[front] = x;
    }

    cout << "Element added. \n";
}

void deq::rpush(int x)
{
    if (front == -1)
    {
        front = rear = 0;
        a[front] = x;
    }
    else
    {
        rear++;
        if (rear > 9)
        {
            cout << "Dequeue full !";
            return;
        }
        else
        {

            a[rear] = x;
        }
    }

    cout << "Element added. \n";
}

void deq::disp()
{
    int temp = front;
    while (temp != rear + 1)
    {
        cout << a[temp] << "\n";
        temp++;
    }
}

void deq::rpop()
{
    if (front == -1)
    {
        return;
    }
    else
    {
        rear--;
    }

    cout << "Element deleted. \n";
}

void deq::fpop()
{
    if (front == -1)
    {
        return;
    }

    else
    {
        int i = 1;
        int j = 0;
        while (front + i != rear + 1)
        {
            a[front + j] = a[front + i];
            i++;
            j++;
        }
        rear--;
    }

    cout << "Element deleted. \n";
}

int main()
{
    int n;
    char c;
    deq q1;

    do
    {

        cout << "Enter the choice" << endl;
        cout << "1.Push rear\n"
             << "2.Push front\n"
             << "3.Display\n"
             << "4.Del from rear\n"
             << "5.Del from front\n";
        cin >> n;
        int a;
        switch (n)
        {
        case 1:
            cout << "Enter the element to be added\n";
            cin >> a;
            q1.rpush(a);

            break;

        case 2:
            cout << "Enter the element to be added\n";
            cin >> a;
            q1.fpush(a);

            break;

        case 3:
            cout << "\nThe elements in the dequeue are:\n";
            q1.disp();
            break;

        case 4:
            q1.rpop();
            break;

        case 5:
            q1.fpop();
            break;

        default:
            cout << "Wrong choice!!\n";
        }
        cout << "Do you want to continue ?  (y/n)";
        cin >> c;
    }

    while (c == 'y');

    return 0;
}