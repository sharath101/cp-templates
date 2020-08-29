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
const int mod=1e9+7;

struct state {
    int len, link;
    ll cnt=0;
    map<char, int> next;
};

const int MAXLEN = 3e5+1;
state st[MAXLEN * 2];

struct SuffixAutomaton{
    int sz=0, last=0;
    vector<pair<ll,ll>> order;
    
    SuffixAutomaton(string s) {
        for(int i=0;i<sz;i++)
            st[i].next.clear();
        st[0].len = 0;
        st[0].link = -1;
        sz=1;
        last = 0;
        for(ll i=0;i<s.size();i++)
            sa_extend(s[i]);
    }
    void sa_extend(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].cnt =  1;
        order.pb({st[cur].len,cur});
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                order.pb({st[clone].len,clone});
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void setcnt(){
        sort(order.begin(),order.end(), greater<pair<ll,ll>>());
        for(auto &p: order)
            st[st[p.second].link].cnt+=st[p.second].cnt;
    }
};

/*-----------Distinct substrings--------*/
vector<ll> dp;
ll DistSub(ll u){
    if(dp[u]!=-1)
        return dp[u];
    ll ans=0;
    for(auto k: st[u].next)
        ans+=1+DistSub(k.second);
    return dp[u]=ans;
}
void CountDistinctSubstrings(ll sz){
    dp.assign(sz,-1);
    cout<<DistSub(0)<<"\n";
}
/*-----------Distinct substrings--------*/

/*-----------Lexicographically Kth substring--------*/
map<ll,string> lex;
ll k=0;
void lexk(ll u, string s){
    lex[k++]=s;
    for(auto p: st[u].next){
        lexk(p.second,s+p.first);
    }
}
void LexicographicallyKthSubstring(){
    lex.clear();
    lexk(0,"");
    for(ll i=1;i<k;i++) cout<<i<<": "<<lex[i]<<"\n";
}
/*-----------Lexicographically Kth substring--------*/

/*-----------Least Common Substring--------*/
void LeastCommonSubstring(string T) {
    int v = 0, l = 0, best = 0, bestpos = 0;
    for (int i = 0; i < T.size(); i++) {
        while (v && !st[v].next.count(T[i])) {
            v = st[v].link ;
            l = st[v].len ;
        }
        if (st[v].next.count(T[i])) {
            v = st [v].next[T[i]];
            l++;
        }
        if (l > best) {
            best = l;
            bestpos = i;
        }
    }
    string lcs = T.substr(bestpos - best + 1, best);
    cout<<lcs<<"\n";
}
/*-----------Least Common Substring--------*/

ll findstate(ll u, ll pos, string &t){
    if(pos==t.size())
        return u;
    if(!st[u].next.count(t[pos]))
        return -1;
    return findstate(st[u].next[t[pos]],pos+1,t);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    //cin>>t;
    while(t--){
        string s,t;
        cin>>s;
        cin>>t;
        //ll q; cin>>q;
        SuffixAutomaton sa(s);
        CountDistinctSubstrings(sa.sz);
        LexicographicallyKthSubstring();
        LeastCommonSubstring(t);
        // Find no. of occurence of substring
        sa.setcnt();
        ll state = findstate(0,0,t);
        if(state==-1) cout<<0<<"\n";
        else          cout<<st[state].cnt<<"\n";
        // Find no. of occurence of substring
    }
    
    return 0;
}

