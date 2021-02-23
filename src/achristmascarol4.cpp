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
const int MAXN = 1e3+5;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cnt = 1;
int maxx = 0;
int minx = 10000;
int maxy = 0;
int miny = 10000;
int ans = 0;

void dfs(int curr, int curc,int r, int c) {
  maxx=max(maxx,curc);
  minx=min(minx,curc);
  maxy=max(maxy,curr);
  miny=min(miny,curr);

  if(curr<r-1&&!vis[curr+1][curc]&&grid[curr+1][curc]=='#') {
    vis[curr+1][curc]=true;
    dfs(curr+1,curc,r,c);
    cnt++;
  }
  if(curc<c-1&&!vis[curr][curc+1]&&grid[curr][curc+1]=='#') {
    vis[curr][curc+1]=true;
    dfs(curr,curc+1,r,c);
    cnt++;
  }
  if(curc>0&&!vis[curr][curc-1]&&grid[curr][curc-1]=='#') {
    vis[curr][curc-1]=true;
    dfs(curr,curc-1,r,c);
    cnt++;
  }
  if(curr>0&&!vis[curr-1][curc]&&grid[curr-1][curc]=='#') {
    vis[curr-1][curc]=true;
    dfs(curr-1,curc,r,c);
    cnt++;
  }
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int r, c; cin >> r >> c;
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      cin >> grid[i][j];
      if(grid[i][j]=='.') vis[i][j]=true;
    }
  }
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(!vis[i][j] && grid[i][j]=='#') {
        //cout << "POINT: " << i << ", " << j << endl;
        vis[i][j]=true;
        dfs(i,j,r,c);
        //cout << "CHECK MIN: " << miny << " " << minx << endl;
        if(grid[miny][minx]!='#'||grid[miny][maxx]!='#'||grid[maxy][maxx]!='#'||grid[maxy][minx]!='#') {
            cnt = 1; maxx=0;maxy=0;minx=10000;miny=10000;
            continue;
        }
        int area = (maxx-minx+1)*(maxy-miny+1);
        int rect = cnt;
        //cout << "CHECK: " << area << ", " << rect << endl;
        cnt=1;maxx=0;maxy=0;minx=10000;miny=10000;
        if(rect==area) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
