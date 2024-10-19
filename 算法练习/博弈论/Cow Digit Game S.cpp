#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e6;
int dp[N+5];
int main()
{
    read_fast
    for(int i=1;i<=9;i++) dp[i]=1;

    for(int i=10;i<=N;i++){
        int maxd=0,mind=1e9;
        int x=i;
        while(x){
            int g=x%10;
            if(g)
            maxd=max(maxd,g);
            if(g)
            mind=min(mind,g);
            x/=10;
        }
        dp[i]|=(dp[i-maxd]^1);
        dp[i]|=(dp[i-mind]^1);
    }

    
    int t,x;
    cin>>t;
    while(t--){
        cin>>x;
        if(dp[x]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}