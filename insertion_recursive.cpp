#include <iostream>
#include <vector>

using namespace std;

void RecursionInsertion(vector<int> &arr, int i, int n)
{

    // base condition
    if (i == n)
    {
        return;
    }

    // move the selected element to the left in its correct position
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    RecursionInsertion(arr, i + 1, n);
}

int main()
{

    vector<int> arr = {13, 42, 23, 33, 3};
    RecursionInsertion(arr, 0, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
