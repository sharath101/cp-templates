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
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin());
const ll mod=1e9+7;
 
const int N=3e5;
vector<pair<ll,ll>> a[N];
vector<ll> b(N);
vector<bool> vis(N, false);
vector<ll> d(N), p(N);
ll n,m,k;
ll ans=0;

void dijkstra(ll s) {
    d.assign(n, mod);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : a[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    //freopen("output.txt","r",stdin);
    //freopen("correct.txt","w",stdout);

    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(ll i=0;i<k;i++){
            cin>>b[i];
            b[i]--;
        }
        for(ll i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w; u--,v--;
            a[u].pb({v,w});
            a[v].pb({u,w});
        }
        ans=0;
        dijkstra(0);
    }



    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
