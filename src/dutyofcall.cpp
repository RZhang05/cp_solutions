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
const int MAXN = 5e5+5;
vector<int> adj[MAXN];
bool vis[MAXN];
bool invalid[MAXN];
int team[MAXN];
int ans[2];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, R; cin >> N >> R;
    for(int i=1;i<=N;i++) {
      int M; cin >> M;
      for(int j=0;j<M;j++) {
        int a; cin >> a;
        adj[i].pb(a); adj[a].pb(i);
        invalid[a] = true;
      }
    }
    queue<pii> Q;
    Q.push(mp(R,0));
    vis[R] = true;
    team[R]=1;
    while(!Q.empty()) {
      pii cur = Q.front(); Q.pop();
      for(int v: adj[cur.first]) {
        if(!vis[v]) {
          vis[v] = true;
          Q.push(mp(v,cur.second==0?1:0));
          team[v]=cur.second;
        }
      }
    }
    for(int i=1;i<=N;i++) {
      if(!invalid[i]) {
        ans[team[i]]++;
      }
    }
    cout << ans[1] << " " << ans[0] << endl;
    return 0;
}

