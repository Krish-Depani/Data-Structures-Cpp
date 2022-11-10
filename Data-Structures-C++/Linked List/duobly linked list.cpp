#include<iostream>
using namespace std;

class node{
public:
    node *prev = nullptr;
    int data;
    node *next = nullptr;
};
node *head = nullptr;

void insert_at_beginning(int ele)
{
    node *ptr = new node;
    ptr->data = ele;
    if (head == nullptr){
        head = ptr;
        return;
    }
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
}

void insert_at_specific_pos(int ele, int pos)
{
    node *ptr = new node, *temp = head;
    ptr->data = ele;
    while (pos--){
        if (pos == 1){
            if (temp->next == nullptr){
                ptr->prev = temp;
                temp->next = ptr;
                return;
            }
            ptr->prev = temp;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            temp->next = ptr;
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
    if (head == nullptr){
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    if (pos == 1){
        head = head->next;
        delete temp;
    }
    else{
        while (pos != 1){
            temp = temp->next;
            pos--;
        }
        if (temp->next == nullptr){
            temp->prev->next = nullptr;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

void display()
{
    if (head == nullptr){
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insrt(25, 1);
    insrt(50, 1);
    insrt(75, 3);
    insrt(100, 2);
    display();
    delet(4);
    display();
    return 0;
}
