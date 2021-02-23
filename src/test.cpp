#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<string,int> pii;
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
ll X = 0;
map<string,vector<pii>> op;

void ADD(ll Y) {
  X+=Y;
  X%=1000000007;
}

void SUB(ll Y) {
  X-=Y;
  X%=1000000007;
}

void MULT(ll Y) {
  X*=Y;
  X%=1000000007;
}

void FUN(string s) {
  op[s];
}

void OP(string op) {
  if(op.compare("ADD")==0) {
    ll Y; cin >> Y;
    ADD(Y);
  } else if(op.compare("MULT")==0) {
    ll Y; cin >> Y;
    MULT(Y);
  } else if(op.compare("SUB")==0) {
    ll Y; cin >> Y;
    SUB(Y);
  } else if(op.compare("FUN")==0) {

  }
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int T; cin >> T;
  for(int k=0;k<T;k++) {
    int N; cin >> N;
    X=0;
    for(int i=0;i<N;i++) {
      string op; cin >> op;
      if(op.compare("ADD")==0) {
        ll Y; cin >> Y;
        ADD(Y);
      } else if(op.compare("MULT")==0) {
        ll Y; cin >> Y;
        MULT(Y);
      } else if(op.compare("SUB")==0) {
        ll Y; cin >> Y;
        SUB(Y);
      }
      //cout << "CHECK: " << X << endl;
    }
    cout << (X%1000000007) << endl;
  }
  return 0;
}
