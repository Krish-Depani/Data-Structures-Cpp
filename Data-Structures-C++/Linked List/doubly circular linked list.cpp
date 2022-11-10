#include<iostream>
using namespace std;

class node{
public:
    node *prev = nullptr;
    int data;
    node *next = nullptr;
};
node *tail = nullptr;

void insert_at_beginning(int ele)
{
    node *ptr = new node;
    ptr->data = ele;
    if (tail == nullptr){
        ptr->next = ptr;
        ptr->prev = ptr;
        tail = ptr;
        return;
    }
    ptr->prev = tail;
    ptr->next = tail->next;
    tail->next->prev = ptr;
    tail->next = ptr;
}

void insert_at_specific_pos(int ele, int pos)
{
    node *ptr = new node, *temp = tail->next;
    ptr->data = ele;
    while (pos --){
        if (pos == 1){
            ptr->prev = temp;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            temp->next = ptr;
            if (temp == tail)
                tail = tail->next;
            return;
        }
        temp = temp->next;
    }
}

void insrt(int ele, int pos)
{
    if (pos == 1){
        insert_at_beginning(ele);
        return;
    }
    insert_at_specific_pos(ele, pos);
}

void delet(int pos)
{
    if (tail == nullptr){
        cout << "List is empty\n";
        return;
    }
    node *temp = tail->next;
    if (pos == 1){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
    else {
        while (pos != 1) {
            temp = temp->next;
            pos--;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == tail)
            tail = tail->prev;
        delete temp;
    }
}

void display()
{
    node *temp = tail->next;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != tail->next){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insrt(25, 1);
    insrt(50, 1);
    insrt(75, 2);
    insrt(100, 4);
    display();
    delet(3);
    display();
    return 0;
}
