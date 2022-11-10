#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next = nullptr;
};
node *top = nullptr;

void push(int ele)
{
    node *ptr = new node;
    ptr->data = ele;
    if (top == nullptr)
        top = ptr;
    else {
        ptr->next = top;
        top = ptr;
    }
}

void pop()
{
    if (top == nullptr){
        cout << "Stack Underflow\n";
	return;
    }
    node *temp = top;
    top = top->next;
    delete temp;
}

void display()
{
    if (top == nullptr){
        cout << "Stack Underflow\n";
        return;
    }
    node *temp = new node;
    temp = top;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    push(25);
    push(50);
    push(75);
    display();
    pop();
    display();
    return 0;
}
