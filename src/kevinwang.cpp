#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> trip;

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
const int MAXN = 1e4+5;
vector<trip> edges;
int par[MAXN]; int rnk[MAXN];
vector<pii> adj[MAXN];
bool vis[MAXN];

void make(int v) {
  par[v] = v;
  rnk[v] = 0;
}

int fnd(int v) {
  if(par[v]==v) return v;
  return par[v]=fnd(par[v]);
}

void uni(int a, int b) {
  a = fnd(a); b = fnd(b);
  if(a!=b) {
    if(rnk[a]>rnk[b]) swap(a,b);
    par[b]=a;
    if(rnk[a]==rnk[b])rnk[a]++;
  }
}

void mst() {
  for(trip cur: edges) {
    pii cur2 = cur.second;
    if(vis[cur2.first]||vis[cur2.second]) continue;
    int u = fnd(cur2.first); int v = fnd(cur2.second);
    if(u!=v) {
      uni(u,v);
      adj[cur2.first].pb(mp(cur2.second,cur.first));
      adj[cur2.second].pb(mp(cur2.first,cur.first));
    }
  }
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i=1;i<=n;i++) make(i);
  for(int i=0;i<m;i++) {
    int u, v , w; cin >> u >> v >> w;
    edges.pb(mp(w,mp(u,v)));
  }
  int x; cin >> x;
  for(int i=0;i<x;i++) {
    int v; cin >> v;
    vis[v] = true;
  }
  sort(edges.rbegin(),edges.rend());
  mst();
  int ans = 0;
  queue<int> q;
  q.push(1); vis[1] = true;
  rnk[1] = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    //cout << "CHECK: " << cur << endl;
    for(pii v: adj[cur]) {
      if(!vis[v.first]) {
        rnk[v.first]=rnk[cur]+v.second;
        vis[v.first] = true;
        ans = max(ans,rnk[v.first]);
        q.push(v.first);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
