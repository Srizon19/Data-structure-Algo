#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{

    // brute force
    int first = -1;
    int last = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << "before if scope first: " << first << endl;
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
                cout << "first: " << first << endl;
            }
            last = i;
            cout << "last: " << last << endl;
        }
    }

    return {first, last};
}

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};

    vector<int> ans = searchRange(arr, 8);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}