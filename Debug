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

const int N = 100005;
const int MOD = 1e9 + 7;

#define show(arr) { for (auto x: arr) cout << x << " "; cout << '\n'; }

    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randNo(ll lower_limit, ll upper_limit){
    
    return lower_limit + rng()%(upper_limit-lower_limit);
}

ll solve(vector<ll> a, int n) {
    
    //write here your optimed code with low complexity
    
    return ans;
}

ll solve2(vector<ll> a, int n) {
    
    //write here your brute force solution
    
    return ans;
}

int main() {
    
    int testCases = 1000000;
    while(testCases--){
        
        //generating n
        ll n = randNo(1,100);
        
        //To generate a random array
        vector<ll> a(n)
        for(int i=0;i<n;i++) a[i] = randNo(1,N);
        
        ll naive_ans = solve2(a,n);
        ll optimised_ans = solve(a,n);
        
        if(naive_ans == optimised_ans) cout << "YES\n";
        else{
            cout << "NO\n";
            cout << n << '\n';
            show(a);
            cout << naive_ans << '\n';
            cout << optimised_ans << '\n';
            break;      
        }
    }

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
