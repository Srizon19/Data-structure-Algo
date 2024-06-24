#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    // Write your code here.
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {

        mpp[nums[i]]++;
    }

    vector<int> result;

    for (int i = 1; i <= n; i++)
    {
        result.push_back(mpp[i]);
    }

    // for (auto it : mpp)
    // {
    //     result.push_back(it.second);
    // }

    return result;
}

int main()
{

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // // pre-compute
    // map<int, int> mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     mpp[arr[i]]++;
    // }

    // // iterate the map

    // for (auto it : mpp)
    // {
    //     cout << it.first << "-->" << it.second << endl;
    // }

    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int number;
    //     cin >> number;

    //     // fetch
    //     cout << mpp[number] << endl;
    // }

    // character hashing

    // string s = "madam";

    // unordered_map<char, int> charMap;

    // for (int i = 0; i < s.size(); i++)
    // {
    //     charMap[s[i]]++;
    // }

    // // iterating throgh the map

    // for (auto it : charMap)
    // {
    //     cout << it.first << "-->" << it.second << endl;
    // }

    vector<int> arr = {1, 3, 4, 3, 4, 1};

    vector<int> result = countFrequency(6, 4, arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}