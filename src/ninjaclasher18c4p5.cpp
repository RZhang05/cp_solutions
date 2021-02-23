#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

    int N, M, A, B; cin >> N >> M >> A >> B;
    vector<pii> adj[N+1];
    for(int i=0;i<M;i++) {
        int a, b; cin >> a >> b;
       adj[a].PB(MP(b,i+1));
    }
    queue<int> Q; bool vis[N+1];
    string path[N+1];
    vector<string> potent;
    memset(vis, false, sizeof vis);
    Q.push(A);vis[A] = true; path[A] = "0";
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(pii v: adj[cur]) {
            if(!vis[v.first]) {
                vis[v.first] = true;
                path[v.first] = path[cur] + " " + to_string(v.second);
                Q.push(v.first);
            } else if(v.first==B) {
              potent.PB(path[cur] + " " + to_string(v.second));
            }
        }
    }
    //cout << path[B] << endl;
    //for(int i=0;i<potent.size();i++) cout << potent[i] << endl;
    if(!vis[B]) cout << "NO PATH" << endl;
    else {
        Q.push(A); bool vis2[N+1]; memset(vis2, false, sizeof vis2);
        vis2[A] = true;
        path[B] += " ";
        unordered_map<string, int> hm;
        int prev = 2;
        for(int i=2;i<path[B].length();i++) {
            // cout << path[N].at(i) << endl;
            if(path[B].substr(i,1).compare(" ")==0) {
                string S = path[B].substr(prev,i-prev);
                hm.insert({S,1});
                //cout << path[B].substr(prev, i-prev) << endl;
                prev = i+1;
            }
        }
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(pii v: adj[cur]) {
                if(!vis2[v.first] && hm.find(to_string(v.second))==hm.end()) {
                    //cout << v.second << endl;
                    vis2[v.first] = true;
                    Q.push(v.first);
                }
            }
        }
        if(vis2[B]) cout << "YES" << endl;
        else {
            if(potent.size()>0) {
              unordered_map<string, int> hm;
              for(int j=0;j<potent.size();j++) {
                string S = potent[j];
                int prev = 2;
                for(int i=2;i<S.length();i++) {
                    // cout << path[N].at(i) << endl;
                    if(S.substr(i,1).compare(" ")==0) {
                        string P = S.substr(prev,i-prev);
                        hm.insert({P,1});
                        //cout << path[B].substr(prev, i-prev) << endl;
                        prev = i+1;
                    }
                }
              }
              Q.push(A);
              memset(vis2, false, sizeof vis2);
              while(!Q.empty()) {
                  int cur = Q.front(); Q.pop();
                  for(pii v: adj[cur]) {
                      if(!vis2[v.first] && hm.find(to_string(v.second))==hm.end()) {
                          //cout << v.second << endl;
                          vis2[v.first] = true;
                          Q.push(v.first);
                      }
                  }
              }
            }
            if(vis2[B]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
  }

  return 0;
}
