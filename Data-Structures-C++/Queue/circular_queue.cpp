#include<iostream>
#define N 3
using namespace std;

int que[N], frnt = -1, rear = -1;

void push(int ele)
{
    if (frnt == rear+1 || (frnt == 0 && rear == N-1)){
        cout << "Queue is full\n";
        return;
    }
    if (frnt == -1)
        frnt = 0;
    rear = (rear+1) % N;
    que[rear] = ele;
}

void pop()
{
    if (frnt == -1){
        cout << "Queue is empty\n";
        return;
    }
    if (frnt == rear)
        frnt = rear = -1;
    else
        frnt = (frnt+1) % N;
}

void display()
{
    if (frnt == -1){
        cout << "Queue is empty\n";
        return;
    }
    for (int i = frnt; i != rear; i = (i+1) % N)
        cout << que[i] << " ";
    cout << que[rear];
    cout << endl;
}

int main()
{
    push(25);
    push(50);
    push(75);
    push(100);
    display();
    pop();
    push(100);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}
