#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

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
const int MAXN = 10000005;

unordered_map<ll,ll> dp;

ll recur(int N) {
  ll ans = 0;
  int i=N;
  while(i>=2) {
    int v = N/i;
    //cout << "CHECK: " << i << endl;
    ll next = N/v-N/(v+1);
    if(dp.count(v)) {
      ans += next*dp[v];
      i=N/(v+1);
      continue;
    }
    ll up = recur(v);
    dp[v] = up;
    ans += next*up;
    i = N/(v+1);
  }
  return ans;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    dp[1] = 1;
    int N; cin >> N;
    if(N==1) {
      cout << 1 << endl;
      return 0;
    }
    cout << recur(N) << endl;
    return 0;
}

