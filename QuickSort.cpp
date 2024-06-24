#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partion(vector<int> &arr, int low, int high)
{

    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        // cout << "before swapping: " << arr[i] << " " << arr[j] << endl;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        // cout << "after swapping: " << arr[i] << " " << arr[j] << endl;
    }

    swap(arr[j], arr[low]);

    // cout << "returned partition: " << j;
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partion_I = partion(arr, low, high);
        quickSort(arr, low, partion_I - 1);
        quickSort(arr, partion_I + 1, high);
    }
}

int main()
{
    vector<int> arr = {13, 42, 23, 33, 3};

    quickSort(arr, 0, arr.size() - 1);

    for (int p = 0; p < arr.size(); p++)
    {
        cout << arr[p] << " ";
    }

    cout << endl;
    return 0;
    return 0;
}