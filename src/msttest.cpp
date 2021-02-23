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
const int MAXN = 1e6+5;

int par[MAXN];
int rnk[MAXN];
vector<trip> edges;

void make(int v) {
  par[v] = v;
  rnk[v] = 0;
}

int fnd(int v) {
  if(v==par[v]) return v;
  return par[v] = fnd(par[v]);
}

void uni(int a, int b) {
  a = fnd(a); b = fnd(b);
  if(a!=b) {
    if(rnk[a]>rnk[b]) swap(a,b);
    par[b]=a;
    if(rnk[a]==rnk[b]) rnk[a]++;
  }
}

int mst() {
  int sum = 0;
  for(trip cur: edges) {
    pii s = cur.second;
    //cout << "CHECK: " << cur.first << endl;
    int u = fnd(s.first); int v = fnd(s.second);
    if(u!=v) {
      uni(u,v);
      sum += cur.first;
      //cout << "DIS: " << cur.first << endl;
    }
  }
  return sum;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++) make(i);
    for(int i=0;i<m;i++) {
      int a, b, c; cin >> a >> b >> c;
      edges.pb(mp(c,mp(a,b)));
    }
    sort(edges.begin(),edges.end());
    cout << mst() << endl;
    return 0;
}
