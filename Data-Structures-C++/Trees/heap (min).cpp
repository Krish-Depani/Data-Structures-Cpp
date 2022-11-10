#include<iostream>
using namespace std;

class heap {
public:
    int *harr;
    int capacity;
    int heap_size;
    heap (int c)
    {
        capacity = c;
        harr = new int[capacity];
        heap_size = 0;
    }
};

int parent (int i) { return (i-1)/2; }

int left_child (int i) { return 2*i+1; }

int right_child (int i) { return 2*i+2; }

void swap_no(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insert_element (heap &H, int value)
{
    if (H.heap_size == H.capacity) {
        cout << "\nHeap overflow\n";
        return;
    }
    H.heap_size++;
    int i = H.heap_size-1;
    H.harr[i] = value;
    while (i != 0 && H.harr[parent(i)] > H.harr[i]) {
        swap_no(H.harr[parent(i)], H.harr[i]);
        i = parent(i);
    }
}

void display (heap H)
{
    if (H.heap_size == 0) {
        cout << "\nHeap underflow\n";
        return;
    }
    for (int i = 0; i < H.heap_size; i++)
        cout << H.harr[i] << " ";
    cout << endl;
}

void heapify(heap &H, int i)
{
    int l = left_child(i);
    int r = right_child(i);
    int smallest = i;
    if (l < H.heap_size && H.harr[l] < H.harr[smallest])
        smallest = l;
    if (r < H.heap_size && H.harr[r] < H.harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap_no(H.harr[smallest], H.harr[i]);
        heapify(H, smallest);
    }
}

int extract_min (heap &H)
{
    if (H.heap_size == 1) {
        H.heap_size--;
        return H.harr[0];
    }
    int mini = H.harr[0];
    H.harr[0] = H.harr[H.heap_size-1];
    H.heap_size--;
    heapify(H, 0);
    return mini;
}

void decrease_key(int i, heap &H)
{
    H.harr[i] = -23434;
    while (i != 0 && H.harr[parent(i)] > H.harr[i]) {
        swap_no(H.harr[parent(i)], H.harr[i]);
        i = parent(i);
    }
}

void delete_key(heap &H, int i)
{
    decrease_key(i, H);
    extract_min(H);
}

int main()
{
    cout << "\nEnter the size of heap : ";
    int n;
    cin >> n;
    heap H(n);
    insert_element(H, 15);
    insert_element(H, 25);
    insert_element(H, 24);
    insert_element(H, 36);
    insert_element(H, 30);
    insert_element(H, 28);
    insert_element(H, 35);
    display(H);
    cout << "\nMin (root node) is " << extract_min(H) << endl;
    display(H);
    delete_key(H, 1);
    display(H);
    return 0;
}
