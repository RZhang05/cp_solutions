#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> trip;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define MOD 1000000007
#define mp make_pair
#define endl '\n'

const int MAXN = 2e5+5;
set<int> seg[4*MAXN];

void build(int v[], int cur, int l, int r) {
    if(l==r) {
        seg[cur].insert(v[l]);
    } else {
        int m = (l+r)/2;
        build(v,cur*2,l,m);
        build(v,cur*2+1,m+1,r);
        set_union(begin(seg[cur*2]),end(seg[cur*2]),begin(seg[cur*2+1]),end(seg[cur*2+1]),inserter(seg[cur],begin(seg[cur])));
    }
    //cout << "CHECK: " << seg[cur] << " " << l << " " << r << endl;
}

set<int> query(int v, int l, int r, int ql, int qr) {
    set<int> temp;
    //cout << "QUERY: " << v << " " << l << " " << r << " " << ql << " " << qr << endl;
    if(qr<l||r<ql) return temp;
    if(ql==l&&qr==r) return seg[v];
    int m = (l+r)/2;
    //if(ql == 8 && qr == 9) return 0;
    set<int> l1 = query(v*2,l,m,ql,min(qr,m));
    set<int> r1 = query(v*2+1,m+1,r,max(ql,m+1),qr);
    //cout << "QUERY L: " << ql << " " << min(qr,m) << " " << l1 << endl;
    //cout << "QUERY R: " << max(ql,m+1) << " " << qr << " " << r1 << endl;
    bool le = l1.empty(); bool re = r1.empty();
    //cout << "CHECK: " << le << " " << re << endl;
    if(le&&!re) return r1;
    else if(!le&&re) return l1;
    set_union(begin(l1),end(l1),begin(r1),end(r1),inserter(temp,begin(temp)));
    return temp;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    int v[N];
    for(int i=0;i<N;i++) {
        int a; cin >> a;
        v[i] = a;
    }
    build(v,1,0,N-1);
    int mid = N/2;
    for(int i=0;i<Q;i++) {
        int l, r; cin >> l >> r;
        if((l>mid&&r>mid))
        cout << query(1,0,N-1,l-1,r-1).size() << endl;
    }
    return 0;
}
