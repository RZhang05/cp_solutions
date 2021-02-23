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
const int MAXN = 1e5+5;
int BIT[MAXN];
unordered_map<int,int> hm;
bool notPrime[MAXN];
bool cancer[MAXN];

void update(int i, int v) {
  for(;i<MAXN;i+=(i&-i)) {
    BIT[i] += v;
  }
}

int query(int i) {
  int sum = 0;
  for(;i>0;i-=(i&-i)) {
    sum += BIT[i];
  }
  return sum;
}

void sieve() {
  int v = 32000;
  hm.insert({4,1});
  for(int i=4;i<v;i+=2) notPrime[i]=true;
  for(int i=3;i<v;i+=2) {
    if(!notPrime[i]) {
      for(int j=i*2;j<v;j+=i) notPrime[j] = true;
      hm.insert({i*i,1});
    }
  }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    sieve();
    for(int i=0;i<N;i++) {
      int a; cin >> a;
      if(hm.count(a)>0) {
          update(i+1,1);
          cancer[i+1] = true;
      }
    }
    for(int i=0;i<Q;i++) {
      int op, l, r; cin >> op >> l >> r;
      if(op==1) cout << (query(r) - query(l-1)) << endl;
      else {
          if(hm.count(r)==0) {
            if(cancer[l]) update(l,-1);
            cancer[l] = false;
          } else {
            if(!cancer[l]) update(l,1);
            cancer[l] = true;
          }
      }
    }
    return 0;
}
