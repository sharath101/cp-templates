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

//Importing libraries
//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// pbds A 
// A.insert(number)
// A.remove(number)
// *A.find_by_order(index) --> gives element at given index
// A.order_of_key(number) --> gives count of elements smaller than number
// *A.lower_bound(number) --> gives first element that is >= number
// *A.upper_bound(number) --> gives first element that is > number

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    pbds s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    cout<<s.size()<<" "; //2



    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
