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

const int MAXN = 1e6;
int seg[4*MAXN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;
    int cur = N;
    for(int i=0;i<N;i++) cin >> seg[N+i];
    int v = seg[N];
    int ans = 1;
    while(cur>1) {
      bool valid = false;
      for(int i=cur;i<cur*2;i+=2) {
        seg[i/2]=max(seg[i],seg[i+1]);
        if(seg[i/2]==v) valid = true;
      }
      if(!valid) break;
      cur/=2;
      ans++;
    }
    cout << ans << endl;
    return 0;
}

