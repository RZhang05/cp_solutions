#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define MOD 1000000007
#define mp make_pair
#define endl '\n'
const int MAXN = 1e5+5;
vector<int> adj[MAXN];
int cnt[MAXN]; int dis[MAXN];
bool vis[MAXN]; bool vis2[MAXN];
unordered_map<int, int> m;
queue<int> Q;

int bfs(int s) {
  Q.push(s); vis[s] = true;
  int ans = 0;
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(int v: adj[cur]) {
      if(!vis[v] && !vis2[v]) {
        vis[v] = true;
        dis[v] = dis[cur]+1;
        Q.push(v);
        ans = v;
      }
    }
  }
  return ans;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int s = 0;
    for(int i=0;i<M;i++) {
        int a; cin >> a;
        s = a;
        m.insert({a,1});
    }
    for(int i=0;i<N-1;i++) {
      int a, b; cin >> a >> b;
      adj[a].pb(b); adj[b].pb(a);
      cnt[a]++; cnt[b]++;
    }
    for(int i=0;i<N;i++) {
      if(cnt[i]==1 && m.count(i)==0) {
          vis2[i] = true;
      }
    }
    cout << "VIS: ";
    for(int i=0;i<N;i++) cout << vis2[i] << " ";
    cout << endl;
    int d = bfs(s);
    cout << "CHECK: " << d << endl;
    memset(vis, false, sizeof vis);
    for(int i=0;i<MAXN;i++) dis[i] = 0;
    int v = bfs(d);
    cout << "CHECK: " << v << endl;
    cout << dis[v] << endl;
    return 0;
}

