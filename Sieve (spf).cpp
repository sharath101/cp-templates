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
const ll mod=1e9+7;


const int MAXN=1e6+1; 
ll spf[MAXN]; 
  
void sieve(){ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=2; i*i<MAXN; i++){ 
        if (spf[i] == i){ 
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  

vector<ll> getfact(ll x){ 
    vector<ll> ret; 
    while (x != 1){ 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    sieve();
    vector<ll> a = getfact(15); //3,5


    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
