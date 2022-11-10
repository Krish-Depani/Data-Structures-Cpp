// Priority queue using linked list
#include<iostream>
using namespace std;

class node{
public:
    int data;
    int prio;
    node *next;
};
node *head = nullptr;

void push(int ele, int prio)
{
    node *ptr = new node, *temp = head;
    ptr->prio = prio;
    ptr->data = ele;
    if (head == nullptr || prio < head->prio){
        ptr->next = head;
        head = ptr;
        return;
    }
    while (temp->next != nullptr && temp->next->prio <= prio)
        temp = temp->next;
    ptr->next = temp->next;
    temp->next = ptr;
}

void pop()
{
    if (head == nullptr){
        cout << "Queue is empty\n";
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}

void display()
{
    if (head == nullptr){
        cout << "Queue is empty\n";
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
    pop();
    push(25, 3);
    push(50, 1);
    push(75, 2);
    display();
    pop();
    display();
    push(100, 7);
    push(85, 7);
    push(35, 7);
    display();
    return 0;
}
