#include <bits/stdc++.h>

using namespace std;

// have to determine majority element more than n/3

//using hashing
vector<int> majorityElement1(vector<int> v)
{
    int n = v.size();

    vector<int> ans;
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }

    int min = n / 3;
    for (auto it : mpp)
    {
        if (ans.size() <= 2 && it.second > min)
        {
            ans.push_back(it.first);
        }
    }

    return ans;
}

//optimal approach: Moore's Voting algorithm




int main()
{

    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement1(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}