#include<iostream>
#define N 3
using namespace std;

int que[N], frnt = -1, rear = -1;

void push(int ele)
{
    if (rear == N-1){
        cout << "Queue is full\n";
        return;
    }
    if (frnt == -1)
        frnt = 0;
    que[++rear] = ele;
}

void pop()
{
    if (frnt == -1){
        cout << "Queue is empty\n";
        return;
    }
    frnt++;
    if (frnt > rear)
        frnt = rear = -1;
}

void display()
{
    for (int i = frnt; i <= rear; i++)
        cout << que[i] << " ";
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
    display();
    return 0;
}
