#include <bits/stdc++.h>

using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    long long n = a.size();
    cout << "n: " << n << endl;
    long long sum = 0;
    long long sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (long long)a[i];
        sum2 = sum2 + (long long)a[i] * (long long)a[i];
    }

    cout << "sum: " << sum << "sum2: " << sum2 << endl;

    long long sumN = (n * (n + 1)) / 2;
    long long sum2N = (n * (n + 1) * (2 * n + 1)) / 6;

    cout << "sumN: " << sumN << "sum2N: " << sum2N << endl;

    long long val1 = sum - sumN;            // x - y
    long long val2 = (sum2 - sum2N) / val1; // (x + y) = (S^2 - Sn^2) / (x - y)

    cout << "val1:" << val1 << " "
         << " val2: " << val2 << endl;

    long long x = (val1 + val2) / 2; // x = (x - y + x + y) / 2

    cout << "x: " << x << endl;
    long long y = x - val1;
    // y = x - (x - y)

    cout << "y: " << y << endl;

    return {(int)x, (int)y};
}

int main()
{

    vector<int> input = {4, 3, 6, 2, 1, 1};

    vector<int> ans = findMissingRepeatingNumbers(input);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}