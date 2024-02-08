#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;

void solve() {
    int n;
    cin >> n;
    char c;
    int l= -1;
    int r= 0;
    for(int i=0;i<n;++i) {
        cin >> c;
        if(l == -1 && c == 'B') {
            l = i;
        }
        if(c == 'B') {
            r = i;
        }
    }
    cout << (r-l+1) << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}