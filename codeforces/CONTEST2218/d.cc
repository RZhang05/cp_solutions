#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);

    return gcd(a, b - a);
}

void solve()
{
    int n;
    cin >> n;
    // vector<int> nums;
    for (int i = n; i >= 1; --i)
    {
        int test = ((2 * i + 1) * (2 * i + 3));
        cout << test << " ";
        // nums.push_back(test);
    }
    cout << endl;
    // for (int i = 1; i < nums.size(); ++i)
    // {
    //     cout << gcd(nums[i], nums[i - 1]) << " ";
    // }
    // cout << endl;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}