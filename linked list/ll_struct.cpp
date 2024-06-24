#include <bits/stdc++.h>

using namespace std;

struct node
{

public:
    int data;
    node *next;

public:
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6};

    node *y = new node(arr[0], nullptr); // new gives the pointer to the variable

    node z = node(arr[1], nullptr); // only declares the object

    cout << y->data << endl; // dot notation does not work.  Have to use arrow notation
    cout << z.data;

    // y->data it is interpreted as: at the memory location y there's a data property whose value is accessed

    return 0;
}
