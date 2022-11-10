#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next = nullptr;
};
node *frnt = nullptr, *rear = nullptr;

void push(int ele)
{
    node *ptr = new node;
    ptr->data = ele;
    if (frnt == nullptr && rear == nullptr)
        frnt = rear = ptr;
    rear->next = ptr;
    rear = ptr;
}

void pop()
{
    if (frnt == nullptr){
        cout << "Queue is empty\n";
        return;
    }
    node *temp = frnt;
    frnt = frnt->next;
    delete temp;
}

void display()
{
    if (frnt == nullptr){
        cout << "Queue is empty\n";
        return;
    }
    node *temp = frnt;
    while (temp != rear->next) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    pop();
    display();
    push(25);
    push(50);
    push(75);
    display();
    pop();
    display();
    return 0;
}
