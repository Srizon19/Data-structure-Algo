#include <iostream>
#include <vector>

using namespace std;

static int count = 1;
vector<int> result;

vector<int> noLoopNums(int n)
{

    // base condition

    if (count == n)
    {
        // cout << "reached base condition: " << count;
        return result;
    }

    // cout << "count status: " << count;

    result.push_back(count);
    count++;
    noLoopNums(n);
    return result;
}

void reverseAnArray(vector<int> &a, int i)
{
    int temp = a[i];
    a[i] = a[a.size() - i - 1];
    a[a.size() - i - 1] = temp;
    reverseAnArray(a, i + 1);
}

int main()
{
    // oneToN(5);
    // cout << endl;
    // reverseOnetoN(5);

    vector<int> array;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    reverseAnArray(array, 0);

    for (int i = 0; i < n; i++)
    {
        cout << array[i];
    }
}