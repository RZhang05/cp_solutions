#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

const int MAXN=1e9;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n; cin >> n;
    for(int i=0;i<n;i++) {
      int f, s; cin >> f >> s;
      cout << f << " " << s << " ";
      int n=f,e=s;
      do{
        int v = n; n = e;
        e=(v+e)%10;
        cout << e << " ";
      } while(n!=f ||e!=s);
      cout << endl;
    }

    return 0;
}
