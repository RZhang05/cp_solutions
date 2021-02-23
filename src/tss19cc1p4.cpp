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
#define MOD 998244353
#define mp make_pair
#define endl '\n'
const int MAXN = 3e5+5;

int seg[4*MAXN];
vector<int> adj[MAXN];
int dis[MAXN];
bool vis[MAXN];

void build(int v[], int cur, int l, int r) {
  if(l==r) seg[cur]=v[l];
  else {
    int m = (l+r)/2;
    build(v,cur*2,l,m);
    build(v,cur*2+1,m+1,r);
    v[cur]=(v[cur*2]%MOD+v[cur*2+1]%MOD)%MOD;
  }
}

int query(int v, int curl, int curr, int l, int r) {
  if(r<curl||curr<l) return 0;
  if(l==curl&&r==curr) return seg[v];
  int m = (l+r)/2;
  return (sum(v*2,curl,m,l,min(r,m))%MOD + sum(v*2+1,m+1,curr,max(l,m+1),r)%MOD)%MOD;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;
    for(int i=0;i<N-1;i++) {
      int u, v; cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    queue<int> Q;
    Q.push(1); vis[1] = true;
    while(!Q.empty()) {
      int cur = Q.front();Q.pop();
      for(int v: adj[cur]) {
        if(!vis[v]) {
          vis[v] = true;
          dis[v] = dis[cur]+1;
          Q.push(v);
        }
      }
    }
    build(dis,1,0,N-1);
    int Q; cin >> Q;
    for(int i=0;i<Q;i++) {
      int u, v, k; cin >> u >> v >> k;
    }
    return 0;
}

