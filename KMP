To find frequency of an array in another array in O(n)

void clps(vector<ll> a){
    ll i=1,j=0;
    lps[0]=0;
    while(i<a.size()){
        if(a[i]==a[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else{
                lps[i]=j;
                i++;
            }
        }
    }
}

int main(){
		...
		...
		...
		while(i<m){
            if(b1[i]==a1[j])
                i++,j++;
            else if(i<m-1 && b1[i]!=a1[j]){
                if(j!=0)
                    j=lps[j-1];
                else
                    i=i+1;
            }
            if(j==n-1){
                j=lps[j-1];
                ans++;
            }
        }
}
