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


ll totient(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result = result / p * (p - 1);
            do {
                n /= p;
            } while (n % p == 0);
        }
 
    if (n > 1)
        result = result / n * (n - 1);
 
    return result;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    ll t;
    cin>>t;
    while(t--){
        ll a,m;
        cin>>a>>m;
        ll r=__gcd(a,m);
        a/=r; m/=r;
        cout<<totient(m)<<"\n";
    }





    
 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
