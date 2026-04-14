#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            ans = max(ans, nums[i] ^ nums[j]);
        }
    }
    cout << ans << endl;
}

//// 1, 2, 3, 4, 5

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}