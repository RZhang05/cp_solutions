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
const int MAXN = 2e5+5;
int par[MAXN];

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  //if next number is not yet placed, place that otherwise place biggest not placed
  int N; cin >> N;
  int f; cin >> f;
  cout << f << endl;
  par[f] = 100;
  int prev=f;
  int big = -1;
  for(int i=0;i<N-1;i++) {
    int res = 0;
    int v;
    if(i<N-2) cin >> v;
    else v = f;
    if(par[v]==0) {
        par[v]=prev;
        res = v;
        for(;big>=1;big--) {
          if(!par[big]) break;
        }
    } else {
      if(big==-1) {
        big=N;
        for(;big>=1;big--) {
          if(!par[big]) break;
        }
      }
      par[big]=prev;
      res = big;
      for(;big>=1;big--) {
        if(!par[big]) break;
      }
    }
    cout << res << " "<< prev << endl;
    prev = v;
  }
  return 0;
}
