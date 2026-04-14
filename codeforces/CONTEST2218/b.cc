#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

void solve()
{
    int sum = 0;
    int maxA = -70;

    for (int i = 0; i < 7; ++i)
    {
        int a;
        cin >> a;
        maxA = max(maxA, a);
        sum -= a;
    }

    sum += 2 * maxA;
    cout << sum << endl;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}