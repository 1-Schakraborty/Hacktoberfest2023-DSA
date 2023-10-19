// singly linkedlist
// characteristics:
/*1.Linked List can be defined as collection of objects called nodes that are randomly stored in the memory.
2.A node contains two fields i.e. data stored at that particular address and the pointer which contains the address of the next node in the memory.
3.The last node of the list contains pointer to the null.
4.The list is not required to be contiguously present in the memory. The node can reside any where in the memory and linked together to make a list. This achieves optimized utilization of space.
5.list size is limited to the memory size and doesn't need to be declared in advance.
6.Empty node can not be present in the linked list.
7.We can store values of primitive types or objects in the singly linked list.*/
//this is a menu driven program for linked list
#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Linkedlist
{
    node *head;

public:
    Linkedlist()
    {
        head = NULL;
    }
    ~Linkedlist()
    {
        node *x;
        x = head;
        while (x->next != NULL)
        {
            x = x->next;
            delete (x);
        }
        delete (x);
    }
    void insertBeg(int item);
    void insertEnd(int x);
    void deleteBeg();
    void deleteEnd();
    void insertAny(int index, int pro);
    void deleteAny(int pos);
    void lengthl();
    void display();
    void reverse();
    void scarch(int sc);
};
void Linkedlist::insertBeg(int item)
{
    node *Newnode = new node(item);
    Newnode->data = item;
    Newnode->next = head;
    head = Newnode;
}
void Linkedlist::insertEnd(int it)
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *en = new node(it);
    node *e;
    e = head;
    while (e->next != NULL)
    {
        e = e->next;
    }
    e->next = en;
    en->data = it;
    en->next = NULL;
}
void Linkedlist::deleteBeg()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *temp;
    temp = head;
    head = head->next;
    delete (temp);
}
void Linkedlist::deleteEnd()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *t;
    node *p;
    t = head;
    while (t->next != NULL)
    {
        p = t;
        t = t->next;
    }
    if (t == head)
    {
        head = NULL;
    }
    else
    {
        p->next = NULL;
    }
    delete (t);
}
void Linkedlist::insertAny(int index, int pro)
{
    if (index == 1)
    {
        insertBeg(pro);
    }
    else
    {
        node *newn = new node(pro);
        node *q;
        q = head;
        for (int i = 1; i < (index - 1); i++)
        {
            q = q->next;
        }
        newn->data = pro;
        newn->next = q->next;
        q->next = newn;
    }
}
void Linkedlist::deleteAny(int pos)
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else
    {
        if (pos == 1)
        {
            deleteBeg();
        }
        else
        {
            node *del;
            node *d;
            del = head;
            for (int i = 1; i < pos - 1; i++)
            {
                del = del->next;
            }
            d = del->next;
            del->next = del->next->next;
            delete (d);
        }
    }
}
void Linkedlist::lengthl()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *len;
    len = head;
    int count = 0;
    while (len->next != NULL) // while(len!=NULL)
    {                         //{count++;
        len = len->next;      // len=len->next
        count++;              //}
    }
    count += 1;
    cout << "the length of the linkedlist"
         << "=";
    cout << count << endl;
}
void Linkedlist::reverse()
{
    node *pre, *curr, *nex;
    pre = NULL;
    curr = nex = head;
    while (nex != NULL)
    {
        nex = nex->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
    }
    head = pre;
}
void Linkedlist::scarch(int sc)
{
    node *s;
    s = head;
    int flag = 0;
    while (s->data != sc && s->next!= NULL)
    {
        s = s->next;
        flag += 1;
    }
    if (s->data==sc)
    {
        ++flag;
        cout << "the position of scarched item"
             << "=";
        cout << flag << endl;
    }
    else
    {
        cout << "the scarched item is not found!" << endl;
    }
}
void Linkedlist::display()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *s;
    s = head;
    while (s->next != NULL)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << s->data << endl;
}

int main()
{
    Linkedlist l;
    int n, item, i;
    int index, pro, pos, sc;
    cout << "operations on linkedlist:" << endl;
    cout << "----------------------------" << endl;
    cout << "0 for EXIT"
         << endl
         << "1.insert at beginning"
         << endl
         << "2.insert at end"
         << endl
         << "3.delete from beinning"
         << endl
         << "4.delete from end"
         << endl
         << "5.insert at any position"
         << endl
         << "6.delete from any position"
         << endl
         << "7.length of the linkedlist"
         << endl
         << "8.reverse"
         << endl
         << "9.scarch an item"
         << endl
         << "10.display" << endl;
    cout << "-------------------------------" << endl;
    while (1)
    {
        cout << "enter your choice"
             << "=";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> item;
            l.insertBeg(item);
            break;
        case 2:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> i;
            l.insertEnd(i);
            break;
        case 3:
            l.deleteBeg();
            break;
        case 4:
            l.deleteEnd();
            break;
        case 5:
            cout << "enter the position where the value should be inserted"
                 << "=";
            cin >> index;
            cout << "enter the item to be inserted"
                 << "=";
            cin >> pro;
            l.insertAny(index, pro);
            break;
        case 6:
            cout << "enter the position from where the value should be deleted"
                 << "=";
            cin >> pos;
            l.deleteAny(pos);
            break;
        case 7:
            l.lengthl();
            break;
        case 8:
            l.reverse();
            break;
        case 9:
            cout << "enter the item to be scarched"
                 << "=";
            cin >> sc;
            l.scarch(sc);
            break;
        case 10:
            l.display();
            break;
        default:
            exit(99);
        }
    }
    return 0;
}
