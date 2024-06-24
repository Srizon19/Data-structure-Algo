#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{

    unordered_map<int, int> mpp;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (sum == k)
        {
            count++;
        }

        else
        {
            if (mpp.find(sum - k) != mpp.end())
            {
                count++;
            }
            else
            {
                mpp[sum - k]++;
            }
        }
    }

    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }

    return count;
}

int main()
{

    vector<int> num = {1, 2, 3};
    int k = 3;
    int result = subarraySum(num, k);

    cout << "result is: " << result;

    return 0;
}