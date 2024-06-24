#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    vector<int> count;
    int tracker = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] != 1)
        {
            // cout << "came to the if seg" << endl;

            // cout << tracker << endl;
            count.push_back(tracker);
            tracker = 0;
            continue;
        }

        cout << "trcker is increased" << endl;
        tracker++;
        cout << tracker << endl;

        if (i == nums.size() - 1)
        {
            count.push_back(tracker);
        }
    }

    int max = 0;

    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }

    return max;
}

int main()
{

    vector<int> input = {1, 1, 0, 1, 1, 1};

    cout << findMaxConsecutiveOnes(input) << endl;
    return 0;
}