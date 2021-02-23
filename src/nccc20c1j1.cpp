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
    string s; cin >> s;
    int ans=1;
    for(int i=1;i<=s.length();i++) ans *= i;
    cout << ans << endl;
    return 0;
}
