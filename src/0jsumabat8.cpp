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

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int R, C; cin >> R >> C;
    char grid[R][C];
    int ans = 0;
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
        cin >> grid[i][j];
        if(grid[i][j]=='*') ans++;
      }
    }
    queue<pii> q;
    int cnt = 0;
    if(grid[0][0]=='*') {
      q.push(mp(0,0));
      int direc = 0;
      while(!q.empty()) {
        pii cur = q.front(); q.pop();
        int i=cur.first; int j= cur.second;
        cnt++;
        if(direc==0) {
            if(i<R-1&&grid[i+1][j]=='*') {
              q.push(mp(i+1,j));
              direc = 1;
            } else if(j<C-1&&grid[i][j+1]=='*') q.push(mp(i,j+1));
        } else if(direc==1) {
          if(j>0&&grid[i][j-1]=='*') {
            q.push(mp(i,j-1));
            direc=2;
          } else if(i<R-1&&grid[i+1][j]=='*') q.push(mp(i+1,j));
        } else if(direc==2) {
          if(i>0&&grid[i-1][j]=='*') {
            q.push(mp(i-1,j));
            direc = 3;
          } else if(j>0&&grid[i][j-1]=='*') q.push(mp(i,j-1));
        } else {
          if(j<C-1&&grid[i][j+1]=='*') {
            q.push(mp(i,j+1));
            direc = 0;
          } else if(i>0&&grid[i-1][j]=='*') q.push(mp(i-1,j));
        }
      }
    }
    if(cnt == ans) cout << "anime!" << endl;
    else cout << "lost!" << endl;
    return 0;
}
