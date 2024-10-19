#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=505,mod=998244353;
typedef long long ll;
ll dp[N][N];
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    
    
    
    ll ans=0;
    for(int d=1;d<=500;d++){
        vector<int> num(m+1);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(b[i]-a[j]>=d){
                    num[i]++;
                }
            }
        }


        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                if(j>=1){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(num[i]-(j-1)))%mod;
                }
            }
        }
        for(int i=1;i<=n;i++) ans=(ans+dp[m][i])%mod;

    }
    
    cout<<ans<<"\n";
    return 0;
}