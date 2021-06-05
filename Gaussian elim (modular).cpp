//https://codeforces.com/contest/1155/problem/E

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
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin()); //need to sort
#define print(s) for(ll u: s) cout<<u<<" "; cout<<"\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e6+3;

ll query(ll x){
    cout<<"? "<<x<<endl;
    ll ans; cin>>ans;
    return ans;
}

const long double EPS = 1e-9;

ll mpow(ll x, ll y){ 
    ll res = 1;
    x = x % mod;
    while (y > 0) { 
        if (y & 1) res = (res * x) % mod; 
        y = y >> 1;
        x = (x * x) % mod; 
    } 
    return res; 
} 
  
ll modInv(ll n){ 
    return mpow(n,mod-2); 
} 

int gauss (vector < vector<ll> > a, vector<ll> & ans) {
    ll n = (ll) a.size();
    ll m = (ll) a[0].size() - 1;

    vector<ll> where (m, -1);
    for (ll col=0, row=0; col<m && row<n; ++col) {
        ll sel = row;
        for (ll i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (ll i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (ll i=0; i<n; ++i)
            if (i != row) {
                ll c = a[i][col] * modInv(a[row][col]) %mod;
                for (ll j=col; j<=m; ++j){
                    a[i][j] -= a[row][j] * c %mod;
                    if(a[i][j]<0) a[i][j] += mod;
                }
            }
        ++row;
    }

    ans.assign (m, 0);
    for (ll i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] * modInv(a[where[i]][i]) %mod;
    for (ll i=0; i<n; ++i) {
        ll sum = 0;
        for (ll j=0; j<m; ++j){
            sum += ans[j] * a[i][j];
            sum %= mod;
        }
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (ll i=0; i<m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();

    vector<vector<ll>> a;
    for(ll i=0;i<11;i++){
        ll fx = query(i);
        vector<ll> v;
        ll r=1;
        for(ll j=0;j<11;j++){
            v.pb(r);
            r=r*i%mod;
        }
        v.pb(fx);
        a.pb(v);
    }
    vector<ll> ans;
    gauss(a,ans);
    

    ll fin=-1;
    for(ll i=0;i<mod;i++){
        ll x=1, sum=0;
        for(ll j=0;j<11;j++){
            sum=(sum+ans[j]*x%mod)%mod;
            x=x*i%mod;
        }
        if(sum==0) fin=i;
    }
    cout<<"! "<<fin<<endl;
    

 
    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}
