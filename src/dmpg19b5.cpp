#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, pair<int,int>> trip;

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

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;
    trip v[N];
    for(int i=0;i<N;i++) {
      int x, y, c; cin >> x >> y >> c;
      v[i] = mp(mp(x,y),mp(c,i+1));
    }
    sort(v, v+N);
    for(int i=0;i<N-2;i++) {
      trip p1 = v[i];
      trip p2 = v[i+1];
      trip p3 = v[i+2];
      //cout << "CHECK: " << p1.first.second << ", " << p1.first.second << " | " << p2.first.first << ", " << p2.first.second << " | " << p3.first.first << ", " << p3.first.second << endl;
      if(p1.second.first!=p2.second.first||p1.second.first!=p3.second.first) {
        cout << p1.second.second << " " << p2.second.second << " " << p3.second.second << endl;
        return 0;
      }
    }
    cout << -1 << endl;
    return 0;
}
