#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair

const int MAXN=1000002;
vector<int> primes;
bool notPrime[MAXN];

void sieve(int N) {
  if(N>=2) primes.PB(2);
  for(int i=4;i<=N;i+=2) notPrime[i] = true;
  for(int i=3;i<=N;i+=2) {
    if(!notPrime[i]) {
        primes.PB(i);
      for(int j=i*2;j<=N;j+=i) {
        notPrime[j] = true;
      }
    }
  }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N; cin >> N;
    sieve(N);
    cout << (primes.size()+1) << endl;
    return 0;
}
