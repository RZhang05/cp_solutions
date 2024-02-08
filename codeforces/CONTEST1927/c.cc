#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    bool kA[k+1] = {false};
    bool kB[k+1] = {false};
    int v;
    for(int i=0;i<n;++i) {
        cin >> v;
        if(v <= k) {
            kA[v] = true;
        }
    }
    for(int i=0;i<m;++i) {
        cin >> v;
        if(v <= k) {
            kB[v] = true;
        }
    }
    int cntAonly = 0;
    int cntBonly = 0;
    int cntBoth = 0;
    for(int i=1;i<=k;++i) {
        if(kA[i] && kB[i]) {
            cntBoth++;
        } else if(kA[i]) {
            cntAonly++;
        } else if(kB[i]) {
            cntBonly++;
        }
    }
    if(cntAonly > k/2 || cntBonly > k/2) {
        cout << "NO" << endl;
    } else if(cntAonly + cntBonly + cntBoth != k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}