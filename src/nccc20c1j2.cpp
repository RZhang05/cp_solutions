#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

const int MAXN=0;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M; cin >> N >> M;
    pii s, e;
    char map[N][M];
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) {
        cin >> map[i][j];
        if(map[i][j]=='J') s = MP(j,i);
      }
    }

    for(int i=0;i<max(N,M);i++) {
      s.second--;
      if(s.second<0) break;
      if(map[s.second][s.first]=='C') {
        cout << "YES" << endl;
        return 0;
      }
      s.first++;
      if(s.first==M) break;
      if(map[s.second][s.first]=='C') {
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
    return 0;
}

