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
#define mkunique(a) sort(a.begin(),a.end()); a.resize(unique(a.begin(),a.end())-a.begin());
#define print(s) for(ll u: s) cout<<u<<" "; cout<<"\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;

template<typename T>
struct rmq {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<int>> range_high;
 
    rmq(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
 
    int compare(int a, int b) const {
        return values[a] < values[b] ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
        range_high.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_high[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_high[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_high[k][i] = compare(range_high[k-1][i], range_high[k-1][i + (1<<(k-1))]);
    }
 
    int rmq_index(int a, int b) const {
        assert(a <= b);
        if(a==b) return a;
        int level = largest_bit(b - a);
        return compare(range_high[level][a], range_high[level][b - (1 << level) + 1]);
    }
 
    T rmq_value(int a, int b) const {
        return values[rmq_index(a, b)];
    }
};

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();
    
    vector<ll> a = {3,3,3,3,-3};
    rmq<ll> rm;
    rm.build(a);
    cout<<rm.rmq_index(0,4)<<" "<<rm.rmq_value(0,4);

    


    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}