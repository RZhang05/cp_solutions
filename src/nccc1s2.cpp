#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

const int MAXN=500005;
int cnt[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    set<int> s;
    for(int i=0;i<MAXN;i++) cnt[i] = 1000000;

    int N, D; cin >> N >> D;
    for(int i=0;i<N;i++) {
      int A; cin >> A;
      if(cnt[A]==1000000) cnt[A] = 0;
      cnt[A]++;
      s.insert(A);
    }
    if(s.size() <= D) cout << (D-(int)s.size()) << '\n';
    else {
      sort(cnt,cnt+MAXN);
      int v = s.size() - D;
      int ans = 0;

      for(int i=0;i<v;i++) ans += cnt[i];
      cout << ans << '\n';
    }
    return 0;
}
