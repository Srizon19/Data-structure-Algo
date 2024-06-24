#include <iostream>
#include <vector>

using namespace std;
void RecursiveBubble(vector<int> &arr, int n)
{
    // base conditon
    if (n == 1)
    {
        return;
    }

    // push the max elem to the right
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }

    // now recursive call to n-1 of arr
    RecursiveBubble(arr, n - 1);
}

int main()
{

    vector<int> arr = {13, 42, 23, 33, 3};
    RecursiveBubble(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}