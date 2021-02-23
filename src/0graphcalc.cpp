#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
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
const int MAXN = 1e3+5;
int L, R, B, T;
double inc;
vector<double> v;
int grid[MAXN][MAXN];

vector<double> op(vector<double> a, vector<double> b, char z) {
  vector<double> c;
  for(int i=0;i<a.size();i++) {
    if(z=='+') {
        double sum = a[i]+b[i];
        if(abs(sum)<=0.000000001) sum = 0;
        c.pb(sum);
    }
    else if(z=='-') c.pb(a[i]-b[i]);
    else if(z=='*') c.pb(a[i]*b[i]);
    else if(z=='/') c.pb(a[i]/b[i]);
    else c.pb(pow(a[i],b[i]));
  }
  return c;
}

char check(string s) {
  int valid = 0;
  for(int i=s.length()-1;i>=0;i--) {
    if(s.at(i)=='(') valid++;
    else if(s.at(i)==')') valid--;
    if(valid==0) {
      if(s.at(i)=='+'||s.at(i)=='-') return s.at(i);
    }
  }
  for(int i=s.length()-1;i>=0;i--) {
    if(s.at(i)=='(') valid++;
    else if(s.at(i)==')') valid--;
    if(valid==0) {
      if(s.at(i)=='/' || s.at(i)=='*') return s.at(i);
    }
  }
  for(int i=s.length()-1;i>=0;i--) {
    if(s.at(i)=='(') valid++;
    else if(s.at(i)==')') valid--;
    if(valid==0) {
      if(s.at(i)=='^') return s.at(i);
    }
  }
  return '!';
}

vector<double> eval(string s) {
  char c = check(s);
  if(c!='!') {
    if(c=='-') {
      int ind = -1;
      int valid2 = 0;
      for(int j=i+1;j<s.length();j++) {
          if(s.at(j)=='(') valid2++;
          else if(s.at(j)==')') valid2--;
          if(valid2==0) {
            if(s.at(j)=='+') ind = j;
          }
      }
      if(ind==-1) {
          vector<double> one = eval(s.substr(0,i)); vector<double> two = eval(s.substr(i+1,s.length()-i));
          return op(one,two,c);
      }
      vector<double> one = eval(s.substr(0,i)); vector<double> two = eval(s.substr(i+1,ind-i-1)); vector<double> three = eval(s.substr(ind+1,s.length()-ind));
      return op(op(one,two,'+'),three,c);
    }
    vector<double> one = eval(s.substr(0,i)); vector<double> two = eval(s.substr(i+1,s.length()-i));
    return op(one,two,c);
  }
  while(s.length()>0 && s.at(0)=='('&&s.at(s.length()-1)==')') {
    s=s.substr(1,s.length()-2);
    if(c!='!') {
      if(c=='-') {
        int ind = -1;
        int valid2 = 0;
        for(int j=i+1;j<s.length();j++) {
            if(s.at(j)=='(') valid2++;
            else if(s.at(j)==')') valid2--;
            if(valid2==0) {
              if(s.at(j)=='+') ind = j;
            }
        }
        if(ind==-1) {
            vector<double> one = eval(s.substr(0,i)); vector<double> two = eval(s.substr(i+1,s.length()-i));
            return op(one,two,c);
        }
        vector<double> one = eval(s.substr(0,i)); vector<double> two = eval(s.substr(i+1,ind-i-1)); vector<double> three = eval(s.substr(ind+1,s.length()-ind));
        return op(op(one,two,'+'),three,c);
      }
      vector<double> one = eval(s.substr(0,i)); vector<double> two = eval(s.substr(i+1,s.length()-i));
      return op(one,two,c);
    }
  }
  if(s.length()==0) {
    vector<double>c;
    for(int i=0;i<(R-L)/inc+1;i++) c.pb(0);
    return c;
  }
  if(s.at(0)!='x') {
    vector<double>c;
    for(int i=0;i<(R-L)/inc+1;i++) c.pb(stod(s));
    return c;
  }
  return v;
}

string edit(string s) {
  s.erase(remove(s.begin(),s.end(),' '),s.end());
  return s;
}

int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  string s; getline(cin,s);
  s = edit(s);
  cin >> L >> R >> B >> T;
  cin >> inc;
  int pos = 0;
  for(double i=L;i<=R;i+=inc) {
    v.pb(i);
    pos++;
  }
  vector<double> res = eval(s);
  for(int i=0;i<res.size();i++) {
    int x = round(v[i]);
    int y = round(res[i]);
    if(y>=B&&y<=T) grid[y-B][x-L]++;
  }
  for(int i=T;i>=B;i--) {
    for(int j=L;j<=R;j++) {
      if(i==0&&j==0&&grid[i-B][j-L]==0) {
          cout << "+";
          continue;
      }
      cout << ((grid[i-B][j-L]>0)?"#":(i==0)?"-":(j==0)?"|":".");
    }
    cout << endl;
  }
  return 0;
}
