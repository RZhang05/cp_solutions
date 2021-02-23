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
const int MAXN = 1e5+5;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++) {
      int a, b; cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    bool vis[n];
    memset(vis,false,sizeof vis);
    queue<int> q;
    q.push(0); vis[0] = true;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(int v: adj[cur]) {
        if(!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    cout << (vis[n-1]?"yes":"no") << endl;
    return 0;
}
