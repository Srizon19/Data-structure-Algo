#include <iostream>
#include <vector>
#include <string>

using namespace std;

void oneToN(int n)
{
    // base case
    if (n < 1)
    {
        return;
    }

    oneToN(n - 1);
    cout << n;
}

void reverseOnetoN(int n)
{

    // base case
    if (n < 1)
    {
        return;
    }

    cout << n;
    reverseOnetoN(n - 1);
}

void reverseAnArray(vector<int> &a, int i)

{
    // base case
    if (i >= a.size() / 2)
    {
        return;
    }
    swap(a[i], a[a.size() - i - 1]);
    reverseAnArray(a, i + 1);
}

bool RecursivePalindrome(string s, int i)
{

    // base case
    if (i >= s.size() / 2)
    {
        return true;
    }

    else if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }

    return RecursivePalindrome(s, i + 1);
}

int main()
{
    // oneToN(5);
    // cout << endl;
    // reverseOnetoN(5);

    // vector<int> arr = {1, 2, 3, 4, 5};

    // reverseAnArray(arr, 0);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    bool result = RecursivePalindrome("CAR", 0);

    cout << result << endl;

    return 0;
}