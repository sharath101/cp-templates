#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
const ll mod=1e9+7;

struct dat{
    ll minm = 2e18;
    ll maxm = -minm;
    dat(){}//default constructor
    dat(ll val){//declare constructor
        minm = maxm = val;
    }
};

struct SegmentTree{
    vector<ll> arr;
    ll n;
    dat combine (const dat & l, const dat & r){//combine Left and Right child
        dat ret;
        ret.minm = min(l.minm, r.minm);
        ret.maxm = max(l.maxm, r.maxm);
        return ret;
    }
    vector<dat> tree;
    SegmentTree(vector<ll> &a){
        arr = a;
        n = a.size();
        tree.resize(4*n);
        build(1, 0, n-1);
    }
    SegmentTree(ll cap){
        n = cap;
        arr.resize(n, 0);
        tree.resize(4*n);
    }
    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = dat(arr[tl]);//see base conditions
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v] = combine(tree[v*2] , tree[v*2+1]);
        }
    }
    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            arr[pos] = new_val;//See update operations
            tree[v] = dat(arr[pos]);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
        }
    }
    dat query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) 
            return dat();//See what to return
        if (l == tl && r == tr) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm)) ,
            query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    void update(ll pos, ll val){
        update(1, 0, n-1, pos, val);
    }
    dat query(ll l, ll r){
        return query(1, 0, n-1, l, r);
    }
};

int main(){
	vector<ll> a;
	SegmentTree st(a);   //0 Indexed
	dat r=st.query(1,5); //1 and 5 included
	st.update(5,10);
	cout<<r.minm<<" "<<r.maxm<<"\n";
	return 0;
}
