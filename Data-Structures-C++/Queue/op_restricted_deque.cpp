#include<iostream>
#define N 3
using namespace std;

int que[N], frnt = -1, rear = -1;

void rearpush(int ele)
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

void frntpush(int ele)
{
    if(frnt == rear+1 || (frnt == 0 && rear == N-1)){
        cout << "Queue is full\n";
        return;
    }
    if (frnt == -1)
        frnt = rear = 0;
    else if (frnt == 0)
        frnt = N-1;
    else
        frnt--;
    que[frnt] = ele;
}

void pop()
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
    pop();
    rearpush(25);
    rearpush(50);
    frntpush(75);
    display();
    pop();
    display();
    frntpush(100);
    display();
    frntpush(125);
    return 0;
}
