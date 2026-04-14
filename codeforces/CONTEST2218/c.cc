#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

void solve()
{
    int n;
    cin >> n;
    int l = 0;
    int h = 3 * n;
    for (; l < n; ++l)
    {
        cout << (l + 1) << " " << (h - 2 * l) << " " << (h - (2 * l + 1)) << " ";
    }
    cout << endl;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}