#include<iostream>
#include<list>
using namespace std;

class hashtable{
    list<int> *table;
    int capacity;
public:
    hashtable(int c)
    {
        capacity = get_prime(c);
        table = new list<int>[capacity];
    }
    int check_prime(int n);
    int get_prime(int n);
    void insrt(int value);
    void delet(int key);
    void display();
    int hash_function(int value);
    ~hashtable()
    {
        delete[] table;
    }
};

int hashtable ::check_prime (int n)
{
    if (n == 0 || n == 1)
        return 0;
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int hashtable ::get_prime (int n)
{
    if (n % 2 == 0)
        n++;
    while (!check_prime(n))
        n += 2;
    return n;
}

int hashtable ::hash_function(int value)
{
    return value % capacity;
}

void hashtable ::insrt(int value)
{
    table[hash_function(value)].push_back(value);
}

void hashtable ::delet(int key)
{
    int index = hash_function(key);
    list<int> ::iterator i;

    for (i = table[index].begin(); i != table[index].end(); i++){
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}

void hashtable ::display()
{
    for (int i = 0; i < capacity; i++) {
        cout << i << " : ";
        for (int a : table[i])
            cout << "--> " << a;
        cout << endl;
    }
}

int main()
{
    int x[] = {11, 22, 33, 44, 55, 66, 77};
    int siz = sizeof(x)/sizeof(x[0]);
    hashtable H(siz);

    for (int i = 0; i < siz; i++)
        H.insrt(x[i]);

    H.display();

    H.delet(33);

    H.display();

    return 0;
}
