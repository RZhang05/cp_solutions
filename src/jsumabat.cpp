#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long,int> pli;
typedef pair<int,int>pii;

#define PB push_back
#define MP make_pair

const int MAXN=1e6+5;
long tim[MAXN];
long dis[MAXN];

int bsearch(long v, int N) {
  int l = 0, r = N;
  while(l<=r) {
    int m = (l+r)/2;
    if(tim[m]==v) return m;
    if(tim[m]<v)l=m+1;
    else r=m-1;
  }
  return l;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n; cin >> n;
    for(int i=1;i<=n;i++) {
      long t, d; cin >> t >> d;
      tim[i]=t*d+tim[i-1];
      dis[i]=d+dis[i-1];
    }
    int Q; cin >> Q;
    for(int i=0;i<Q;i++) {
      long d; cin >> d;
      int j = bsearch(d,n);
      //cout << "CHECK: " << j << '\n';
      cout << (dis[j-1]+(d-tim[j-1])/((tim[j]-tim[j-1])/(dis[j]-dis[j-1]))) << '\n';
    }
    return 0;
}
