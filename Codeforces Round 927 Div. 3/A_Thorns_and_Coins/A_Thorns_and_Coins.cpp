#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    a+='*';
    vector<int> dp(n+1);
    if(a[1]=='@') dp[1]=1;
    for(int i=2;i<n;i++)
    {
        if(a[i-1]!='*') dp[i]=max(dp[i],dp[i-1]);
        if(a[i-2]!='*') dp[i]=max(dp[i],dp[i-2]);
 
        if(a[i]=='@') dp[i]++;
        else if(a[i]=='*') dp[i]=0;
    }
    int j;
    for(j=0;j<n;j++)
    {
        if(a[j]=='*'&&a[j+1]=='*')
        {
            break;
        }
    }
    if(j!=n) cout<<dp[j-1]<<endl;
    else cout<<dp[n-1]<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}