#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
const ll mod=1e9+7;

vector<ll> a[100000];
bool vis[100000];
ll in[100000],low[100000];
ll cnt,tmr;
set<ll> st;
 
void dfs(ll v,ll par){
    vis[v]=true;
    low[v]=in[v]=tmr++;
    ll c=0;
    for(ll u:a[v]){
        if(u==par) continue;
        if(vis[u])
            low[v]=min(low[v],in[u]);
        else{
            c++;
            dfs(u,v);
            low[v]=min(low[u],low[v]);
            if(low[u]>=in[v] && par!=-1){
                st.insert(v);
            }
        }
    }
    if(par==-1 && c>1)
        st.insert(v);
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n,m;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0) break;
        for(ll i=0;i<n;i++) a[i].clear(),vis[i]=false;
        ll u,v;
        for(ll i=0;i<m;i++){
            cin>>u>>v;u--,v--;
            a[u].pb(v);
            a[v].pb(u);
        }
        st.clear();
        tmr=0;
        dfs(0,-1);
        cout<<st.size()<<"\n";
    }

    return 0;
}
