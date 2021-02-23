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
#define MAXN 15

char grid[MAXN][MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<pii> Q;
int direc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int X; cin >> X;
    pii start, finish;
    bool done = false;
    for(int i=0;i<X;i++) {
      for(int j=0;j<X;j++) {
        cin >> grid[i][j];
        if(grid[i][j]=='-' && !done) {
          start = mp(i,j);
          done = true;
        }
      }
    }
    Q.push(start);
    vis[start.first][start.second]=true;
    while(!Q.empty()) {
      pii cur = Q.front(); Q.pop();
      int x = cur.first; int y = cur.second;
      for(int i=0;i<4;i++) {
        int newx = x+direc[i][0]; int newy = y+direc[i][1];
        if((newx>=0 && newx <X && newy>=0 && newy<X) && !vis[newx][newy] && grid[newx][newy]!='x') {
          //cout <<"CHECKING: " << newx << " " << newy << endl;
          dis[newx][newy]=dis[x][y]+1;
          vis[newx][newy]=true;
          Q.push(mp(newx,newy));
        }
      }
    }
    int N; cin >> N;
    for(int k=0;k<N;k++) {
      pii q; pii q2;
      bool done2 = false; bool done3 = false;
      for(int i=0;i<X;i++) {
        string s; cin >> s;
        if(done2 && done3) continue;
        for(int j=0;j<X;j++) {
          if(s.at(j)=='J') {
            q=mp(i,j);
            done2=true;
          } else if(s.at(j)=='R') {
            q2=mp(i,j);
            done3 = true;
          }
        }
      }
      if(dis[q.first][q.second]==0) {
        cout << "Demote Rayzhang!" << endl;
        return 0;
      }
      int v = abs(dis[q2.first][q2.second]-dis[q.first][q.second]);
      cout << v << endl;
    }
    return 0;
}
