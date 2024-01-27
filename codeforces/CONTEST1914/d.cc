#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

// 5
// 15 1   1  1 1
// 30 1  15  1 1
//  1 25  1  1 1

struct Val {
    int v;
    int ind;

    Val(int v, int ind) : v{v}, ind{ind} {}
};

bool operator<(const Val &v1, const Val &v2) {
    return v1.v > v2.v;
}


void solve() {
    int n;
    cin >> n;
    vector<Val> acs[3];

    for(int i=0;i<3;++i) {
        for(int j=0;j<n;++j) {
            int v;
            cin >> v;
            acs[i].emplace_back(v, j);
        }
        sort(acs[i].begin(), acs[i].end());
    }

    int perms[] = {0, 1, 2};
    int sz = sizeof(perms) / sizeof(perms[0]);
    int ans = 0;
    do {
        int elems[] = {-1,-1,-1};
        int sum = 0;
        for(int i=0;i<3;++i) {
            int curInd = perms[i];
            for(int j=0;j<n;++j) {
                bool used = false;
                for(int z=0;z<3;++z) {
                    if(acs[curInd][j].ind == elems[z]) used = true;
                }
                if(!used) {
                    elems[i] = acs[curInd][j].ind;
                    sum += acs[curInd][j].v;
                    break;
                }
            }
        }
        ans = max(ans, sum);
    } while(next_permutation(perms, perms+sz));
    cout << ans << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        solve();
    }
}