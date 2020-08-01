//https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/sadness/problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const int mod=1e9+7;
 
struct Union{
    vector<int> par,sz;

    Union(int n){
        par.assign(n,-1);
        sz.assign(n,1);
    }
    int find(int a){
        if(par[a]<0)
            return a;
        return par[a]=find(par[a]);
    }
    void unite(int a,int b){
        int x=find(a), y=find(b);
        if(x==y) return;
        if(sz[x]>=sz[y])
            par[y]=x, sz[x]+=sz[y];
        else
            par[x]=y, sz[y]+=sz[x];
    }
};   

 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n,m;
    cin>>n>>m;
    ll ans=n*(n-1)/2;
    vector<pair<ll,ll>> a(m);
    for(ll i=0;i<m;i++){
        cin>>a[i].first>>a[i].second;
        --a[i].first, --a[i].second;
    }
    reverse(a.begin(),a.end());
    vector<ll> fin;
    Union un(n);
    for(ll i=0;i<m;i++){
        ll u=a[i].first, v=a[i].second;
        ll x=un.find(u), y=un.find(v);
        fin.pb(ans);
        if(x!=y){
            ans-=un.sz[x]*un.sz[y];
            un.unite(x,y);
        }
    }
    reverse(fin.begin(),fin.end());
    for(ll i=0;i<m;i++)
        cout<<fin[i]<<"\n";
    
    return 0;
}
