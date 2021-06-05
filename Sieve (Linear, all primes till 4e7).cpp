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
const ll mod=998244353;
 
const int NAX_PRIME = sqrt(1e15) + 5;
bool comp[NAX_PRIME];
vector<int> primes;

void sieve(int n = NAX_PRIME){
    fill(comp, comp + n, false);
    for (ll i = 2; i < n; i++){
        if (!comp[i])
            primes.push_back(i);
        for (ll j = 0; j < primes.size() && (i * primes[j] < n); j++){
            comp[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
 
    sieve();
    
    return 0;
}
