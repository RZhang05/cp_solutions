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
const int MAXN = 1e6+5;
string orig[12] = {"C E G A#",
"C# F G# B",
"D F# A C",
"D# G A# C#",
"E G# B D",
"F A C D#",
"F# A# C# E",
"G B D F",
"G# C D# F#",
"A C# E G",
"A# D F G#",
"B D# F# A"};
string poss[36] = {"E G A# C",
"G A# C E",
"A# C E G",
"F G# B C#",
"G# B C# F",
"B C# F G#",
"F# A C D",
"A C D F#",
"C D F# A",
"G A# C# D#",
"A# C# D# G",
"C# D# G A#",
"G# B D E",
"B D E G#",
"D E G# B",
"A C D# F",
"C D# F A",
"D# F A C",
"A# C# E F#",
"C# E F# A#",
"E F# A# C#",
"B D F G",
"D F G B",
"F G B D",
"C D# F# G#",
"D# F# G# C",
"F# G# C D#",
"C# E G A",
"E G A C#",
"G A C# E",
"D F G# A#",
"F G# A# D",
"G# A# D F",
"D# F# A B",
"F# A B D#",
"A B D# F#"};

int check(string s) {
  for(int j=0;j<12;j++) {
    if(s.compare(orig[j])==0) return 100;
  }
  for(int j=0;j<36;j++) {
    if(s.compare(poss[j])==0) return (j%3);
  }
  return -1;
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  int T; cin >> T;
  string s; getline(cin,s);
  for(int i=0;i<T;i++) {
    getline(cin,s);
    int v = check(s);
    if(v==100) cout << "root" << endl;
    else if(v==-1) cout << "invalid" << endl;
    else {
      if(v==0) cout << "first" << endl;
      else if(v==1) cout << "second" << endl;
      else cout << "third" << endl;
    }
  }
  return 0;
}
