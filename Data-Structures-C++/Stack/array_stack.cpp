#include<iostream>
#define N 3
using namespace std;

int stk[N], top = -1;

void push(int ele)
{
    if (top == N-1){
        cout << "Stack Overflow\n";
        return;
    }
    if (top == -1)
        stk[++top] = ele;
    else
        stk[++top] = ele;
}

int pop()
{
    if (top == -1){
        cout << "Stack Underflow\n";
        return 0;
    }
    int ele = stk[top--];
    return ele;
}

void display()
{
    for (int i = top; i >= 0; i--)
        cout << stk[i] << endl;
}

int main()
{
    pop();
    push(25);
    push(50);
    push(75);
    push(100);
    display();
    cout << "Element " << pop() << " is deleted\n";
    display();
    return 0;
}
