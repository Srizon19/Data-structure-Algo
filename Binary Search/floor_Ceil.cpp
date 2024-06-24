#include <bits/stdc++.h>

using namespace std;

int ceil(vector<int> arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return arr[mid];
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            ans = arr[mid];
            high = mid - 1;
        }
    }

    return ans;
}

int floor(vector<int> arr, int n, int x)
{
    // Write your code here

    // input::
    // 4
    // 1 2 2 3
    // 0

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return arr[mid];
        }

        else if (arr[mid] < x)
        {
            ans = arr[mid]; // it might be the answer but we don't know that. That's why storing the answer

            low = mid + 1; // as we looking for largest floor here
        }
        else
        {
            high = mid - 1; // looking for answer to the right
        }
    }

    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.

    // according to the description:
    // ceil: lowerbound:: arr[i] >= x
    // floor: arr[i] <= x

    pair<int, int> ans;

    ans.first = floor(a, n, x);

    ans.second = ceil(a, n, x);

    cout << ans.first << " " << ans.second << endl;

    return ans;
}

int main()
{
    vector<int> arr = {6, 6, 7, 12, 16, 18, 19, 22, 3, 30};

    int n = arr.size();

    int x = 14;

    pair<int, int> ans = getFloorAndCeil(arr, n, x);

    cout << ans.first << " " << ans.second;

    return 0;
}