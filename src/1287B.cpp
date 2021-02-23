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
map<string,int> ss;
int ans[1501];

void calc() {
  for(int i=2;i<=1500;i++) ans[i]=ans[i-1]*i;
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  ans[0]=1;
  ans[1]=1;
  calc();
  int n,k; cin >> n >> k;
  for(int i=0;i<n;i++) {
    string s; cin >> s;
    sort(s.begin(),s.end());
    auto t = ss.find(s);
    if(t!=ss.end()) {
        int temp = ss[s]+1;
        ss.erase(t);
        ss.insert({s,temp});
    } else ss.insert({s,1});
  }
  //   n!
  //-------
  //r!(n-r)!
  int cnt = 0;
  cout << "CHECK: " << ss.size() << endl;
  for(pair<string, int> x : ss) {
     if(x.second>=3) cnt += (int)(ans[x.second]/(ans[3]*ans[x.second-3]));
  }
  if(ss.size()>=3) cnt += (int)(ans[ss.size()]/(ans[3]*ans[ss.size()-3]));
  cout << cnt << endl;
  return 0;
}
