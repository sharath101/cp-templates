//https://www.spoj.com/problems/PON/

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
const ll mod=1e9+7;

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;
    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0){
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();

    ll t;
    cin>>t;
    while(t--){
        ll p;
        cin>>p;
        if(MillerRabin(p))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

 
    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}
