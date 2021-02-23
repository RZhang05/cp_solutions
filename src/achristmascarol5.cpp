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
int cnt[MAXN];

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int N, M; cin >> N >> M;
  map<int,int> m;
  for(int i=0;i<N;i++) {
    int a; cin >> a;
    m.insert({a,0});
    cnt[a]++;
  }
  int prev; cin >> prev;
  int cur = 0;
  for(int i=1;i<M;i++) {
    int b; cin >> b;
    int dis = b-prev;
    if(b<=cur) dis=0;
    auto v = m.lower_bound(dis);
    int t = v->first;
    cnt[t]--;
    if(cnt[t]==0) m.erase(v);
    if(v==m.end()) {
      cout << "no" << endl;
      return 0;
    }
    cur = max(cur,prev+t);
    prev = b;
  }
  cout << "yes" << endl;
  return 0;
}
