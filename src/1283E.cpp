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
int dp[MAXN];

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int n; cin >> n;
  for(int i=0;i<n;i++) {
    int v; cin >> v;
    dp[v]++;
  }
  //min case
  int cnt = 0;
  int prev = -1000;
  //check if counting correct
  for(int i=1;i<=n;i++) {
    if(dp[i]==0&&i>prev+1) continue;
    if(i>prev+2) prev=i;
    if(prev==i) cnt++;
    if(prev==i-2 && dp[i+1]>0) prev=i+1;
    //cout << "CHECK: " << prev << endl;
  }

  //max case
  int cnt2 = 0;
  for(int i=1;i<=n+1;i++) {
    if(dp[i]!=0&&dp[i-1]==0) {
      dp[i]--;
      dp[i-1]++;
    }
    if(dp[i]<=1&&dp[i-1]>1) {
      dp[i]++;
      dp[i-1]--;
    }
  }
  for(int i=0;i<=n+1;i++) {
    if(dp[i]>0) cnt2++;
  }
  cout << cnt << " " << cnt2 << endl;
  return 0;
}
