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
 
ll ncr(int n, int r){
    if (r > n || n < 0 || r < 0)
        return 0;
    __int128 num = 1, den = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++){
        num *= n - r + i;
        num /= i;
    }
    assert(num <= MAX);
    return num;
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n,k;
    cin>>n>>k;
    vector<ll> derr(5);
    derr[0]=1; derr[1]=0; derr[2]=1;
    for(ll i=3;i<=4;i++)
        derr[i]=(i-1)*(derr[i-1]+derr[i-2]);
    ll ans=0;
    for(ll i=n-k,j=k;i<=n;i++,j--)
        ans+=ncr(n,i)*derr[j];
    cout<<ans;


 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
