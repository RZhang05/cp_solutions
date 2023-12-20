#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;


    for(int i=0;i<n;++i) {
        int cnt[26] = {0};
        cin >> m;
        int ans = 0;
        for(int j=0;j<m;++j) {
            char c;
            cin >> c;
            cnt[c-'A']++;
            if(cnt[c-'A'] == c-'A' + 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}