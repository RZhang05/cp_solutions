/*
 * To use, edit settings, input generator, and output generator part
 * Made by your boy Jonathan Sumabat :dab:
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<double,int> pii;
typedef pair<double,pair<int,int>> trip;

#define pb push_back
#define mp make_pair
#define endl '\n'

const int MAXN = 1e3+5;
trip cnt[MAXN];
vector<int> adj[MAXN];
int arr[MAXN];
int par[MAXN];

// DEFINES
#define cin inf[CURRENT_FILE]
#define cout outfstr[CURRENT_FILE]
using ll = long long;

mt19937 g1;
// seeds 1,2, respectively
void seed1() { g1.seed(time_t(0)); }
void seed2() { g1.seed(chrono::steady_clock::now().time_since_epoch().count()); }
// gen num in [a, b]
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}





// SETTINGS -----------------------------------------------------------------------------------------------------------------------
const int file_cnt = 20; // choose how many files you want (too many may be too dangerous, so beware not more than 250)
const int seed = 1; // choose seed [1,2]
const bool gen_init = false; // choose if you want init.yml file made (no batches supported)
//---------------------------------------------------------------------------------------------------------------------------------






// input/output file stream
ifstream inf[file_cnt+1];
ofstream outfstr[file_cnt+1];


void dfs(int s, int prev) {
  cnt[s-1]=mp((long double)(1/pow(2,s)),mp(s,prev));
  for(int v: adj[s]) {
    dfs(v,s);
    cnt[s-1]=mp(cnt[s-1].first+cnt[v-1].first,mp(s,prev));
  }
  //cout << "CHECK: " << s << ", " << cnt[s].first << endl;
}


// INPUT GENERATOR -----------------------------------------------------------------------------------------------------------
/*
 * DO NOT REMOVE 'CURRENT_FILE', that tells the generator which file to output to.
 * To output to the input file, just use 'cout'.
 */

void gen_input(int CURRENT_FILE) {
  for(int i=0;i<MAXN;i++) adj[i].clear();
  int N = 1000;
  cout << N << endl;
  for(int i=0;i<N;i++) arr[i]=i+1;
  for(int i=N-1;i>0;i--) {
    int j = rand()%i;
    swap(arr[i],arr[j]);
  }
  vector<int> cur;
  cur.pb(arr[0]);
  for(int i=1;i<N;i++) {
    int v = rand()%(cur.size());
    //cout << "EDGES: " << cur[v] << ", " << arr[i] << endl;
    adj[cur[v]].pb(arr[i]);
    cur.pb(arr[i]);
  }
  dfs(arr[0],-1);
  sort(cnt,cnt+N);

  //cout.precision(17);
  //for(int i=N-2;i>=0;i--) cout <<"SORTED GRAPH: " << cnt[i].second.first << " " << cnt[i].second.second << endl;
  for(int i=N-2;i>=0;i--) cout << cnt[i].second.second << " ";
  cout << endl;
}
// END OF INPUT GENERATOR ----------------------------------------------------------------------------------------------------

// OUTPUT GENERATOR -----------------------------------------------------------------------------------------------------------
/*
 * DO NOT REMOVE 'CURRENT_FILE', that tells the generator which file to output to.
 * To output to the output file, just use 'cout'. To input from file, use 'cin'.
 */
void gen_output(int CURRENT_FILE) {
  for(int i=0;i<MAXN;i++) par[i]=0;
  int N; cin >> N;
  int f; cin >> f;
  par[f] = 100;
  int prev=f;
  int small = numeric_limits<int>::max();
  for(int i=0;i<N-1;i++) {
    int res = 0;
    int v;
    if(i<N-2) cin >> v;
    else v = f;
    if(par[v]==0) {
        par[v]=prev;
        res = v;
        for(;small<=N;small++) {
          if(!par[small]) break;
        }
    } else {
      if(small==numeric_limits<int>::max()) {
        small=1;
        for(;small<=N;small++) {
          if(!par[small]) break;
        }
      }
      par[small]=prev;
      res = small;
      for(;small<=N;small++) {
          if(!par[small]) break;
      }
    }
    cout << min(res,prev) << " " << max(res,prev) << endl;
    prev = v;
  }
}
// END OF OUTPUT GENERATOR ----------------------------------------------------------------------------------------------------






int main() {
    if(file_cnt<=0) { cerr << "Please choose a sane amount of files\n"; return 0; }

    if(seed==1) seed1();
    else if(seed==2) seed2();
    else { cerr << "Please choose a seed [1, 2].\n"; return 0; }

    // open file_cnt file stream input
    for(int i=1; i<=file_cnt; i++) { outfstr[i].open("input" + to_string(i) + ".txt"); }

    // GENERATE INPUT
    for(int i=1; i<=file_cnt; i++) { gen_input(i); }

    // close the input file stream
    for(int i=1; i<=file_cnt; i++) { outfstr[i].close(); }

    // open file_cnt file stream output
    for(int i=1; i<=file_cnt; i++) {
        inf[i].open("input" + to_string(i) + ".txt");
        outfstr[i].open("output" + to_string(i) + ".txt");
    }

    // GENERATE OUTPUT
    for(int i=1; i<=file_cnt; i++) { gen_output(i); }

    // close output files
    for(int i=1; i<=file_cnt; i++) { outfstr[i].close(); inf[i].close(); }

}

