#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;

void solve() {
    int n;
    cin >> n;
    int elems[n];
    for(int i=0;i<n;++i) {
        cin >> elems[i];
    }
    int diff[n];
    diff[n-1] = -1;
    for(int i=n-2;i>=0;--i) {
        if(elems[i] != elems[i+1]) {
            diff[i] = i+1;
        } else {
            diff[i] = diff[i+1];
        }
        // cout << "diff at " << i << ": " << diff[i] << endl;
    }
    int q;
    cin >> q;
    for(int i=0;i<q;++i) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(diff[l] == diff[r]) {
            cout << -1 << " " << -1 << endl;
        } else {
            cout << l+1 << " " << diff[l]+1 << endl;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}