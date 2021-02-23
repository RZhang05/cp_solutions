#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int cur, vector<int>adj[], int dis[], bool vis[]) {
    for(int v: adj[cur]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs(v,adj,dis,vis);
            dis[cur] += dis[v];
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, R, M; cin >> N >> R >> M;
    vector<int> adj[N+1];
    for(int i=0;i<N-1;i++) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int dis[N+1]; bool vis[N+1];
    memset(vis,false,sizeof vis);
    for(int i=0;i<=N;i++) dis[i] = 1;
    vis[R] = true;
    dfs(R, adj, dis, vis);
    sort(dis,dis+N+1);
    //for(int i=0;i<=N;i++) cout << dis[i] << endl;
    cout << dis[M] << endl;
    return 0;
}
