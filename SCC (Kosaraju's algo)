//https://codeforces.com/contest/542/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin());
const ll mod=1e9+7;

const int N=2e5+10;
vector<ll> a[N], at[N];
ll n;
vector<ll> order, comp;
vector<bool> vis;

void dfs1(ll v){
    vis[v]=true;
    for(ll u: a[v])
        if(!vis[u])
            dfs1(u);
    order.pb(v);
}

void dfs2(ll v){
    vis[v]=true;
    comp.pb(v);
    for(ll u: at[v])
        if(!vis[u])
            dfs2(u);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    cin>>n;
    vector<bool> self(n);
    for(ll i=0;i<n;i++){
        ll r; cin>>r; r--;
        if(i==r) {self[i]=true; continue;}
        //directed edge from r -> i
        a[r].pb(i);
        at[i].pb(r);
    }
    vis.assign(n,false);
    for(ll i=0;i<n;i++)
        if(!vis[i])
            dfs1(i);
    reverse(order.begin(),order.end());
    vis.assign(n,false);
    vector<vector<ll>> scc;
    for(ll i=0;i<n;i++){
        ll v=order[i];
        if(!vis[v]){
            comp.clear();
            dfs2(v);
            scc.pb(comp);
        }
    }
    //end of kosaraju's algo. scc contains all components.

    queue<ll> q;
    vis.assign(n, false);
    for(ll i=0;i<n;i++)
        if(self[i])
            q.push(i), vis[i]=true;
    ll lcm=1, gc=0;
    for(ll i=0;i<scc.size();i++){
        if(scc[i].size()==1) continue;
        for(ll u: scc[i])
            q.push(u), vis[u]=true;
        ll clen = scc[i].size();
        gc=__gcd(lcm, clen);
        lcm=lcm*clen/gc;
    }
    vector<ll> d(n);
    ll maxlen=1;
    while(!q.empty()){
        ll v=q.front();
        q.pop();
        maxlen=max(maxlen, d[v]);
        for(ll u: a[v]){
            if(!vis[u]){
                q.push(u);
                d[u]=d[v]+1;
                vis[u]=true;
            }
        }
    }
    ll m=(maxlen + lcm - 1)/lcm;
    cout<<lcm*m;



    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
