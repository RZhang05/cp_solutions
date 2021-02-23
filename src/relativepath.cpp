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

map<string, int> m;
string arr[MAXN];
vector<int> adj[MAXN];
stack<int> q;

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int n; cin >> n;
  int prev = -1;
  string dddd; getline(cin, dddd);
  for(int i=0;i<n;i++) {
    //if(q.size()==1) cout << "BORKED: " << i << endl;
    string s; getline(cin,s);
    int ind = 0;
    for(int j=0;j<s.length();j++) {
      if(s.at(j)==' ') ind++;
      else break;
    }
    string v = s.substr(ind);
    arr[i] = v;
    m.insert({v,i});
    if(ind>prev&&i!=0) q.push(i-1);
    else if (ind < prev) {
        for(int j=0;j<(prev-ind)/2;j++) q.pop();
    }
    if(i!=0) {
      //cout << "CHECK: " << v << " ADDED TO " << arr[q.top()] << endl;
      adj[q.top()].pb(i);
    }
    prev = ind;
  }
  int Q; cin >> Q;
  int cur = 0;
  string op, folder; cin >> op >> folder;
  for(int i=0;i<Q-1;i++) {
    cin >> op;
    if(op.compare("ls")==0) {
      for(int v: adj[cur]) cout << arr[v] << endl;
    } else {
      cin >> folder;
      if(folder.compare("..")==0) {
        q.pop();
        cur = q.top();
      } else {
        int temp = m[folder];
        //cout << "CHECK: " << temp << endl;
        cur = temp;
        q.push(temp);
      }
    }
  }
  return 0;
}
