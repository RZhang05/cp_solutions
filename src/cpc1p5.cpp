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

ll sum[MAXN];
ll freq[MAXN];

void update(int i, int v, ll BIT[]) {
  for(;i<MAXN;i+=(i&-i)) {
    BIT[i]+=v;
  }
}

ll query(int v, ll BIT[]) {
  ll ans = 0;
  for(;v>0;v-=(v&-v)) {
    ans += BIT[v];
  }
  return ans;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int Q; cin >> Q;
    for(int i=0;i<Q;i++) {
      int op, t; cin >> op >> t;
      if(op==1) {
        update(t,1,freq);
        update(t,t,sum);
      } else if(op==2) cout << query(t,freq) << endl;
      else cout << query(t,sum) << endl;
    }
    return 0;
}
