#include <bits/stdc++.h>
using namespace std;
#define ll long long 
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

struct Node
{
    long long val;
    Node(long long one = 0) : val(one) {}
    void merge(ll &l, ll r){
        l = (l + r); 
    }
    Node lazylazyMerge(const Node &rhs){
        Node a = *this;
        //merge(a.val , rhs.val);
        a.val=rhs.val; //for range assign
        //a.val = a.val + rhs.val; //range add
        return a;
    }
    Node seglazyMerge(const Node &rhs, const int &l, const int &r){
        Node a = *this;
        //merge(a.val , (r - l + 1) * (rhs.val));
        //a.val = a.val + (r - l + 1) * rhs.val; //range add
        a.val = (r - l + 1) * rhs.val; //range assign
        //a.val = a.val + rhs.val; //for max/min. For min change default query return
        return a;
    }
    Node segSegMerge(const Node &rhs){
        Node a = *this;
        merge(a.val , rhs.val);
        return a;
    }
};

template <typename segNode>
struct SegmentTree
{
    vector<segNode> Seg, Lazy;
    vector<segNode> Base;
    vector<bool> isLazy;
    int n;
    SegmentTree(int _n = 2e5){
        this->n = _n;
        Seg.resize(4 * _n + 10);
        Lazy.resize(4 * _n + 10);
        isLazy.resize(4 * _n + 10);
    }
    void merge(segNode &curr, segNode &l, segNode &r){
        curr = (l , r);
    }
    void propagate(int node, int L, int R){
        if (isLazy[node]){
            isLazy[node] = false;
            Seg[node] = Seg[node].seglazyMerge(Lazy[node], L, R);
            if (L != R){
                Lazy[2 * node] = Lazy[2 * node].lazylazyMerge(Lazy[node]);
                Lazy[2 * node + 1] = Lazy[2 * node + 1].lazylazyMerge(Lazy[node]);
                isLazy[2 * node] = true;
                isLazy[2 * node + 1] = true;
            }
            Lazy[node] = segNode();
        }
    }
    void build(int node, int start, int end){
        if (start == end){
            Seg[node] = Base[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    void build(vector<segNode> &Arr){
        Base = Arr;
        n = Arr.size();
        Seg.resize(4 * n + 10);
        Lazy.resize(4 * n + 10);
        isLazy.resize(4 * n + 10);
        build(1, 0, n - 1);
    }
    segNode Query(int node, int start, int end, int qstart, int qend){
        propagate(node, start, end);
        if (qend < start || qstart > end || start > end)
            return segNode();
        if (qstart <= start && end <= qend)
            return Seg[node];
        int mid = (start + end) / 2;
        segNode l = Query(2 * node, start, mid, qstart, qend);
        segNode r = Query(2 * node + 1, mid + 1, end, qstart, qend);
        return l.segSegMerge(r);
    }
    segNode qQuery(int node, int start, int end, int pos){
        propagate(node, start, end);
        if (start == end)
            return Seg[node];
        int mid = (start + end) / 2;
        if (pos <= mid)
            return qQuery(2 * node, start, mid, pos);
        return qQuery(2 * node + 1, mid + 1, end, pos);
    }
    void Update(int node, int start, int end, int qstart, int qend, segNode val){
        propagate(node, start, end);
        if (qend < start || qstart > end || start > end)
            return;
        if (qstart <= start && end <= qend)
        {
            isLazy[node] = true;
            Lazy[node] = val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        Update(2 * node, start, mid, qstart, qend, val);
        Update(2 * node + 1, mid + 1, end, qstart, qend, val);
        Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    void pUpdate(int node, int start, int end, int pos, segNode val){
        propagate(node, start, end);
        if (start == end)
        {
            isLazy[node] = true;
            Lazy[node] = val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid)
            pUpdate(2 * node, start, mid, pos, val);
        else
            pUpdate(2 * node + 1, mid + 1, end, pos, val);
        Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    segNode query(int pos){
        return qQuery(1, 0, n - 1, pos);
    }
    segNode query(int left, int right){
        return Query(1, 0, n - 1, left, right);
    }
    void update(int pos, segNode val){
        pUpdate(1, 0, n - 1, pos, val);
    }
    void update(int start, int end, segNode val){
        Update(1, 0, n - 1, start, end, val);
    }
};

const int N=1e5+10;
vector<vector<ll>> a(N);

struct hld{
    vector<ll> parent, depth, heavy, head, pos, sa, val, lev;
    vector<vector<ll>> lca;
    SegmentTree<Node> st;
    ll Log;
    ll cur_pos;

    hld(vector<vector<ll>> const& adj, vector<ll> v) {
        ll n = adj.size();
        val = v;
        st = SegmentTree<Node>(n);
        parent = vector<ll>(n);
        depth = vector<ll>(n);
        heavy = vector<ll>(n, -1);
        head = vector<ll>(n);
        pos = vector<ll>(n);
        sa = vector<ll>(n);
        cur_pos = 0;
        Log = ceil(log2(n))+1;
        lca.assign(n, vector<ll>(Log,-1));
        lev.assign(n,0);
        dfsblift(0, adj);
        dfs(0, adj);
        decompose(0, 0, adj, sa);
    }

    void dfsblift(ll v, vector<vector<ll>> const& adj, ll d=0, ll p=-1){
        lca[v][0]=p;
        lev[v]=d;
        for(ll i=1;i<Log;i++)
            if(lca[v][i-1]!=-1)
                lca[v][i]=lca[lca[v][i-1]][i-1];
        for(ll u:adj[v]){
            if(u==p) continue;
            dfsblift(u,adj,d+1,v);
        }
    }

    ll getlca(ll a,ll b){
        if(lev[a]<lev[b]) swap(a,b);
        for(ll i=Log-1;i>=0;i--){
            if(lca[a][i]==-1 || lev[lca[a][i]]<lev[b]) continue;
            a=lca[a][i];
        }
        if(a==b) return a;
        for(ll i=Log-1;i>=0;i--)
            if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
                a=lca[a][i],b=lca[b][i];
        return lca[a][0];
    }

    ll dfs(ll v, vector<vector<ll>> const& adj) {
        ll size = 1;
        ll max_c_size = 0;
        for (ll c : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v, depth[c] = depth[v] + 1;
                ll c_size = dfs(c, adj);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[v] = c;
            }
        }
        return size;
    }

    void decompose(ll v, ll h, vector<vector<ll>> const& adj, vector<ll> &sa) {
        head[v] = h, pos[v] = cur_pos;
        st.update(cur_pos++,val[v]);
        if (heavy[v] != -1)
            decompose(heavy[v], h, adj, sa);
        for (ll c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c, adj, sa);
        }
    }

    void merge(ll &res, ll ex){
        res = res + ex;
    }

    ll lcaquery(ll a, ll b) {
        ll res = 0;
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            res+= st.query(pos[head[b]], pos[b]).val;
        }
        if (depth[a] > depth[b])
            swap(a, b);
        res+= st.query(pos[a], pos[b]).val;
        return res;
    }

    void lcaupdate(ll a, ll b, ll val) {
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            st.update(pos[head[b]], pos[b], val);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        st.update(pos[a], pos[b], val);
    }

    ll query(ll u, ll v){
        ll l = getlca(u,v);
        return lcaquery(l,u) + lcaquery(l,v) - lcaquery(l,l);
    }

    void update(ll u, ll v, ll val){
        ll l = getlca(u,v);
        lcaupdate(l,u,val); lcaupdate(l,v,val); lcaupdate(l,l,val);
    }
};

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();

    ll n,q;
    cin>>n>>q;
    vector<ll> val(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v; u--,v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(ll i=0;i<n;i++)
        cin>>val[i];
    hld h(a,val);
    while(q--){
        ll t,u,v;
        cin>>t>>u>>v; u--,v--;
        if(t==1){
            ll va; cin>>va;
            h.update(u,v,va);
        }
        else
            cout<<h.query(u,v)<<"\n";
    }


 
    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}
/*
8 7
1 2
2 3
3 4
2 5
1 6
6 7
7 8
1 5 6 7 8 9 1 10
2 7 5
1 7 7 1
2 7 5
1 5 5 1
2 7 5
1 2 3 26
2 7 5
o/p:
24
24
17
38
*/
