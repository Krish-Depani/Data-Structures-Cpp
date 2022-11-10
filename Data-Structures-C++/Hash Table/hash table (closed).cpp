#include<iostream>
#define SIZE 13
using namespace std;

void insert_element (int arr[], int value)
{
    int key = value % SIZE;
    if (arr[key] == -1)
        arr[key] = value;
    else {
        if (key < SIZE) {
            for (int i = key+1; i < SIZE; i++) {
                if (arr[i] == -1) {
                    arr[i] = value;
                    return;
                }
            }
        }
        for (int i = 0; i < key; i++) {
            if (arr[i] == -1) {
                arr[i] = value;
                break;
            }

        }
    }
}

int search_element (int arr[], int value)
{
    int key = value % SIZE;
    if (arr[key] == value)
        return key;
    else {
        if (key < 12) {
            for (int i = key+1; i < SIZE; i++) {
                if (arr[i] == value)
                    return i;
            }
        }
        for (int i = 0; i < key; i++) {
            if (arr[i] == value)
                return i;
        }
    }
    return -1;
}

void delete_element (int arr[], int value)
{
    int key = search_element(arr, value);
    cout << "\nDeleted element is " << arr[key] << endl;
    arr[key] = -1;
}

void display (int arr[])
{
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = -1;
    insert_element(arr, 234);
    insert_element(arr, 565);
    insert_element(arr, 1237);
    insert_element(arr, 6785);
    insert_element(arr, 2374);
    insert_element(arr, 9857);
    insert_element(arr, 9832);
    insert_element(arr, 2378);
    display(arr);
    cout << "\nElement 9857 is at index " << search_element(arr, 9857) << endl;
    delete_element(arr, 2378);
    display(arr);
    return 0;
}
