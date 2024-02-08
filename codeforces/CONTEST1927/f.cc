#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;

void dfs(int cur, vector<pair<int,int>> &path, vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &minCycle, vector<int> &minPath) {
    vis[cur] = 1;
    // cout << "CHECK AT: " << cur << endl;
    for(pair<int,int> edge : adj[cur]) {
        if(path.size() >= 2 && edge.first == path[path.size()-2].first) continue;   // skip backward edge
        if(vis[edge.first] == 1) {
            // cycle
            int cycleDis = INT_MAX;
            cycleDis = min(cycleDis, edge.second);
            for(int i=path.size()-1;i>=0;--i) {
                if(path[i].first == edge.first) break;
                cycleDis = min(cycleDis, path[i].second);
            }

            // cout << "FOUND A CYCLE with dis " << cycleDis << endl;
            if(cycleDis < minCycle) {
                minPath.clear();
                for(int i=path.size()-1;i>=0;--i) {
                    minPath.push_back(path[i].first);
                    if(path[i].first == edge.first) break;
                }
                minCycle = cycleDis;
            }
        } else if(vis[edge.first] != 2) {
            path.emplace_back(edge.first, edge.second);
            dfs(edge.first, path, adj, vis, minCycle, minPath);
            path.pop_back();
        }
    }
    vis[cur] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    for(int i=0;i<=n;++i) {
        adj.push_back(vector<pair<int,int>>());
        vis.push_back(0);
    }
    for(int i=0;i<m;++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u,w);
    }
    int minCycle = INT_MAX;
    vector<int> minPath;
    vector<pair<int, int>> path;
    for(int i=1;i<=n;++i) {
        if(vis[i] != 2) {
            path.emplace_back(i, -1);
            dfs(i, path, adj, vis, minCycle, minPath);
            path.pop_back();
        }
    }
    cout << minCycle << " " << minPath.size() << endl;
    for(int i=0;i<minPath.size();++i) {
        cout << minPath[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}