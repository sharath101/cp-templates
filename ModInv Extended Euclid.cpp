//https://atcoder.jp/contests/abc186/tasks/abc186_e

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

int modInv(int a, int m){ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
        return 0; 
  
    while (a > 1) { 
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
        x += m0; 
  
    return x; 
} 
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
 
    ll t;
    cin>>t;
    while(t--){
        ll n,s,k;
        cin>>n>>s>>k;
        ll gc=__gcd(__gcd(n-s,k),n);
        ll m=(n-s)/gc;
        k/=gc; n/=gc;
        if(__gcd(k,n)!=1)
            cout<<-1<<"\n";
        else
            cout<<m*modInv(k,n)%n<<"\n";
    }
    

 
 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}

