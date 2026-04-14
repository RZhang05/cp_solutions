#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

long long MOD = 676767677;

void solve()
{
    int n, m;
    cin >> n >> m;

    // people: 4 time : 3
    // 0 1 2 0
    // time, possibilities, number of people sat
    // 0, 1, 2
    // 1, previous of num people sat * poss = 2, 3
    // 2, (diff between previous number of people sat) * poss = 2, 4

    // psa sat: [0,2,3,4]

    // possible arrays at time 0: 1= [0, x, x, 0]
    // time 1: 2= [0,(1,2),x,0]

    // 9 5
    // 1 0 1 3 4 3 2 1 0

    // how many people have sat down before time t
    // psa: [0,2,5,6,8,9]

    // time 0: 1 possibility
    // time 1: 8 possibilities,
    // for each of the three people who sat down -> they can use any of the 2 numbers available at time 0 -> psa[1] - psa[0]
    // time 2: 40 possibilities
    // 1 guy has 5 numbers available (psa[2])
    // time 3: 240
    // one person has 1 possibilities, one person has 6?
    // time 4: 1920
    // 1 guy with 8 possiblities

    // if the only person next to you sat down right before u -> psa[t of that person]
    // otherwise psa[t] - psa[t-1]

    vector<long long> psa(m + 1, 0);
    vector<int> order;
    vector<vector<int>> satRightBefore(m, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        psa[num + 1]++;
        order.push_back(num);
    }

    for (int i = 0; i < n; ++i)
    {
        int leftSeat = 1000000;
        int rightSeat = 1000000;
        if (i != 0)
        {
            leftSeat = order[i - 1];
        }
        if (i != n - 1)
        {
            rightSeat = order[i + 1];
        }
        // impossible ordering
        if (order[i] <= leftSeat && order[i] <= rightSeat && order[i] != 0)
        {
            cout << "0" << endl;
            return;
        }
        int lowestNeightbour = min(leftSeat, rightSeat);
        satRightBefore[order[i]].push_back(lowestNeightbour);
    }

    for (int i = 1; i <= m; ++i)
    {
        psa[i] += psa[i - 1];
    }

    long long possibilities = 1;
    for (int i = 1; i < m; ++i)
    {
        for (int t : satRightBefore[i])
        {
            possibilities *= t == i - 1 ? psa[i] : psa[i] - psa[i - 1];
            possibilities %= MOD;
        }
    }
    possibilities %= MOD;
    cout << possibilities << endl;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}