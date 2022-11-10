#include<iostream>
using namespace std;

class node{
public:
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
    ptr->next = head;
    head = ptr;
}

void insert_at_specific_pos(int ele, int pos)
{
    node *ptr = new node, *temp = head;
    ptr->data = ele;
    while (pos--){
        if (pos == 1){
            ptr->next = temp->next;
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
    node *curr = head, *prev;
    if (pos == 1){
        head = head->next;
        delete curr;
    }
    else{
        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        delete curr;
    }
}

void display()
{
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
    insrt(50, 2);
    insrt(75, 1);
    insrt(100, 3);
    insrt(125, 5);
    display();
    delet(5);
    display();
    return 0;
}
