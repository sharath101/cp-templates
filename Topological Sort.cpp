#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define INF 9223372036854775807
#define PI 3.141592653589
const int mod=998244353;

const int N=2e5+1;
vector<ll> a[N];
vector<ll> order, pos(N); //Stores the Topological Order
 
bool topsort(ll n){ //Returns 1 if there exists a toposort, 0 if there is a cycle   
    order.clear();
    queue<ll> q;
    vector<ll> indeg(n, 0);
    for(ll i = 0; i < n; i++)
        for(auto &it:a[i])
            indeg[it]++;
    for(ll i = 0; i < n; i++)
        if(!indeg[i])
            q.push(i);
    ll idx = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        order.push_back(v);
        idx++;
        pos[v] = idx;
        for(auto &u:a[v]){
            indeg[u]--;
            if(!indeg[u])
                q.push(u);
        }
    }
    return (order.size() == n);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        a[u].pb(v);
    }
    if(!topsort(n))
        cout<<"Cycle Found";
    else{
        cout<<"Topological Sort\n";
        for(ll i=0;i<order.size();i++)
            cout<<order[i]<<" ";
    }
    


    return 0;
}
