#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

const int MAXN=1e2+5;
priority_queue<int> Q;
vector<pii> adj[MAXN];
vector<pii> best[MAXN];
int dis[MAXN][MAXN];
int ans = numeric_limits<int>::max();

void dijk(int s) {
  Q.push(s); dis[s][s] = 0;
  while(!Q.empty()) {
    int cur = Q.top(); Q.pop();
    for(pii v: adj[cur]) {
      if(dis[s][cur] + v.second < dis[s][v.first]) {
        dis[s][v.first] = dis[s][cur] + v.second;
        dis[v.first][s] = dis[s][v.first];
        Q.push(v.first);
      } else if(dis[s][cur]+v.second==dis[s][v.first]) Q.push(v.first);
    }
  }
}

void recur(int a[], int n) {
  sort(a,a+n);
  do{
    int sum = 0; int prev = 0;
    int cnt = 0;
    for(int j=0;j<n;j++) {
      if(dis[prev][a[j]]==0) break;
      cnt++;
      sum += dis[prev][a[j]];
      prev = a[j];
    }
    if(cnt==n) ans = min(ans, sum);
  }while(next_permutation(a,a+n));
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, r; cin >> n >> r;
    for(int i=0;i<r;i++) {
      int a, b, l; cin >> a >> b >> l;
      adj[a].PB(MP(b,l));
      adj[b].PB(MP(a,l));
    }
    for(int i=0;i<MAXN;i++) {
      for(int j=0;j<MAXN;j++) {
        dis[i][j]= numeric_limits<int>::max();
      }
    }
    dijk(0);
    int invalid = numeric_limits<int>::max();
    int p; cin >> p;
    int startps[p];
    for(int i=0;i<p;i++) {
      int q; cin >> q;
      startps[i]=q;
      if(dis[0][0]!=invalid) best[0].PB(MP(q,dis[0][q]));
    }
    for(int i=0;i<p;i++) {
      int q = startps[i];
      dijk(q);
      for(int j=0;j<i;j++) {
          if(dis[q][startps[j]]!=invalid) best[q].PB(MP(startps[j],dis[q][startps[j]]));
      }
      for(int j=i+1;j<p;j++) {
          if(dis[q][startps[j]]!=invalid) best[q].PB(MP(startps[j],dis[q][startps[j]]));
      }
      if(dis[q][0]!=invalid) best[q].PB(MP(0,dis[q][0]));
    }
    recur(startps,p);
    cout << ans << '\n';
    return 0;
}
