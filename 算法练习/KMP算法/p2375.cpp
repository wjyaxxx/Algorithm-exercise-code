
#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int p=1e9+7;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> pi(n);
    vector<int> num(n,1);
    
    for(int i=1;i<n;i++){
        int len=pi[i-1];
        while(len > 0 && (s[i]!=s[len])) len=pi[len-1];
        if(s[i]==s[len]) pi[i]=len+1;
        if(s[i]==s[len]) num[i]=num[len]+1;
        
    }
    long long ans=1;
   
    //这一步是精华中的精华
    for(int i=1,len=0;i<n;i++){
        while(len > 0 && (s[i]!=s[len])) len=pi[len-1];
        if(s[i]==s[len]) len++;
        while((len<<1)> (i+1)) len=pi[len-1];
        if(len) ans=(ans*(long long) (num[len-1]+1))%p;
    }
    cout<<ans<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}