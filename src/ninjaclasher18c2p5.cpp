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
int dis[MAXN]; int cnt[MAXN];
vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, M, A, B; cin >> N >> M >> A >> B;
    for(int i=0;i<M;i++) {
      int u, v, w; cin >> u >> v >> w;
      adj[u].pb(mp(v,w));
      adj[v].pb(mp(u,w));
    }
    for(int i=1;i<=N;i++) dis[i]=numeric_limits<int>::max();
    dis[A]=0; cnt[A]=1; pq.push(mp(0,A));
    while(!pq.empty()) {
      pii cur = pq.top(); pq.pop();
      //cout <<"CHECK: " << cnt[cur.second] << endl;
      for(pii v: adj[cur.second]) {
        if(cur.first+v.second<dis[v.first]) {
          cnt[v.first]=cnt[cur.second];
          dis[v.first]=cur.first+v.second;
          pq.push(mp(dis[v.first],v.first));
        } else if(cur.first+v.second==dis[v.first]) cnt[v.first]+=cnt[cur.second];
      }
    }
    cout << dis[B] << endl << cnt[B] << endl;
    return 0;
}
