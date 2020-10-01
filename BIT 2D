class BIT {
	vector <vector<ll>> bit;
	int n;
	public:
	BIT(int n) {
		this->n = n;
		bit.assign(n+1,vector<LL>(n+1,0));
	}
	void upd(int x, int y, LL delta) {
		int j = y;
		for (;x<=n;x+=(x&-x))
			for (y=j;y<=n;y+=(y&-y)) bit[x][y] += delta;
	}
	ll qq(int x, int y) {
		ll res=0;
		int j = y;
		for (;x;x-=(x&-x))
			for (y=j;y;y-=(y&-y)) res += bit[x][y];
		return res;
	}
};
