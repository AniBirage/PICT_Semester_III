/*
Second year Computer Engineering class, set A of students like Vanilla Icecream and set B of students like butterscotch ice-cream. Write C++ program 
to store two sets using linked list. compute and display- a) Set of students 
who like both vanilla and butterscotch b) Set of students who like either 
vanilla or butterscotch or not both c) Number of students who like neither 
vanilla nor butterscotch
*/

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    *x = temp;
    *x = *y;
    *y = temp;
}

class Node
{
public:
    Node *next;
    int data;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *first, *last;

class LinkedList
{
public:
    Node *head = NULL;

public:
    LinkedList() { head = NULL; }

    void insert_first(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void create(int A[], int n)
    {

        int i;
        Node *t, *last;
        first = new Node();
        first->data = A[0];
        first->next = NULL;
        last = first;

        for (i = 1; i < n; i++)
        {
            t = new Node();
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }

    void insert_pos(int data, int pos)
    {
        Node *t = new Node(data);
        Node *p = first;
        int counter = 1;

        while (counter < pos - 1 && p)
        {
            p = p->next;
            counter++;
        }
        t->next = p->next;
        p->next = t;
    }

    void insert_last(int x)
    {

        Node *new_node = new Node(x);

        Node *temp = head;

        if (head == NULL)
        {

            head = new_node;
        }

        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void delete_node(int pos)
    {
        Node *p = head;
        int i = 1;

        while (i < pos)
        {
            p = p->next;
            i++;
        }
        Node *temp = p->next->next;
        p->next->next = NULL;
        p->next = temp;
    }

    void Display2()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int count(int key)
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                counter++;
            }
            temp = temp->next;
        }

        return counter;
    }

    LinkedList inter(LinkedList l1)
    {
        Node *f1 = l1.head;
        Node *f = this->head;
        LinkedList l3;

        while (f != NULL)
        {
            if (l1.search(f->data))
            {
                l3.insert_last(f->data);
            }
            f = f->next;
        }
        return l3;
    }

    LinkedList Union(LinkedList l1)
    {
        Node *f1 = l1.head;
        Node *f = this->head;
        LinkedList l3;

        while (f != NULL)
        {
            l3.insert_last(f->data);
            f = f->next;
        }

        while (f1 != NULL)
        {
            if (!this->search(f1->data))
            {
                l3.insert_last(f1->data);
            }
            f1 = f1->next;
        }
        return l3;
    }

    LinkedList Symdiff(LinkedList l1)
    {
        Node *f1 = l1.head;
        Node *f = this->head;
        LinkedList l3;

        while (f != NULL)
        {
            if (!l1.search(f->data))
            {
                l3.insert_last(f->data);
            }
            f = f->next;
        }

        while (f1 != NULL)
        {
            if (!this->search(f1->data))
            {
                l3.insert_last(f1->data);
            }

            f1 = f1->next;
        }

        return l3;
    }

    LinkedList Neither(LinkedList unionlist, LinkedList total)
    {

        Node *u = unionlist.head;
        Node *t = total.head;

        Node *f = this->head;

        LinkedList l3;

        while (t != NULL)
        {
            if (!unionlist.search(t->data))
            {
                l3.insert_last(t->data);
            }

            t = t->next;
        }

        return l3;
    }

    int menu()
    {
        cout << "1.Both Vanilla and Butterscotch" << endl;
        cout << "2.Either Vanilla or Butterscotch but not both" << endl;
        cout << "3.Neither Vanilla nor Butterscotch" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter Choice: ";
        int c;
        cin >> c;
        return c;
    }
};

// End of class LL

int main()
{

    int data;
    string s;
    LinkedList Vanilla, Butterscotch, Both, Union_list, symdiff_list, Neither_list, Total_list;

    cout << "Total Students: " << endl;
    while (true)
    {
        cout << "Do you want to add an element (y/n): ";
        cin >> s;
        if (s == "y" || s == "Y")
        {
            cout << "Enter data: ";
            cin >> data;
            Total_list.insert_last(data);
        }
        else if (s == "n" || s == "N")
        {
            break;
        }
        else
        {
            cout << "Wrong choice" << endl;
        }
    }

    cout << "Vanilla Flavour: " << endl;
    while (true)
    {
        cout << "Do you want to add an element (y/n): ";
        cin >> s;
        if (s == "y" || s == "Y")
        {
            cout << "Enter data: ";
            cin >> data;
            if (Total_list.search(data))
            {
                Vanilla.insert_last(data);
            }
            else
            {
                cout << "Entered Data is not present in Total Students list" << endl;
            }
        }
        else if (s == "n" || s == "N")
        {
            break;
        }
        else
        {
            cout << "Wrong choice" << endl;
        }
    }

    cout << "Butterscotch Flavour: " << endl;
    while (true)
    {
        cout << "Do you want to add an element (y/n): ";
        cin >> s;
        if (s == "y" || s == "Y")
        {
            cout << "Enter data: ";
            cin >> data;
            if (Total_list.search(data))
            {
                Butterscotch.insert_last(data);
            }
            else
            {
                cout << "Entered Data is not present in Total Students list" << endl;
            }
        }
        else if (s == "n" || s == "N")
        {
            break;
        }
        else
        {
            cout << "Wrong choice" << endl;
        }
    }

    cout << "Total: ";
    Total_list.Display2();
    cout << "Vanilla: ";
    Vanilla.Display2();
    cout << "Butterscotch: ";
    Butterscotch.Display2();

    Both = Vanilla.inter(Butterscotch);

    Union_list = Vanilla.Union(Butterscotch);

    symdiff_list = Vanilla.Symdiff(Butterscotch);

    Neither_list = Vanilla.Neither(Union_list, Total_list);

    int choice = Vanilla.menu();

    while (true)
    {
        if (choice == 1)
        {
            cout << endl;
            cout << "Intersection: ";
            Both.Display2();
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            cout << "Symdiff: ";
            symdiff_list.Display2();
            cout << endl;
        }

        else if (choice == 3)
        {
            cout << endl;
            cout << "Neither: ";
            Neither_list.Display2();
            cout << endl;
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << endl;
            cout << "Wrong Choice" << endl;
        }
        choice = Vanilla.menu();
    }

    cout << "Program has ended";
    return 0;
}
