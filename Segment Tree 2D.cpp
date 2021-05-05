//https://www.codechef.com/CENS2020/problems/CENS20A/

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

template<typename T>
struct SegmentTree
{
    int n;
    vector<T> st;
    SegmentTree(int n) : n(n) { st.assign(2 * n, T()); }
    T query(int p)
    {
        T res = 0;
        for (p += n; p; p >>= 1) res += st[p];
        return res % 2;
    }
    void update(int l, int r) // inclusive
    {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) st[l++] += 1;
            if (r & 1) st[--r] += 1;
        }
    }
};

template<typename T>
struct SegmentTree2D
{
    const int n;
    vector<T> st;
    SegmentTree2D(const vector<T>& a) : n(sz(a))
    {
        st.assign(2 * n, a[0]);
    }
    int query(int p, int q)
    {
        int res = 0;
        for (p += n; p; p >>= 1) res += st[p].query(q);
        return res % 2;
    }
    void update(int l, int r, int x, int y)
    {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) st[l++].update(x, y);
            if (r & 1) st[--r].update(x, y);
        }
    }
};

int main()
{ _
    int n, m; cin >> n >> m;
    vector a(m, 0);
    vector STs(n, SegmentTree<int>(m));
    SegmentTree2D st(STs);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            if (c != '0') st.update(i, i, j, j);
        }

    int q; cin >> q;
    while (q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --x2, --y1, --y2;
        st.update(x1, x2, y1, y2);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << st.query(i, j);
        cout << endl;
    }

    exit(0);
}
