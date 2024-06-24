#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// int missingNumber(vector<int> &nums)
// {
//     unordered_map<int, int> map;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         map[nums[i]]++;
//     }

//     if (map[nums.size()] ==)

//         for (int i = 0; i < map.size(); i++)
//         {
//             cout << map[i] << " ";
//         }

//     cout << endl;

//     for (auto it : map)
//     {
//         if (it.second == 0)
//         {
//             return it.first;
//         }
//     }

//     return -1;
// }

int missingNumberWithSum(vector<int> &nums)
{

    int n = nums.size();
    int sum = n * (n + 1) / 2;

    cout << "SUM: " << sum << endl;

    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum2 = sum2 + nums[i];
    }

    cout << "SUM2: " << sum2 << endl;

    return sum - sum2;
}

int main()
{
    vector<int> input = {3, 0, 1};

    cout << "resutl is: " << missingNumberWithSum(input);
    return 0;
}