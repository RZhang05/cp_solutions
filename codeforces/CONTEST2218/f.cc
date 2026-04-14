#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

void solve()
{
    int x, y;
    cin >> x >> y;
    // more even than odd is impossible
    if (x > y)
        cout << "NO" << endl;
    else
    {
        int genEven = 0;
        int genOdd = 0;
        if ((x + y) % 2 == 0)
        {
            genEven = 1;
        }
        else
        {
            genOdd = 1;
        }
        vector<pair<int, int>> edges;
        int curNode = 2;
        while (genEven < x)
        {
            edges.push_back(make_pair(1, curNode));
            edges.push_back(make_pair(curNode, curNode + 1));
            curNode += 2;
            genOdd++;
            genEven++;
        }
        while (genOdd < y)
        {
            edges.push_back(make_pair(1, curNode));
            curNode++;
            genOdd++;
        }
        if (genEven != x || genOdd != y)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (auto p : edges)
            {
                cout << p.first << " " << p.second << endl;
            }
        }
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}