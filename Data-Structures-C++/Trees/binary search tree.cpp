#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *left = nullptr;
    node *right = nullptr;
};

node *search_ele (node *temp, int val)
{
    if (temp->data == val)
        return temp;
    else
        if (val < temp->data)
            search_ele(temp->left, val);
        else
            search_ele(temp->right, val);
}

node* insert_element (node *tree, int ele)
{
    if (tree == nullptr) {
        node *ptr = new node;
        ptr->data = ele;
        return ptr;
    }
    if (ele < tree->data)
        tree->left = insert_element (tree->left, ele);
    else
        tree->right = insert_element (tree->right, ele);
}

void preorder (node *tree)
{
    if (tree != nullptr) {
        cout << tree->data << " ";
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder (node *tree)
{
    if (tree != nullptr) {
        inorder(tree->left);
        cout << tree->data << " ";
        inorder(tree->right);
    }
}

void postorder (node *tree)
{
    if (tree != nullptr) {
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data << " ";
    }
}

node* largest_node(node *tree)
{
    if (tree == nullptr || tree->right == nullptr)
        return tree;
    else
        largest_node(tree->right);
}

node* delet (node *tree, int val)
{
    if (tree == nullptr) {
        cout << "Tree is empty\n";
        return tree;
    }
    else if (val < tree->data)
        tree->left = delet(tree->left, val);
    else if (val > tree->data)
        tree->right = delet(tree->right, val);
    else {
        if (tree->left == nullptr && tree->right == nullptr) {
            delete tree;
            tree = nullptr;
            return tree;
        }
        else if (tree->left == nullptr) {
            node *temp = tree->right;
            delete tree;
            return temp;
        }
        else if (tree->right == nullptr) {
            node *temp = tree->left;
            delete tree;
            return temp;
        }
        node *temp = largest_node(tree->left);
        tree->data = temp->data;
        tree->left = delet(tree->left, temp->data);
    }
    return tree;
}

int main()
{
    node *root = new node;
    root->data = 15;
    root = insert_element(root, 13);
    root = insert_element(root, 20);
    root = insert_element(root, 7);
    root = insert_element(root, 14);
    root = insert_element(root, 18);
    root = insert_element(root, 25);
    root = insert_element(root, 23);
    root = insert_element(root, 40);
    root = insert_element(root, 16);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << "Largest node : " << largest_node(root)->data << endl;
    cout << "Element 23 is at node : " << search_ele(root, 23) << endl;
    root = delet(root, 40);
    inorder(root);
    cout << endl;
    return 0;
}
