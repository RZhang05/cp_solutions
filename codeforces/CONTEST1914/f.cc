#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;

int dfs(int root, vector<vector<int>> &outEdges, vector<int> &children) {
    if(outEdges[root].size() == 0) {
        return 1;
    }
    int cnt = 1;
    for(int edge: outEdges[root]) {
        cnt += dfs(edge, outEdges, children);
    }
    children[root] = cnt;
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> outEdges;
    vector<int> children;

    for(int i=0;i<n;++i) {
        outEdges.push_back(vector<int>());
        children.push_back(0);
    }
    for(int i=0;i<n-1;++i) {
        int a;
        cin >> a;
        outEdges[a-1].push_back(i+1);
    }

    dfs(0, outEdges, children);

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(children[0], 0));
    int ans = 0;
    while(!pq.empty()) {
        auto first = pq.top();
        pq.pop();
        if(!pq.empty()) {
            ans++;
            auto second = pq.top();
            pq.pop();
            // cout << "Matched: " << first.second+1 << " with " << second.second+1 << endl;

            for(int edge: outEdges[second.second]) {
                pq.push(make_pair(children[edge], edge));
            }
        }

        for(int edge: outEdges[first.second]) {
            pq.push(make_pair(children[edge], edge));
        }
    }

    cout << ans << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}