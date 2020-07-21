#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define INF 9223372036854775807
#define PI 3.141592653589
const int mod=1e9+7;

const int N=2e5+1;
vector<ll> a[N];
vector<ll> s,pos(N,-1),cyc;

bool dfs(ll v){
    pos[v]=s.size();   //pos is similar to visited array
    s.pb(v);
    ll ok=-1;
    for(ll u:a[v]){
        if(pos[u]!=-1 && pos[v]-pos[u]>1) //Already visited and dist>1
            ok=max(ok,pos[u]);
    }
    if(ok!=-1){
        for(ll i=ok;i<=pos[v];i++)
            cyc.pb(s[i]);
        return true;
    }
    for(ll u:a[v]){
        if(pos[u]==-1){
            if(dfs(u))
                return true;
        }
    }
    s.pop_back();
    return false;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;u--,v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    if(!dfs(0))
        cout<<"No Cycle";
    else{
        cout<<"Cycle with no cross edges:\n";
        for(ll i=0;i<cyc.size();i++)
            cout<<cyc[i]+1<<" ";
    }
        
    
    return 0;
}
