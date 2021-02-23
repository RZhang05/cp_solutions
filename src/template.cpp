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
int l, up = numeric_limits<int>::max();
int r, down = 0;

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int T; cin >> T;
  for(int k=0;k<T;k++) {
    int N; cin >> N;
    for(int i=0;i<N;i++) {
      l=numeric_limits<int>::max(); up = numeric_limits<int>::max();
      r=0; down = 0;
      int H, W; cin >> H >> W;
      char grid[H][W];
      for(int j=0;j<H;j++) {
        string s; cin >> s;
        for(int p=0;p<W;p++) {
          grid[j][p] = s.at(p);
          if(s.at(p)=='*') {
            l = min(l,p);
            r = max(r,p);
            up = min(up,j);
            down = max(down,j);
          }
        }
      }
      cout << "DIMENSIONS: " << up << " " << down << " " << l << " " << r << endl;
      if(l==r) cout << 1;
      else {
        bool u = false; bool ur = false; bool ul = false; bool dl = false; bool dr = false; bool d = false; bool m = false;
        if(grid[up][l+1]=='*') u = true;
        if(grid[up+1][l]=='*') ul = true;
        if(grid[up+1][r]=='*') ur = true;
        if(grid[down][l+1]=='*') d = true;
        if(grid[down-1][l]=='*') dl = true;
        if(grid[down-1][r]=='*') dr = true;
        if(grid[(up+down)/2][l+1]=='*') m = true;

        cout << "CHECK: " << u << " " << ur << " " << ul << " " << dl << " " << dr << " " << d << " " << m << endl;

        //numbers
             if(u&&ul&&ur&&!m&&dl&&dr&&d) cout << 0;
        else if(u&&!ul&&ur&&m&&dl&&!dr&&d) cout << 2;
        else if(u&&!ul&&ur&&m&&!dl&&dr&&d) cout << 3;
        else if(!u&&ul&&ur&&m&&!dl&&dr&&!d) cout << 4;
        else if(u&&ul&&!ur&&m&&!dl&&dr&&d) cout << 5;
        else if(u&&ul&&!ur&&m&&dl&&dr&&d) cout << 6;
        else if(u&&!ul&&ur&&!m&&!dl&&dr&&!d) cout << 7;
        else if(u&&ul&&ur&&m&&dl&&dr&&d) cout << 8;
        else if(u&&ul&&ur&&m&&!dl&&dr&&d) cout << 9;
      }
    }
    cout << endl;
  }
  return 0;
}
