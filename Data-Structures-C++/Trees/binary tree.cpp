#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *left = nullptr;
    node *right = nullptr;
};

node* insert_element (int ele)
{
    node *ptr = new node;
    ptr->data = ele;
    return ptr;
}

void preorder (node *temp)
{
    if (temp != nullptr) {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder (node *temp)
{
    if (temp != nullptr) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void postorder (node *temp)
{
    if (temp != nullptr) {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

int main()
{
    node *root = insert_element(15);
    root->left = insert_element(23);
    root->right = insert_element(50);
    root->left->right = insert_element(7);
    root->left->left = insert_element(30);
    root->right->left = insert_element(2);
    root->right->right = insert_element(40);
    root->right->right->left = insert_element(25);
    root->right->right->right = insert_element(58);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
