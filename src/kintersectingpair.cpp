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
const int MAXN = 1e4+5;
int freq[MAXN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for(int i=0;i<n;i++) {
      int v; cin >> v;
      freq[v]++;
    }
    ll ans = 0;
    for(int i=0;i<MAXN;i++) {
      for(int j=0;j<MAXN;j++) {
        if(freq[i]>0&&freq[j]>0&&__builtin_popcount(i^j)==k) ans += freq[i]*(j==i?freq[j]-1:freq[j]);
      }
    }
    ans/=2;
    cout << ans << endl;
    return 0;
}
