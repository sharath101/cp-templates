//https://cses.fi/problemset/task/1694/
//Time for https://www.spoj.com/problems/FASTFLOW/ : TLEs

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin());
const ll mod=1e9+7;

const ll inf = mod*mod;
const ll N = 501;

ll n;
vector<vector<ll>> cap(N, vector<ll>(N)), flow;
vector<ll> height, excess;

void push(ll u, ll v)
{
    ll d = min(excess[u], cap[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
}

void relabel(ll u)
{
    ll d = inf;
    for (ll i = 0; i < n; i++) {
        if (cap[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
    if (d < inf)
        height[u] = d + 1;
}

vector<ll> find_max_height_vertices(ll s, ll t) {
    vector<ll> max_height;
    for (ll i = 0; i < n; i++) {
        if (i != s && i != t && excess[i] > 0) {
            if (!max_height.empty() && height[i] > height[max_height[0]])
                max_height.clear();
            if (max_height.empty() || height[i] == height[max_height[0]])
                max_height.push_back(i);
        }
    }
    return max_height;
}

ll maxflow(ll s, ll t)
{
    height.assign(n, 0);
    height[s] = n;
    flow.assign(n, vector<ll>(n, 0));
    excess.assign(n, 0);
    excess[s] = inf;
    for (ll i = 0; i < n; i++) {
        if (i != s)
            push(s, i);
    }

    vector<ll> current;
    while (!(current = find_max_height_vertices(s, t)).empty()) {
        for (ll i : current) {
            bool pushed = false;
            for (ll j = 0; j < n && excess[i]; j++) {
                if (cap[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1) {
                    push(i, j);
                    pushed = true;
                }
            }
            if (!pushed) {
                relabel(i);
                break;
            }
        }
    }

    ll max_flow = 0;
    for (ll i = 0; i < n; i++)
        max_flow += flow[i][t];
    return max_flow;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    ll m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c; u--,v--;
        if(cap[u][v]!=0){
            cap[u][v]+=c;
            continue;
        }
        //a[u].pb(v);
        //a[v].pb(u);
        cap[u][v]=c;
    }
    cout<<maxflow(0,n-1);

 
    cerr<<"\n\nTIME: "<<(long double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
