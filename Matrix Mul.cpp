//https://atcoder.jp/contests/abc199/tasks/abc199_f
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
void prints(set<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
void printms(multiset<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
void printv(vector<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
const ll mod=1e9+7;

struct Matrix
{
    vector< vector<ll> > mat;
    ll n_rows, n_cols;
 
    Matrix() {}
 
    Matrix(vector< vector<ll> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}
 
    static Matrix identity_matrix(ll n)
    {
        vector< vector<ll> > values(n, vector<ll>(n, 0));
        for(ll i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }
 
    Matrix operator*(const Matrix &other) const 
    {
        ll n = n_rows, m = other.n_cols;
        vector< vector<ll> > result(n_rows, vector<ll>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {
                    tmp += (mat[i][k] * other.mat[k][j])%mod;
                    while(tmp >= mod)
                        tmp -= mod;
                }
                result[i][j] = tmp % mod;
            }
 
        return move(Matrix(move(result)));
    }
 
    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix pw(Matrix a,int p){
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}

//end

ll mpow(ll x, ll y){ 
    ll res = 1;
    x = x % mod;
    while (y > 0) { 
        if (y & 1) res = (res * x) % mod; 
        y = y >> 1;
        x = (x * x) % mod; 
    } 
    return res; 
} 
  
ll modInv(ll n){ 
    return mpow(n,mod-2); 
} 

const int N=101;
vector<ll> a[N];

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();

    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> b(n);
    for(ll i=0;i<n;i++)
        cin>>b[i];
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v; u--,v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    vector<vector<ll>> mat(n,vector<ll>(n));
    for(ll i=0;i<n;i++){
        if(a[i].size()==0){
            mat[i][i]=1;
            continue;
        }
        ll deg = a[i].size(), other = m-deg;
        mat[i][i] = (deg*modInv(2)+other)%mod*modInv(m)%mod;
        for(ll u: a[i])
            mat[u][i]=modInv(2*m);
    }
    Matrix mt(mat); //create matrix from 2d vector
    Matrix fin = pw(mt,k); //fast expo
    for(ll i=0;i<n;i++){
        ll ans=0;
        for(ll j=0;j<n;j++)
            ans=(ans+fin.mat[j][i]*b[j]%mod)%mod;
        cout<<ans<<"\n";
    }
    


 
    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}
