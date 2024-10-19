#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
int main()
{
    read_fast
    string s;
    cin>>n>>s;
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int len=pi[i-1];
        while(len > 0 && s[i]!=s[len]) len=pi[len-1];
        if(s[i]==s[len]) pi[i]=len+1;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        int len=pi[i];
        while(len && pi[len-1]){
            len=pi[len-1];
        }
        pi[i]=len;
        if( len && 2 * len <=(i+1)){
            ans+=(i+1-len);
        }  
    }
    cout<<ans<<"\n";
    return 0;
}

