#include <iostream>

using namespace std;

int n;

// 3 3
// 1 1 10000
// 5 1 1

void solve() {

    int n, k;
    cin >> n >> k;
    int first[n];
    int sMax[n];

    for(int i=0;i<n;++i) {
        cin >> first[i];
        if(i > 0) first[i] += first[i-1];
    }
    for(int i=0;i<n;++i) {
        cin >> sMax[i];
        if(i > 0 && sMax[i-1] > sMax[i]) sMax[i] = sMax[i-1];
    }
    int ans = 0;
    for(int i=0;i<min(n,k);++i) {
        int sum = 0;
        sum += first[i];
        sum += sMax[i] * (k-i-1);
        ans = max(sum, ans);
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}