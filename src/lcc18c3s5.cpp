#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int T; cin >> T;
  for(int k=0;k<T;k++) {
    int N, M; cin >> N >> M;
    vector<int> adj[N+1];
    for(int i=0;i<M;i++) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B); adj[B].push_back(A);
    }
    queue<int> Q; bool vis[N+1];
    string path[N+1];
    memset(vis, false, sizeof vis);
    Q.push(1);vis[1] = true; path[1] = "1";
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int v: adj[cur]) {
            if(!vis[v]) {
                vis[v] = true;
                path[v] = path[cur] + " " + to_string(v);
                Q.push(v);
            }
        }
    }
    // cout << path[N] << endl;
    if(!vis[N]) cout << "No" << endl;
    else {
        Q.push(1); bool vis2[N+1]; memset(vis2, false, sizeof vis2);
        vis2[1] = true;
        unordered_map<string, int> hm;
        int prev = 0;
        for(int i=0;i<path[N].length();i++) {
            // cout << path[N].at(i) << endl;
            if(path[N].substr(i,1).compare(" ")==0) {
                string S = path[N].substr(prev,i-prev);
                hm.insert({S,1});
                //cout << path[N].substr(prev, i-prev) << endl;
                prev = i+1;
            }
        }

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int v: adj[cur]) {
                if(!vis2[v] && hm.find(to_string(v))==hm.end()) {
                    //cout << v << endl;
                    vis2[v] = true;
                    Q.push(v);
                }
            }
        }
        if(vis2[N]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
  }

  return 0;
}
