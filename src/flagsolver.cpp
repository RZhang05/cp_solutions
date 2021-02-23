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
const int MAXN = 20;
vector<int> adj[MAXN];
int colour[MAXN];
int N, M;
int cnt = 0;
int check[MAXN];

void rec(int cur) {
  for(int i=1;i<=10;i++) {
    bool valid = true;
    for(int v:adj[cur]) {
      if(colour[v]==i) {
          valid = false;
          break;
      }
    }
    if(!valid) continue;
    colour[cur]=i;
    if(cur<N) rec(cur+1);
    else {
        //cout << "CHECK: " << ans << endl;
        cnt++;
    }
    check[cur]++;
    colour[cur]=0;
    //cout << "CHECK: " << cur << ": " << prev << " -> " << cnt << endl;
  }
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  cin >> N >> M;
  for(int i=0;i<M;i++) {
    int a; int b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  rec(1);
  for(int i=1;i<=N;i++) {
    cout << check[i] << endl;
  }
  cout << cnt << endl;
  return 0;
}
