#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

const int MAXN=1e9;
bool notPrime[(int)sqrt(MAXN)+2];

void sieve() {
  for(int i=4;i<=sqrt(MAXN);i++) {
    notPrime[i] = true;
  }
  for(int i=3;i<=sqrt(MAXN);i+=2) {
    if(!notPrime[i]) {
      for(int j=i*2;j<=sqrt(MAXN);j+=i) {
        notPrime[j] = true;
      }
    }
  }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N; cin >> N;
    int p = 1;
    for(int i=2;i<=sqrt(N);i++) {
      if(!notPrime[i] && N%i==0) {
          p*= i;
          while(N%i==0) {
              N/=i;
          }
      }
    }
    p*=N;
    cout << p << endl;
    return 0;
}
