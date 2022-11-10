#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *left = nullptr;
    node *right = nullptr;
};

node *insert_element(node *tree, int val)
{
    if (tree == nullptr) {
        node *ptr = new node;
        ptr->data = val;
        return ptr;
    }
    tree->left = insert_element(tree->left, val);
    tree->right = insert_element(tree->right, val);
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
    node *root = new node;
    root->data = 15;
    root = insert_element(root, 23);
    root = insert_element(root, 50);
    root = insert_element(root, 30);
    root = insert_element(root, 7);
    root = insert_element(root, 2);
    root = insert_element(root, 40);
    root = insert_element(root, 25);
    root = insert_element(root, 58);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
