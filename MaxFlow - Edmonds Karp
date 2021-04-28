//https://cses.fi/problemset/task/1694/
//Time for https://www.spoj.com/problems/FASTFLOW/ : TLE

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

const int N=501;
vector<ll> a[N];
vector<vector<ll>> cap(N,vector<ll>(N));
ll n,m;

ll bfs(ll s, ll t, vector<ll> &p){
    p.assign(n,-1);
    p[s]=-2;
    queue<pair<ll,ll>> q;
    q.push({s,mod*mod});
    while(!q.empty()){
        ll v = q.front().ff;
        ll f = q.front().ss;
        q.pop();
        for(ll u: a[v]){
            if(p[u]==-1 && cap[v][u]){
                p[u]=v;
                ll nf=min(f,cap[v][u]);
                if(u==t)
                    return nf;
                q.push({u,nf});
            }
        }
    }
    return 0;
}

ll maxflow(ll s, ll t){
    ll flow=0;
    ll nflow;
    vector<ll> p(n);
    while(nflow = bfs(s,t,p)){
        flow+=nflow;
        ll cur=t;
        while(cur!=s){
            ll prv = p[cur];
            cap[prv][cur]-=nflow;
            cap[cur][prv]+=nflow;
            cur=prv;
        }
    }
    return flow;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
	
	//declare n if not in input
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c; u--,v--;
        if(cap[u][v]!=0){
            cap[u][v]+=c;
            continue;
        }
        a[u].pb(v);
        a[v].pb(u);
        cap[u][v]=c;
    }
    cout<<maxflow(0,n-1);
 
    cerr<<"\n\nTIME: "<<(long double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
