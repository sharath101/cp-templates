//https://atcoder.jp/contests/abc193/tasks/abc193_e

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

ll euclid(ll a, ll b, ll &x, ll &y){
    if (b){
        ll d = euclid(b, a % b, y, x);
        return y -= a / b * x, d;
    }
    return x = 1, y = 0, a;
}
 
ll crt(ll a, ll m, ll b, ll n){
    if (n > m)
        swap(a, b), swap(m, n);
    if (n == 1)
        return a;
    ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0)
        return LLONG_MAX;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}
 
// returns {rem, m} from x%m=rem where m is the lcm or {-1,-1} if soln doesnt exist
pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m){
    ll r0 = 0, m0 = 1;
    assert(r.size() == m.size());
    for (size_t i = 0; i < r.size(); i++){
        auto rem = crt(r0, m0, r[i], m[i]);
        if (rem == LLONG_MAX)
            return {-1, -1};
        r0 = rem;
        m0 = m0 / __gcd(m0, m[i]) * m[i];
    }
    return {r0, m0};
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    ll t;
    cin>>t;
    while(t--){
        ll x,y,p,q;
        cin>>x>>y>>p>>q;
        ll ans=mod*mod;
        for(ll i=x;i<x+y;i++){
            for(ll j=p;j<p+q;j++){
                auto [r,lcm] = crt({i, j}, {2*x+2*y, p+q});
                if(lcm==-1) continue;
                ans=min(ans, r);
            }
        }
        if(ans==mod*mod)
            cout<<"infinity\n";
        else
            cout<<ans<<"\n";
    }

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
