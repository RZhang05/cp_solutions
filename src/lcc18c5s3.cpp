#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAXN = 100005;
int BIT[MAXN];
int BIT2[MAXN];

bool comp(const pair<int,int> &x, const pair<int,int>y) {
    if(x.first==y.first) {
        return (x.second>y.second);
    }
    return (x.first<y.first);
}

void update(int i, int v, int BIT[]) {
    for(;i<=MAXN;i+=(i&-i)) {
        BIT[i] += v;
    }
}

int query(int i, int BIT[]) {
    int sum = 0;
    for(;i>0;i-=(i&-i)) {
        sum += BIT[i];
    }
    return sum;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N, M; cin >> N >> M;
    pii Q[M];
    for(int i=0;i<M;i++) {
        int K; cin >> K;
        Q[i] = make_pair(K,i+1);
    }
    sort(Q,Q+M);
    pii ans[M];
    for(int i=0;i<M;i++) {
        int bef = query(Q[i].second, BIT);
        int v = Q[i].first+bef;
        if(Q[i].first>N-Q[i].second+1) {
            cout << "Out of bounds" << endl;
            return 0;
        }
        update(Q[i].second,1, BIT);
        ans[i]=make_pair(v,i+1);
    }

    sort(ans, ans+M,comp);
    int realAns[M];
    for(int i=0;i<M;i++) realAns[i] = -1;
    for(int i=0;i<M;i++) {
        int bef = query(ans[i].second,BIT2);
        int v = ans[i].first;
        if(i-bef>0) {
            v++;
        }
        update(ans[i].second,1,BIT2);
        realAns[i]=v;
    }
    sort(realAns, realAns+M);
    for(int i=0;i<M;i++) {
        cout << to_string(realAns[i]) + " ";
    }
    cout << endl;
    return 0;
}
