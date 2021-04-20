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
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin());
void prints(set<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
void printms(multiset<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
void printv(vector<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
const ll mod=1e9+7;

const int MAXPR = (int)1e9+10000;
vector<ll> pr;

void calc() {
    pr.pb(2);
    const int S = round(sqrt(MAXPR));
    vector<char> sieve(S + 1, true);
    vector<array<int, 2>> cp;
    for (int i = 3; i < S; i += 2) {
        if (!sieve[i])
            continue;
        cp.push_back({i, (i * i - 1) / 2});
        for (int j = i * i; j <= S; j += 2 * i)
            sieve[j] = false;
    }
    vector<char> block(S);
    int high = (MAXPR - 1) / 2;
    for (int low = 0; low <= high; low += S) {
        fill(block.begin(), block.end(), true);
        for (auto &i : cp) {
            int p = i[0], idx = i[1];
            for (; idx < S; idx += p)
                block[idx] = false;
            i[1] = idx - S;
        }
        if (low == 0)
            block[0] = false;
        for (int i = 0; i < S && low + i <= high; i++)
            if (block[i])
                pr.pb((low + i) * 2 + 1);
    };

}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    calc();
    for(auto primes: pr)
    	cout<<primes<<" ";

 
    cerr<<"\n\nTIME: "<<(long double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
