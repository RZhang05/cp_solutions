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

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    string S; readln(S);
    S+=".";
    S="."+S;
    if(S.at(1)=='<'&&S.at(S.length()-2)=='>') {
      int endp = -1;
      for(int i=2;i<S.length()-1;i++) {
        if(S.at(i)=='>'&&S.at(i+1)!='>') {
          endp = i; break;
        }
      }
      if(endp==S.length()-2||endp==-1) cout << S.substr(1,S.length()-2) << endl;
      else {
        string a = S.substr(2,endp-1);
        int start = -1;
        for(int i=S.length()-3;i>0;i--) {
          if(S.at(i)=='<'&&S.at(i-2)!='<') {
            start = i; break;
          }
        }

        if(start==1 || start == -1 || a.length()==0) cout << S.substr(1,S.length()-2) << endl;
        else {
          string b = S.substr(start+1,S.length()-start-2);
          //cout << "CHECK: " << a << ", " << b << endl;
          if(b.at(0)=='/') {
            cout << (a==b.substr(1,b.length()-1)?S.substr(endp+1,start-endp-1):S.substr(1,S.length()-2)) << endl;
          } else cout << S.substr(1,S.length()-2) << endl;
        }
      }
    } else cout << S.substr(1,S.length()-2);
    return 0;
}
