#include<iostream>
#define N 10
using namespace std;

int que[N], frnt = -1, rear = -1;

void push(int ele)
{
    if(frnt == rear+1 || (frnt == 0 && rear == N-1)){
        cout << "Queue is full\n";
        return;
    }
    if (frnt == -1)
        frnt = rear = 0;
    else if (rear == N-1)
        rear = 0;
    else
        rear++;
    que[rear] = ele;
}

void frntpop()
{
    if (frnt == -1){
        cout << "Queue is empty\n";
        return;
    }
    if (frnt == rear)
        frnt = rear = -1;
    else if (frnt == N-1)
        frnt = 0;
    else
        frnt++;
}

void rearpop()
{
    if (frnt == -1){
        cout << "Queue is empty\n";
        return;
    }
    if (frnt == rear)
        frnt = rear = -1;
    else if (rear == 0)
        rear = N-1;
    else
        rear--;
}

void display()
{
    if (frnt == -1){
        cout << "Queue is empty\n";
        return;
    }
    for(int i = frnt; i != rear; i = (i+1) % N)
        cout << que[i] << " ";
    cout << que[rear] << endl;
}

int main()
{
    push(25);
    push(75);
    push(50);
    display();
    frntpop();
    display();
    push(35);
    display();
    rearpop();
    display();
    return 0;
}
