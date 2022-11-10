#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next = nullptr;
};
node *tail = nullptr;

void insert_at_beginning(int ele)
{
    node *ptr = new node;
    ptr->data = ele;
    if (tail == nullptr){
        tail = ptr;
        tail->next = ptr;
        return;
    }
    ptr->next = tail->next;
    tail->next = ptr;
}

void insert_at_specific_pos(int ele, int pos)
{
    node *ptr = new node, *temp = tail->next;
    ptr->data = ele;
    while (pos--){
        if (pos == 1){
            ptr->next = temp->next;
            temp->next = ptr;
            if (temp == tail){
                tail = tail->next;
            }
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
    if (tail == nullptr){
        cout << "List is empty\n";
        return;
    }
    node *curr = tail->next, *prev;
    if (pos == 1){
        tail->next = curr->next;
        delete curr;
    }
    else{
        while (pos != 1){
            prev= curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        if (curr == tail){
            tail = prev;
        }
        delete curr;
    }
}

void display()
{
    node *temp = tail->next;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != tail->next){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insrt(25, 1);
    insrt(50, 1);
    insrt(75, 2);
    insrt(100, 4);
    display();
    delet(4);
    display();
    return 0;
}
