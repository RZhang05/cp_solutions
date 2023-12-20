#include <iostream>

using namespace std;

int n;

void solve() {
    int n, k;
    cin >> n >> k;
    int cur = 1;
    for(int i=0;i<k;++i) {
        cout << cur++ << " ";
    }
    for(int i=n;i>=cur;--i) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}