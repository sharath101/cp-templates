#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define INF 9223372036854775807
#define PI 3.141592653589
const ll mod=1e9+7;

const int N=3e5+1;
ll f[N], invf[N];

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
  
ll C(ll n, ll r){
    if (r == 0) return 1; 
    assert(n>=r);
    return (f[n]*invf[r]%mod*invf[n-r]%mod)%mod; 
} 

void fact(){
    f[0]=1;
    invf[0]=1;
    for(int i=1;i<N;i++){
        f[i]=(f[i-1]*i)%mod; 
        invf[i]=modInv(f[i]);
    }
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,r;
    fact();
    cin>>n>>r;
    cout<<C(n,r);

    return 0;
}
