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

const int N=2e5+100;
vector<ll> a[N];

struct binlift{
    vector<vector<ll>> lca;
    vector<ll> lev;
    ll Log;

    binlift(ll n){
        Log = ceil(log2(n))+1;
        lca.assign(n, vector<ll>(Log,-1));
        lev.assign(n,0);
        dfs(0);
    }

    void dfs(ll v, ll d=0, ll p=-1){
        lca[v][0]=p;
        lev[v]=d;
        for(ll i=1;i<Log;i++)
            if(lca[v][i-1]!=-1)
                lca[v][i]=lca[lca[v][i-1]][i-1];
        for(ll u:a[v]){
            if(u==p) continue;
            dfs(u,d+1,v);
        }
    }

    ll getlca(ll a,ll b){
        if(lev[a]<lev[b]) swap(a,b);
        for(ll i=Log-1;i>=0;i--){
            if(lca[a][i]==-1 || lev[lca[a][i]]<lev[b]) continue;
            a=lca[a][i];
        }
        if(a==b) return a;
        for(ll i=Log-1;i>=0;i--)
            if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
                a=lca[a][i],b=lca[b][i];
        return lca[a][0];
    }

    ll dist(ll a, ll b){
        return lev[a] + lev[b] - 2*lev[getlca(a,b)];
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll m; cin>>m;
        for(ll j=0;j<m;j++){
            ll r; cin>>r;
            a[i].pb(r);
            a[r].pb(i);
        }
    }

    binlift lc(n);
    ll q;
    cin>>q;
    
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<lc.getlca(a,b)<<"\n";
    }
 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
