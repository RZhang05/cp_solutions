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
#define endl "\n"
#define MOD 1000000007
#define mp make_pair
#define endl '\n'
#define MAXN 1000005

pii v[MAXN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;
    for(int i=0;i<N;i++) {
      int P, V; cin >> P >> V;
      v[i]=mp(V,P);
    }
    sort(v, v+N);
    return 0;
}

