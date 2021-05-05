struct BIT // range add and point query
{
    vector<ll> bit;
    ll n;
    BIT(ll n1) 
    {
        n = n1;
        bit.assign(n,0);
    }
    ll sum(ll r) 
    {
        ll ret = 0;
        for(; r >= 0; r = (r&(r+1))-1)
            ret += bit[r];
        return ret;
    }
    void add(ll idx, ll d) 
    {
        for(; idx < n; idx = idx | (idx+1))
            bit[idx] += d;
    }
    void upd(ll l,ll r,ll val)
    {
        add(l,val);
        add(r+1,-val);
    }
    ll val(ll l) 
    {
        return sum(l);
    }
};  
