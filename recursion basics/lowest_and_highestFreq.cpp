#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> getFrequencies(vector<int> &v)
{
    // Write Your Code Here

    map<int, int> mpp;

    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }

    int max = 0;
    int min = 10000000;

    int maxElem = 0;
    int minElem = 0;

    for (auto it : mpp)
    {
        if (it.second > max)
        {
            max = it.second;
            maxElem = it.first;
        }
    }

    for (auto it : mpp)
    {
        if (it.second < min)
        {
            min = it.second;
            minElem = it.first;
        }
    }

    vector<int> result;

    result.push_back(maxElem);
    result.push_back(minElem);

    return result;
}

int main()
{
    vector<int> v = {10, 10, 10, 3, 3, 3};
    int n = 6;

    vector<int> result = getFrequencies(v);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
}