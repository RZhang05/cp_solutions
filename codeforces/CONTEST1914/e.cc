#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    int v;
    for(int i=0;i<n;++i) {
        cin >> v;
        a.push_back(v);
    }
    for(int i=0;i<n;++i) {
        cin >> v;
        b.push_back(v);
    }

    vector<pair<int, int>> value;
    for(int i=0;i<n;++i) {
        value.emplace_back(a[i] + b[i] - 2, i);
    }
    sort(value.begin(), value.end(), greater<pair<int,int>>());

    long long ans = 0;
    for(int i=0;i<n;++i) {
        // cout << "Chose " << i << " with score now " << ans << endl;
        if(i%2==0) {
            ans += a[value[i].second]-1;
        } else {
            ans -= b[value[i].second]-1;
        }
    }
    cout << ans << endl;

}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}