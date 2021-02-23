#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> trip;

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
vector<trip> adj[MAXN];
ull dis[MAXN];
queue<int> Q;

void bfs(int s) {
  Q.push(s);
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(trip v: adj[cur]) {
      int des = v.first; pii det = v.second;
      if(det.first==0) dis[des]+=det.second;
      else dis[des] *= det.second;
      Q.push(des);
    }
  }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for(int i=0;i<k;i++) {
      int a, b, c; char op; cin >> a >> b >> op >> c;
      int o = 0;
      if(op=='*') o = 1;
      adj[a].pb(mp(b,mp(o,c)));
    }
    int q; cin >> q;
    for(int i=0;i<q;i++) {
      int a, b; cin >> a >> b;
      dis[a] += b;
      bfs(a);
    }
    for(int i=1;i<=n;i++) cout << dis[i] << " ";
    cout << endl;
    return 0;
}
