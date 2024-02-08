#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;

void solve() {
    int n;
    cin >> n;

    int freq[26] = {0};
    int v;
    for(int i=0;i<n;++i) {
        cin >> v;
        for(int j=0;j<26;++j) {
            if(freq[j] == v) {
                cout << (char)('a' + j);
                freq[j]++;
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}