#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int breakPoint = -1;

    // find the breaking point
    for (int i = n - 2; i >= 0; i--)
    {

        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }

    cout << breakPoint << endl;

    // handle the case if there is no breaking point
    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // need to find the smallest in brp+1 to n-1
    for (int i = n - 1; i > breakPoint; i--)
    {
        if (nums[i] > nums[breakPoint])
        {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }

    // then sort in the increasing order from break+1 to n-1 or just reverse the rest

    reverse(nums.begin() + breakPoint + 1, nums.end());
}

int main()
{

    vector<int> input = {3, 2, 1};

    nextPermutation(input);

    for (int i = 0; i < input.size(); i++)
    {

        cout << input[i] << " ";
    }

    return 0;
}