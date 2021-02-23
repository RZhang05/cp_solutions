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
ll dp[MAXN];

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int N; cin >> N;
  for(int i=2;i<N+2;i++) cin >> dp[i];
  for(int i=2;i<N+2;i++) {
    dp[i]=max(dp[i],max(dp[i-1],dp[i-2]+dp[i]));
  }
  /*for(int i=2;i<N+2;i++) {
    int cur = dp[i-2]+v[i];
    if(v[i]<0) dp[i]=max(dp[i],dp[i-1]);
    else dp[i]=max(dp[i],cur);
  }*/
  dp[N+2] = max(dp[N+1],dp[N]);
  cout << dp[N+2] << endl;
  return 0;
}
