//https://codeforces.com/contest/947/problem/C

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
 
template<int MX> struct tri {
    int nex = 0, ans = 0;
    int trie[MX][2], sz[MX]; // easily changed to character
    
    tri() {
        memset(trie,0,sizeof trie);
        memset(sz,0,sizeof sz);
    }
    
    void insert(int x) {
        int cur = 0; sz[cur] ++;
        for(int i=30;i>=0;i--) {
            int t = (x&(1<<i))>>i;
            if (!trie[cur][t]) trie[cur][t] = ++nex;
            cur = trie[cur][t]; sz[cur] ++;
        }
    }
    
    void del(int x) {
        int cur = 0; sz[cur] --;
        for(int i=30;i>=0;i--){
            int t = (x&(1<<i))>>i;
            if (!trie[cur][t]) trie[cur][t] = ++nex;
            cur = trie[cur][t]; sz[cur] --;
        }
    }
    
    int test(int x) {
        int cur = 0, z = 0;
        for(int i=30;i>=0;i--){
            int t = ((x&(1<<i))>>i);
            if(!trie[cur][t] || !sz[trie[cur][t]]) //after inverting make sure trie[cur][t]!=0
            	t^=1;
            cur = trie[cur][t];
            if(t) z^=(1ll<<i);
        }
        del(z);
        return z;
    }
};

tri<10000000> tr;
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        tr.insert(k);
    }
    for(ll i=0;i<n;i++)
        cout<<(a[i]^tr.test(a[i]))<<" ";


 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
