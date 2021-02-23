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
int dp[2][MAXN];

int rev(int v) {
  int fin = 0;
  while(v>0) {
    fin = fin*10+v%10;
    v/=10;
  }
  return fin;
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int n; cin >> n;
  int prev = 0;
  int prev2 = 0;
  for(int i=0;i<n;i++) {
    if(i>0) dp[0][i] = dp[1][i] = 5*MAXN;
    else dp[1][i] = 1;
    int v; cin >> v;
    int v2 = rev(v);
    if(i==0) {
      prev = v;
      prev2 = v2;
      continue;
    }
    //cout << "CHECK1: " << v << ", " << v2 << endl;
    //cout << "CHECK2: " << prev << ", " << prev2 << endl;
    if(v>prev) dp[0][i] = dp[0][i-1];
    if(v>prev2) dp[0][i] = min(dp[0][i],dp[1][i-1]);
    if(v2>prev) dp[1][i] = dp[0][i-1]+1;
    if(v2>prev2) dp[1][i] = min(dp[1][i],dp[1][i-1]+1);
    //cout << "not flip: " << dp[0][i] << endl;
    //cout << "flip: " << dp[1][i] << endl;
    prev = v;
    prev2 = v2;
  }
  cout << min(dp[0][n-1],dp[1][n-1]) << endl;
  return 0;
}
