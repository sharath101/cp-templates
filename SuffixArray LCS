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
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin());
const ll mod=1e9+7;

vector<int> sa, lcp;

void rsort(vector<int> &p, vector<int> &c){
    int n=p.size();
    vector<int> cnt(n);
    for(auto x: c) cnt[x]++;
    vector<int> p_new(n), pos(n, 0);
    for(int i=1;i<n;i++)
        pos[i]=pos[i-1]+cnt[i-1];
    for(auto x: p){
        int i=c[x];
        p_new[pos[i]]=x;
        pos[i]++;
    }
    p=p_new;
}

void buildsa(string &s){
    s+="$";
    int n=s.size();
    vector<pair<char,int>> a(n);
    for(int i=0;i<n;i++) a[i]={s[i],i};
    sort(a.begin(),a.end());

    vector<int> p(n), c(n);
    for(int i=0;i<n;i++) p[i]=a[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;i++){
        if(a[i].first==a[i-1].first)
            c[p[i]]=c[p[i-1]];
        else
            c[p[i]]=c[p[i-1]]+1;
    }
    int k=0;
    while((1<<k) < n){
        for(int i=0;i<n;i++)
            p[i]=(p[i]-(1<<k)+n)%n;
        rsort(p,c);

        vector<int> c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++){
            pair<int, int> prev = {c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int, int> now = {c[p[i]],c[(p[i]+(1<<k))%n]};
            if(now==prev)
                c_new[p[i]]=c_new[p[i-1]];
            else
                c_new[p[i]]=c_new[p[i-1]]+1;
        }
        c=c_new;
        k++;
    }
    sa=p;

    lcp.assign(n,0);
    k=0;
    for(int i=0;i<n-1;i++){
        int pi=c[i];
        int j=p[pi-1];
        while(s[i+k]==s[j+k]) k++;
        lcp[pi]=k;
        k=max(0,k-1);
    }
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();


    string a, b;
    cin>>a>>b;
    ll na=a.size(), nb=b.size();
    string s=a+'&'+b;           //use character < '$'
    ll n=s.size();
    buildsa(s);
    s+=s;
    ll ans=0, st=0, x, y;
    for(int i=1;i<sa.size();i++){
        if(((sa[i-1]<na&&sa[i]>na)||(sa[i-1]>na&&sa[i]<na)) && lcp[i]>ans){
            ans=lcp[i];
            st=sa[i];
        }
    }
    cout<<s.substr(st, ans);




    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
