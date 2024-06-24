#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr)
{
    // Write your code here.

    int n = arr.size();
    int i;
    int min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {

            if (arr[j] < arr[min])
            {
                int temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort(vector<int> &arr, int n)
{
    // write your code here
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(vector<int> &arr, int n)
{
    // write your code here
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MS(vector<int> &arr, int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    MS(arr, left, mid);
    MS(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{

    vector<int> input = {12, 46, 24, 53, 30, 9};
    // selectionSort(input);
    // bubbleSort(input, input.size());
    // insertionSort(input, input.size());
    int low = 0;
    int high = input.size() - 1;
    MS(input, low, high);
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
}